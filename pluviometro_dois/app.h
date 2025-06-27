#ifndef APP_H_
#define APP_H_

#include <Arduino.h>
#include "espwifi.h"
#include "mpu.h"
#include "esp_task_wdt.h"
#include "pins.h"
#include "firmwareUpdate.h"
#include "configManager.h"

#define FW_VERSION            1
#define ID                    1
#define WDT_TIMEOUT           30  // Tempo limite do watchdog (segundos)
#define TENTATIVAS_DE_CONEXAO 1
#define READ_SENSOR_TIMER_S   60*10 // 10 minutos


void app_init(void);
void app_poll(void);

#endif