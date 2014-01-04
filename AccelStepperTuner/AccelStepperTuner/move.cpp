//
//  move.cpp
//  AccelStepperTuner
//
//  Created by Benoît Clouet on 15/12/2013.
//  Copyright (c) 2013 Benoît Clouet. All rights reserved.
//

#include "move.h"

int motorSpeed = 19200;
int motorMaxSpeed = 19200;
int motorAccel = 80000; //steps/second/second to accelerate

/*
const int leftDirPin = 3;
const int leftStepperPin = 2;

const int rightDirPin = 7;
const int rightStepperPin = 6;

//set up the accelStepper intances
AccelStepper leftStepper(AccelStepper::DRIVER, leftStepperPin, leftDirPin);
AccelStepper rightStepper(AccelStepper::DRIVER, rightStepperPin, rightDirPin);
*/

AccelStepper leftStepper(AccelStepper::FULL4WIRE, 34, 35, 36, 37);
AccelStepper rightStepper(AccelStepper::FULL4WIRE, 30, 31, 32, 33);

void initSteppers()
{
    leftStepper.setSpeed(motorSpeed);
    rightStepper.setSpeed(motorSpeed);
    leftStepper.setAcceleration(motorAccel);
    rightStepper.setAcceleration(motorAccel);
    Timer3.getAvailable().attachInterrupt(processSteppers).setPeriod(10).start();
}

void processSteppers()
{
    leftStepper.runSpeed();
    rightStepper.runSpeed();
}

void moveTo(int desiredPosition)
{
    leftStepper.setCurrentPosition(0);
    rightStepper.setCurrentPosition(0);
    leftStepper.moveTo(desiredPosition);
    rightStepper.moveTo(desiredPosition);
}

void setSpeed(int desiredSpeed)
{
    leftStepper.setSpeed(desiredSpeed);
    rightStepper.setSpeed(desiredSpeed);
}

void setAcceleration(int desiredAcceleration)
{
    leftStepper.setAcceleration(desiredAcceleration);
    rightStepper.setAcceleration(desiredAcceleration);
}

void setMaxSpeed(int desiredMaxSpeed)
{
    leftStepper.setMaxSpeed(desiredMaxSpeed);
    rightStepper.setMaxSpeed(desiredMaxSpeed);
}

void stop()
{
    leftStepper.stop();
    rightStepper.stop();
}