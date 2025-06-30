#include <Arduino.h>
#include <ModbusRTUSlave.h>
#include <SoftwareSerial.h>

#define RX 2
#define TX 3
#define RTS 4

SoftwareSerial rs485Serial(RX, TX);
ModbusRTUSlave slave;

uint16_t registers[10] = {1234};  // registrador 0 vai conter 1234

void setup() {
  pinMode(RTS, OUTPUT);
  rs485Serial.begin(9600);

  slave.begin(1, 9600);  // ID 1, usa RTS para RE/DE

  slave.configureHoldingRegisters(registers, sizeof(registers) / sizeof(registers[0]));
}

void loop() {
}
