#ifndef PINS_H_
#define PINS_H_

#include <Wire.h>

//#define SCL     37 // deu conflito de nome
//#define SDA     21 // deu conflito de nome
#define TX   PB3
#define RX   PB4
#define ADO  38

const int8_t RE = PB5; // RE = DE, igual ao do esquematico

void pins_init(void);

#endif