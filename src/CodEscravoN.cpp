#include <ModbusRTU.h>
#include <SoftwareSerial.h>

#define RS485_RX    12  // PB4
#define RS485_TX    11  // PB3  
#define RS485_DE_RE 13  // PB5
#define SLAVE_ID  0x01  // alterar para cada escravo

// Instâncias
SoftwareSerial rs485Serial(RS485_RX, RS485_TX);
ModbusRTU modbus;

uint16_t valor = 0; // alterar para pegar do sensor futuramente

void setup() {
  rs485Serial.begin(9600); // é obrigado a usar o 8N1

  pinMode(RS485_DE_RE, OUTPUT);
  digitalWrite(RS485_DE_RE, LOW);  // Modo recepção

  modbus.begin(&rs485Serial, RS485_DE_RE);
  modbus.slave(SLAVE_ID); // inicia como escravo

  modbus.addHreg(0, 0);   // inicia registrador na pos 0, com valor 0
}

void loop() {
  modbus.Hreg(0, valor);  // Atualiza registrador
  modbus.task();
  delay(1000); // Atualiza valor a cada 1 segundo, talvez alterar
}
