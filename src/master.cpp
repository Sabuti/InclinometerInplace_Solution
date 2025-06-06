// exemplo básico
#include "master.h"

void master_init(void){
  Wire.begin(); // como mestre
}

void teste_master(){
  while (true){
    Wire.beginTransmission(0x08); // endereço do escravo
    Wire.write("Oi");             // envia dados
    Wire.endTransmission();       // finaliza transmissão
    delay(200);
  }
}