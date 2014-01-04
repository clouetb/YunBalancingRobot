#include "move.h"

int leftDirPin = 3;
int leftStepperPin = 2;

int rightDirPin = 7;
int rightStepperPin = 6;

int motorSpeed = 19200; //maximum steps per second (about 3rps / at 16 microsteps)
int motorAccel = 80000; //steps/second/second to accelerate

AccelStepper leftStepper(AccelStepper::DRIVER, leftStepperPin, leftDirPin);
AccelStepper rightStepper(AccelStepper::DRIVER, rightStepperPin, rightDirPin);

void initMotors()
{
    leftStepper.setMaxSpeed(motorSpeed);
    rightStepper.setMaxSpeed(motorSpeed);
    
    leftStepper.setSpeed(motorSpeed);
    rightStepper.setSpeed(motorSpeed);
    
    leftStepper.setAcceleration(motorAccel);
    rightStepper.setAcceleration(motorAccel);
    Timer3.getAvailable().attachInterrupt(processSteppers).setPeriod(10).start();
}

void step(int stepsLeft, int stepsRight)
{
    leftStepper.moveTo(stepsLeft+leftStepper.currentPosition());
    rightStepper.moveTo(stepsRight+rightStepper.currentPosition());
}

void processSteppers()
{
    leftStepper.run();
    rightStepper.run();
}