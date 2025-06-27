#ifndef PINS_H_
#define PINS_H_

#include <Arduino.h>

#define LED_POWER_ON        2   
#define LED_WIFI_CONN       15   
#define RX_PIN              16   
#define TX_PIN              17   
#define RS485_DE_RE         33   // Pino para controle do driver RS485 (DE/RE)

void pins_init();

#endif