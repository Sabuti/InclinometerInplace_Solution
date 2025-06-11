#ifndef MASTER_H_
#define MASTER_H_

#include <Wire.h>
#include <Arduino.h>
#include "ModbusRTUMaster.h"
#include "pins.h"
#include "rs485.h"

void master_init(void);
void teste_master(void);
void ping(uint8_t slave_id);
void req_status(uint8_t slave_id);

#endif