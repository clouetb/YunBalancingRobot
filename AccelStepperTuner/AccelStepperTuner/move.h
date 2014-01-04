//
//  move.h
//  AccelStepperTuner
//
//  Created by Benoît Clouet on 15/12/2013.
//  Copyright (c) 2013 Benoît Clouet. All rights reserved.
//

#ifndef AccelStepperTuner_move_h
#define AccelStepperTuner_move_h

#include "AccelStepper.h"
#include "DueTimer.h"

extern int motorSpeed; //19200; //maximum steps per second (about 3rps / at 16 microsteps)
extern int motorAccel; //steps/second/second to accelerate
extern int motorMaxSpeed;

//set up the accelStepper intances
extern AccelStepper leftStepper;
extern AccelStepper rightStepper;

void initSteppers();

void processSteppers();

void moveTo(int desiredPosition);

void setSpeed(int desiredSpeed);

void setAcceleration(int desiredAcceleration);

void setMaxSpeed(int desiredMaxSpeed);

void stop();

#endif
