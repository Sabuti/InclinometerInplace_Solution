#ifndef ESPWIFI_H_
#define ESPWIFI_H_

#include <Arduino.h>
#include <WiFi.h>
#include "mpu.h"
#include "pins.h"
#include "configManager.h"

void espwifi_init(void);
int8_t espwifi_getSignal();
bool espwifi_poll(void);
bool espwifi_sendData(MPU6050_DATA_PTR sensorMPU);
#endif