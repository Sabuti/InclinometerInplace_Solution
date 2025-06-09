#ifndef MASTER_H_
#include <Wire.h>
#include <Arduino.h>
#include "ModbusRTUMaster.h"

const int8_t dePin = A6; // soh seguindo o exemplo, "driver enable pin"

void master_init(void);
void teste_master(void);

#endif