#include <Arduino.h>
#include "main.h"
#include "master.h"

void setup() {
  //pins_init();
  //adxl_init();
  //mpu_init();
  //app_init();
  rs485_init();
  //Serial.begin(115200);
  Serial.begin(9600);
}

void loop() {
  teste_master();
  //app_poll();
}