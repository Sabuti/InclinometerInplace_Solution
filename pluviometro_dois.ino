#include "app.h"

//  esp_task_wdt_config_t wdtConfig = {
//         .timeout_ms = WDT_TIMEOUT * 1000,  // Tempo limite em milissegundos
//         .idle_core_mask = (1 << 0),        // Aplicado ao Core 0
//         .trigger_panic = true              // Reinicia o sistema se disparado
//     };

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pins_init();
  configManager_init();
  espwifi_init();
  mpu6050_init();
  app_init();
  pinMode(LED_POWER_ON, OUTPUT);
  digitalWrite(LED_POWER_ON, LOW);  // LED indicativo de código rodando
}

void loop() {

  app_poll();
  configManager_poll();
  // esp_task_wdt_reset();
  //firmwareUpdate_check();
}
