#include "master.h"

void master_init(void){
  //Serial.begin(38400, SERIAL_8E1); // baudrate / 8 bits, paridade par, 1 stop bit
  //ModbusRTUMaster modbus(Serial, dePin); // comunicação / driver pin
  //modbus.begin(&Serial); // qual serial usada

  //uint16_t inputRegisters[8]; // buffer pra colocar os dados
}

void teste_master(){
  while (true){
    //modbus.readInputRegisters(1, 0, inputRegisters, 8) //id escravo, endereço do 1o input register pra ler, buffer, quant
  }
}