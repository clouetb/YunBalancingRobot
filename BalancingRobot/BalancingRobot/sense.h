#ifndef sense_h
#define sense_h

#include "Wire.h"
#include "I2CDev.h"
#include "MPU6050DMP.h"

extern MPU6050 mpu;
extern float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector
extern float roll;
extern uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
extern uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
extern uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
extern uint16_t fifoCount;     // count of all bytes currently in FIFO
extern uint8_t fifoBuffer[64]; // FIFO storage buffer
extern Quaternion q;           // [w, x, y, z]         quaternion container
extern VectorFloat gravity;    // [x, y, z]            gravity vector
extern double angleSetpoint, angleInput, angleOutput;

void initSensors();

float calibrateSensor();

void dmpDataReady();

void showRoll();

#endif
