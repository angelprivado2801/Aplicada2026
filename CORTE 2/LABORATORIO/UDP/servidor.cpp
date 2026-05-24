#include <WiFi.h>
#include <WiFiUdp.h>

// Configuración de la red Wi-Fi que va a crear este ESP32
const char* ssid = "ESP32_Red_Directa";
const char* password = "password123"; // Mínimo 8 caracteres

// Puerto por donde escucharemos los mensajes UDP
const int puertoUDP = 4210;
WiFiUDP udp;

// Buffer para guardar el mensaje entrante
char bufferRecepcion[255];

void setup() {
  Serial.begin(115200);
  delay(1000);

  // 1. Configurar este ESP32 como Punto de Acceso (AP)
  Serial.println("\n=== [ESP32 SERVIDOR UDP] ===");
  Serial.print("Creando red Wi-Fi: ");
  Serial.println(ssid);
  
  WiFi.softAP(ssid, password);

  // 2. Mostrar la IP del Servidor (Por defecto en ESP32 siempre es 192.168.4.1)
  Serial.print("IP del Servidor (AP): ");
  Serial.println(WiFi.softAPIP());

  // 3. Iniciar la escucha UDP
  udp.begin(puertoUDP);
  Serial.printf("Escuchando mensajes UDP en el puerto %d\n", puertoUDP);
}

void loop() {
  // Revisar si llegó un paquete UDP
  int tamañoPaquete = udp.parsePacket();
  
  if (tamañoPaquete) {
    // Leer los datos y guardarlos en el buffer
    int len = udp.read(bufferRecepcion, 255);
    if (len > 0) {
      bufferRecepcion[len] = 0; // Terminar la cadena de texto correctamente
    }

    // Mostrar el mensaje y la IP de quién lo envió
    Serial.print("<- Recibido de ");
    Serial.print(udp.remoteIP());
    Serial.print(": ");
    Serial.println(bufferRecepcion);

    // Opcional: Enviar un acuse de recibo de vuelta al Cliente
    udp.beginPacket(udp.remoteIP(), udp.remotePort());
    udp.print("Mensaje recibido por el Servidor!");
    udp.endPacket();
  }
}
