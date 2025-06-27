#ifndef MPU_H_
#define MPU_H_

#include <ModbusRTU.h>
#include "pins.h"

#define SLAVE_WHOAMI_ID 0x75                       // ID do dispositivo escravo
#define NUM_SENSOR_REGISTERS 16             // Quantidade de registradores a serem lidos

#define ADDRESS_DEVICE_ADDRESS 0x68
#define ADDRESS_ACCELXOUT_H 0x3B
#define ADDRESS_ACCELXOUT_L 0x3C
#define ADDRESS_ACCELYOUT_H 0x3D
#define ADDRESS_ACCELYOUT_L 0x3E
#define ADDRESS_ACCELZOUT_H 0x3F
#define ADDRESS_ACCELZOUT_L 0x40
#define ADDRESS_TEMPOUT_H 0x41
#define ADDRESS_TEMPOUT_L 0x42
#define ADDRESS_GYROXOUT_H 0x43
#define ADDRESS_GYROXOUT_L 0x44
#define ADDRESS_GYROYOUT_H 0x45
#define ADDRESS_GYROYOUT_L 0x46
#define ADDRESS_GYROZOUT_H 0x47
#define ADDRESS_GYROZOUT_L 0x48

typedef struct {
  uint16_t deviceName;
  uint16_t dataRate;
  uint16_t deviceAddress;
  uint16_t accelx;
  uint16_t accely;
  uint16_t accelz;
  uint16_t temp;
  uint16_t gyrox;
  uint16_t gyroy;
  uint16_t gyroz;
}MPU6050_DATA_T, *MPU6050_DATA_PTR;

extern MPU6050_DATA_T sensorMPU;

void mpu6050_init(void);
void mpu6050_processTasks(void);
bool mpu6050_readHoldingRegister(MPU6050_DATA_PTR sensorMPU);

#endif