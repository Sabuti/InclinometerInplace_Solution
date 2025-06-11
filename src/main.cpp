#include <Arduino.h>
#include "main.h"

void setup() {
  //pins_init();
  //adxl_init();
  //mpu_init();
  //app_init();
  rs485_init();
}

void loop() {
  teste_master();
  //app_poll();
}