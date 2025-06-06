#ifndef RS485_H_
#define RS485_H_

#include "pins.h"
#include "filters.h"
#include "app.h"
#include <SoftwareSerial.h>
#include <Wire.h>

#define RX 5
#define TX 4
extern SoftwareSerial mySerial;

void rs485_init();
void rs485_send_data(FILTER_MOVING_AVERAGE_PTR filterAvg);
bool rs485_recvCommand(RS485_CONTROL_PTR rs485Control);

#endif