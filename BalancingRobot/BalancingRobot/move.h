#ifndef move_h
#define move_h

#include "AccelStepper.h"
#include "DueTimer.h"

extern AccelStepper leftStepper;
extern AccelStepper rightStepper;

extern int leftDirPin;
extern int leftStepperPin;

extern int rightDirPin;
extern int rightStepperPin;

extern int motorSpeed;
extern int motorAccel;

void initMotors();

void step(int stepsLeft, int stepsRight);

void processSteppers();

#endif
