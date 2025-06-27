#include "memeeprom.h"

// Inicializa a EEPROM com o tamanho necessário (deve ser chamada no setup)
void memeeprom_init() {
  EEPROM.begin(MEMEEPROM_SIZE);  // Aloca 512 bytes (ajuste conforme necessidade)
  if (!memeeprom_isWritten(MEMEEPROM_ID_ADDRESS)) {
    memeeprom_writeByte(MEMEEPROM_ID_ADDRESS, 1);
    Serial.println("ID: EEPROM vazia, escrevendo ID = 1");
  }
  if (!memeeprom_isWritten(MEMEEPROM_SSID_ADDRESS)) {
    memeeprom_writeString(MEMEEPROM_SSID_ADDRESS, "");
    Serial.println("SSID: EEPROM vazia, escrevendo SSID = ");
  }
  if (!memeeprom_isWritten(MEMEEPROM_PASSWORD_ADDRESS)) {
    memeeprom_writeString(MEMEEPROM_PASSWORD_ADDRESS, "");
    Serial.println("Password: EEPROM vazia, escrevendo Password = ");
  }
  if (!memeeprom_isWritten(MEMEEPROM_INTERVAL_ADDRESS)) {
    memeeprom_write2Bytes(MEMEEPROM_INTERVAL_ADDRESS, 10);
    Serial.println("Interval: EEPROM vazia, escrevendo Interval = 10");
  }
  Serial.println("Carregou os valores da EEPROM");
}

// Função para escrever string na EEPROM
bool memeeprom_writeString(int baseAddress, const char* stringToWrite) {
  if (strlen(stringToWrite) > 128) {
    return false;  // String muito longa
  }
  EEPROM.write(baseAddress, MEMEEPROM_BASE_WROTE_CODE_1);
  EEPROM.write(baseAddress + 1, MEMEEPROM_BASE_WROTE_CODE_2);

  // Escreve o comprimento da string primeiro
  uint8_t len = strlen(stringToWrite);
  EEPROM.write(baseAddress + MEMEEPROM_BASE_ADDRESS_SIZE, len);

  // Escreve a string
  for (int i = 0; i < len; i++) {
    EEPROM.write(baseAddress + MEMEEPROM_BASE_LEN_SIZE + MEMEEPROM_BASE_ADDRESS_SIZE + i, stringToWrite[i]);
  }

  return EEPROM.commit();  // Salva as alterações na EEPROM
}

// Função para ler string da EEPROM
void memeeprom_readString(int baseAddress, char* buffer) {
  uint8_t len = EEPROM.read(baseAddress + MEMEEPROM_BASE_ADDRESS_SIZE);

  for (int i = 0; i < len; i++) {
    buffer[i] = EEPROM.read(baseAddress + MEMEEPROM_BASE_ADDRESS_SIZE + MEMEEPROM_BASE_LEN_SIZE + i);
  }

  // buffer[len] = '\0';  // Adiciona terminador nulo
}

// Função para verificar se a string foi preenchida
bool memeeprom_isWritten(int baseAddress) {
  if (EEPROM.read(baseAddress) == MEMEEPROM_BASE_WROTE_CODE_1 && EEPROM.read(baseAddress + 1) == MEMEEPROM_BASE_WROTE_CODE_2)
    return true;
  else
    return false;
}

// Função para escrever um byte ID na EEPROM
bool memeeprom_writeByte(int baseAddress, uint8_t id) {
  EEPROM.write(baseAddress, MEMEEPROM_BASE_WROTE_CODE_1);
  EEPROM.write(baseAddress + 1, MEMEEPROM_BASE_WROTE_CODE_2);
  EEPROM.write(baseAddress + MEMEEPROM_BASE_ADDRESS_SIZE, id);
  return EEPROM.commit();
}

// Função para escrever um byte ID na EEPROM
bool memeeprom_write2Bytes(int baseAddress, uint16_t bytes) {
  EEPROM.write(baseAddress, MEMEEPROM_BASE_WROTE_CODE_1);
  EEPROM.write(baseAddress + 1, MEMEEPROM_BASE_WROTE_CODE_2);
  EEPROM.write(baseAddress + MEMEEPROM_BASE_ADDRESS_SIZE, bytes & 0x00FF);
  EEPROM.write(baseAddress + MEMEEPROM_BASE_ADDRESS_SIZE + 1, (bytes & 0xFF00) >> 8);

  return EEPROM.commit();
}

// Função para ler um byte ID da EEPROM
uint8_t memeeprom_readByte(int baseAddress) {
  return EEPROM.read(baseAddress + MEMEEPROM_BASE_ADDRESS_SIZE);
}

// Função para ler um byte ID da EEPROM
uint16_t memeeprom_read2Bytes(int baseAddress) {
  return (EEPROM.read(baseAddress + MEMEEPROM_BASE_ADDRESS_SIZE) | (EEPROM.read(baseAddress + MEMEEPROM_BASE_ADDRESS_SIZE + 1) << 8));
}