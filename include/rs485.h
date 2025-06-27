#ifndef RS485_H_
#define RS485_H_

#include "pins.h"
#include "filters.h"
#include "app.h"
#include <Wire.h>
#ifdef ESP32
    #include <HardwareSerial.h>
    extern HardwareSerial mySerial;
#else
    #include <SoftwareSerial.h>
    extern SoftwareSerial mySerial;
#endif


void rs485_init();
void rs485_send_data(FILTER_MOVING_AVERAGE_PTR filterAvg);
bool rs485_recvCommand(RS485_CONTROL_PTR rs485Control);

#endif