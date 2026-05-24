#include <driver/spi_slave.h>

#define MOSI_PIN 23
#define MISO_PIN 19
#define SCLK_PIN 18
#define CS_PIN 5

// Los buffers deben ser globales para que no colapse la memoria RAM
char tx_buf[13] = "Hola_Maestro"; 
char rx_buf[13] = {0};

void setup() {
  Serial.begin(115200);
  delay(1000); // Pausa para que abras el monitor serial
  
  // 1. Configuración de la interfaz (limpiamos memoria con memset por seguridad)
  spi_slave_interface_config_t slvcfg;
  memset(&slvcfg, 0, sizeof(slvcfg)); 
  slvcfg.spics_io_num = CS_PIN;             
  slvcfg.queue_size = 3;
  slvcfg.mode = 0; // Modo 0, igual que el maestro

  // 2. Configuración de los pines físicos del bus
  spi_bus_config_t buscfg;
  memset(&buscfg, 0, sizeof(buscfg));
  buscfg.mosi_io_num = MOSI_PIN;
  buscfg.miso_io_num = MISO_PIN;
  buscfg.sclk_io_num = SCLK_PIN;
  
  // Desactivamos explícitamente pines avanzados que no usamos
  buscfg.quadwp_io_num = -1;
  buscfg.quadhd_io_num = -1;
  buscfg.data4_io_num = -1;
  buscfg.data5_io_num = -1;
  buscfg.data6_io_num = -1;
  buscfg.data7_io_num = -1;
  
  buscfg.max_transfer_sz = 4096;

  // 3. Inicializamos el SPI esclavo SIN DMA (pasando un 0 al final)
  esp_err_t ret = spi_slave_initialize(VSPI_HOST, &buscfg, &slvcfg, 0);
  
  if (ret == ESP_OK) {
    Serial.println("=== [ESP32 ESCLAVO] Iniciado ===");
    Serial.println("Esperando mensajes del Maestro...");
  } else {
    Serial.printf("Error al iniciar: Código %d\n", ret);
  }
}

void loop() {
  // Limpiamos el buffer de recepción para no tener "basura" de mensajes anteriores
  memset(rx_buf, 0, sizeof(rx_buf));

  // Preparamos el paquete de datos
  spi_slave_transaction_t trans;
  memset(&trans, 0, sizeof(trans));
  trans.length = 12 * 8; // 96 bits exactos (12 letras * 8 bits)
  trans.tx_buffer = tx_buf;
  trans.rx_buffer = rx_buf;

  // El esclavo se queda "pausado" en esta línea hasta que el Maestro jale el pin CS
  esp_err_t ret = spi_slave_transmit(VSPI_HOST, &trans, portMAX_DELAY);
  
  if (ret == ESP_OK) {
    Serial.print("<- Esclavo recibió: "); Serial.println(rx_buf);
  }
}
