#include <WiFi.h>
#include <WiFiUdp.h>

// Credenciales de la red que creó el Servidor
const char* ssid = "ESP32_Red_Directa";
const char* password = "password123";

// Datos de destino (IP del Servidor y el puerto acordado)
const char* ipServidor = "192.168.4.1";
const int puertoUDP = 4210;

WiFiUDP udp;
char bufferRespuesta[255];

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("\n=== [ESP32 CLIENTE UDP] ===");
  Serial.print("Conectando a la red: ");
  Serial.println(ssid);

  // 1. Conectar a la red Wi-Fi del Servidor
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\n¡Conectado exitosamente!");
  Serial.print("Mi IP asignada: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // 2. Crear el mensaje que vamos a enviar
  String mensaje = "Hola Servidor, aquí el Cliente. Tiempo: " + String(millis());

  // 3. Empaquetar y enviar por UDP
  udp.beginPacket(ipServidor, puertoUDP);
  udp.print(mensaje);
  udp.endPacket();

  Serial.print("-> Enviado: ");
  Serial.println(mensaje);

  // 4. Escuchar brevemente por si el Servidor nos responde
  int tamañoRespuesta = udp.parsePacket();
  if (tamañoRespuesta) {
    int len = udp.read(bufferRespuesta, 255);
    if (len > 0) {
      bufferRespuesta[len] = 0; 
    }
    Serial.print("   Respuesta del Servidor: ");
    Serial.println(bufferRespuesta);
  }

  // Esperar 2 segundos antes de mandar el siguiente paquete
  delay(2000);
}
