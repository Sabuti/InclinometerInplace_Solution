#ifndef SLAVE_H_
#define SLAVE_H_

#include <Wire.h>
#include <Arduino.h>
#include "rs485.h"

void slave_init(void);
void enviarDados(int qtd);

#endif