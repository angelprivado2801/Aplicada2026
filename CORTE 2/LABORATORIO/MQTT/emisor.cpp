#include <WiFi.h>
#include <PubSubClient.h>

// Configuración de tu red Wi-Fi con acceso a internet
const char* ssid = "TU_RED_WIFI";
const char* password = "TU_CONTRASEÑA";

// Configuración del Broker MQTT público
const char* mqtt_broker = "broker.hivemq.com";
const int mqtt_port = 1883;

// Tema (Topic) donde publicaremos. ¡Cámbialo por algo único para ti!
const char* tema_mqtt = "mi_laboratorio/esp32/datos";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  delay(1000);

  // 1. Conectar a Wi-Fi
  Serial.print("Conectando a Wi-Fi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi conectado.");

  // 2. Configurar el Broker MQTT
  client.setServer(mqtt_broker, mqtt_port);
}

void reconectar() {
  // Bucle hasta que estemos conectados al broker
  while (!client.connected()) {
    Serial.print("Intentando conexión MQTT...");
    // Creamos un ID de cliente aleatorio
    String clientId = "ESP32_Pub_" + String(random(0xffff), HEX);
    
    if (client.connect(clientId.c_str())) {
      Serial.println("¡Conectado al Broker!");
    } else {
      Serial.print("Falló, código de error: ");
      Serial.print(client.state());
      Serial.println(" Intentando de nuevo en 5 segundos...");
      delay(5000);
    }
  }
}

void loop() {
  // Asegurar que la conexión MQTT se mantiene viva
  if (!client.connected()) {
    reconectar();
  }
  client.loop();

  // Crear el mensaje a enviar
  String mensaje = "Hola desde ESP32 Publicador. Tick: " + String(millis());

  // Publicar el mensaje en el tema
  Serial.print("Publicando mensaje: ");
  Serial.println(mensaje);
  client.publish(tema_mqtt, mensaje.c_str());

  delay(2000); // Esperar 2 segundos antes de enviar el siguiente
}
