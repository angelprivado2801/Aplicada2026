#include <SPI.h>

#define CS_PIN 5

void setup() {
  Serial.begin(115200);
  
  // Configuramos el pin CS manualmente
  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH); // HIGH significa "Esclavo en espera"
  
  // Inicializamos el bus VSPI (SCK=18, MISO=19, MOSI=23). 
  // Pasamos -1 al SS para controlarlo nosotros manualmente.
  SPI.begin(18, 19, 23, -1);
  
  Serial.println("=== [ESP32 MAESTRO] Iniciado ===");
  Serial.println("Enviando ráfagas de prueba...");
}

void loop() {
  // Buffers de 13 bytes (12 caracteres + el fin de línea \0)
  uint8_t tx_buf[13] = "Hola_Esclavo"; 
  uint8_t rx_buf[13] = {0};

  // 1. Configuramos la velocidad y modo de SPI (1 MHz, Modo 0)
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
  
  // 2. Bajamos la línea CS a LOW para "despertar" al esclavo
  digitalWrite(CS_PIN, LOW);
  delayMicroseconds(10); // Pequeña pausa para estabilizar
  
  // 3. Enviamos los 12 bytes de golpe (es más estable que enviar letra por letra)
  SPI.transferBytes(tx_buf, rx_buf, 12);

  // 4. Subimos la línea CS a HIGH para terminar la transmisión
  digitalWrite(CS_PIN, HIGH);
  
  SPI.endTransaction();

  // 5. Mostramos los resultados
  Serial.print("-> Maestro envió: "); Serial.println((char*)tx_buf);
  Serial.print("<- Maestro recibió: "); Serial.println((char*)rx_buf);
  Serial.println("------------------------");

  delay(2000); // Esperamos 2 segundos antes de repetir
}
