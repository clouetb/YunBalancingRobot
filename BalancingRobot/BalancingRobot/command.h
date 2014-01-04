#ifndef command_h
#define command_h

#include "PID_v1.h"
#include "MovingAvarageFilter.h"
#include "CmdMessenger.h"
#include "DueTimer.h"

#include "sense.h"
#include "move.h"

extern double angleKp, angleKi, angleKd;
extern bool mustUseAverage;
extern PID anglePID;
extern MovingAvarageFilter movingAvarageFilter;
extern CmdMessenger cmdMessenger;

void initCommands();

void onUnknownCommand();

void onSetAnglePID();

void onSetAngleOutputLimits();

void readTuningArgs(float *Kp, float *Ki, float *Kd);

void readLimitsArgs(float *lMin, float *lMax);

void onSetAcceleration();

void onSetSpeed();

void onSetAverage();

void onRecalibrate();

void processCommands();

#endif
