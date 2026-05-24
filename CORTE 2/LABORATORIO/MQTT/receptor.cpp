#include <WiFi.h>
#include <PubSubClient.h>

// Configuración de tu red Wi-Fi con acceso a internet
const char* ssid = "TU_RED_WIFI";
const char* password = "TU_CONTRASEÑA";

// Configuración del Broker MQTT público
const char* mqtt_broker = "broker.hivemq.com";
const int mqtt_port = 1883;

// DEBE ser exactamente el mismo tema que usa el Publicador
const char* tema_mqtt = "mi_laboratorio/esp32/datos";

WiFiClient espClient;
PubSubClient client(espClient);

// Función que se ejecuta automáticamente cuando llega un mensaje
void recepcionMensaje(char* topic, byte* payload, unsigned int length) {
  Serial.print("<- Nuevo mensaje en el tema [");
  Serial.print(topic);
  Serial.print("]: ");
  
  // Imprimir letra por letra el mensaje recibido
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

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

  // 2. Configurar el Broker MQTT y la función de recepción
  client.setServer(mqtt_broker, mqtt_port);
  client.setCallback(recepcionMensaje);
}

void reconectar() {
  while (!client.connected()) {
    Serial.print("Intentando conexión MQTT...");
    String clientId = "ESP32_Sub_" + String(random(0xffff), HEX);
    
    if (client.connect(clientId.c_str())) {
      Serial.println("¡Conectado al Broker!");
      // 3. ¡MUY IMPORTANTE! Suscribirse al tema después de conectar
      client.subscribe(tema_mqtt);
    } else {
      Serial.print("Falló, código de error: ");
      Serial.print(client.state());
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconectar();
  }
  // Esta función mantiene vivo el proceso para escuchar mensajes entrantes
  client.loop(); 
}
