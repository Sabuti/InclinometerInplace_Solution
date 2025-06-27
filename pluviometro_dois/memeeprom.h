#ifndef MEMEEPROM_H
#define MEMEEPROM_H

#include <EEPROM.h>

#define MEMEEPROM_SIZE 512

#define MEMEEPROM_ID_ADDRESS 0
#define MEMEEPROM_INTERVAL_ADDRESS 10
#define MEMEEPROM_SSID_ADDRESS 16
#define MEMEEPROM_PASSWORD_ADDRESS 144


#define MEMEEPROM_BASE_ADDRESS_SIZE 2
#define MEMEEPROM_BASE_LEN_SIZE 1
#define MEMEEPROM_BASE_WROTE_CODE_1 0xFD
#define MEMEEPROM_BASE_WROTE_CODE_2 0xFE

void memeeprom_init();
void memeeprom_readString(int baseAddress, char* buffer);
bool memeeprom_writeString(int baseAddress, const char* stringToWrite);
bool memeeprom_writeByte(int baseAddress, uint8_t id);
bool memeeprom_isWritten(int baseAddress);
uint8_t memeeprom_readByte(int baseAddress);
bool memeeprom_write2Bytes(int baseAddress, uint16_t bytes);
uint16_t memeeprom_read2Bytes(int baseAddress);



#endif