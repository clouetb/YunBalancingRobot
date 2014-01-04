//
//  command.cpp
//  AccelStepperTuner
//
//  Created by Benoît Clouet on 17/12/2013.
//  Copyright (c) 2013 Benoît Clouet. All rights reserved.
//

#include "command.h"

CmdMessenger cmdMessenger = CmdMessenger(Serial);

void initCommand()
{
    Serial.begin(115200);
    cmdMessenger.printLfCr();
    cmdMessenger.attach(onUnknownCommand);
    cmdMessenger.attach(kMoveTo, onMoveTo);
    cmdMessenger.attach(kSetSpeed, onSetSpeed);
    cmdMessenger.attach(kSetAcceleration, onSetAcceleration);
    cmdMessenger.attach(kSetMaxSpeed, onSetMaxSpeed);
    cmdMessenger.attach(kStop, onStop);
    Timer3.getAvailable().attachInterrupt(processCommands).setPeriod(10000).start();
    cmdMessenger.sendCmd(kStatus, "System ready");
}

void processCommands()
{
    cmdMessenger.feedinSerialData();
}

void onUnknownCommand()
{
    cmdMessenger.sendCmd(kStatus, "Command without attached callback");
}

void onMoveTo()
{
    int desiredPosition = cmdMessenger.readIntArg();
    moveTo(desiredPosition);
    cmdMessenger.sendCmd(kStatus, "Move requested");
}

void onSetSpeed()
{
    int desiredSpeed = cmdMessenger.readIntArg();
    setSpeed(desiredSpeed);
    cmdMessenger.sendCmd(kStatus, "Speed set");
}

void onSetAcceleration()
{
    int desiredAcceleration = cmdMessenger.readIntArg();
    setAcceleration(desiredAcceleration);
    cmdMessenger.sendCmd(kStatus, "Acceleration set");
}

void onSetMaxSpeed()
{
    int desiredMaxSpeed = cmdMessenger.readIntArg();
    setMaxSpeed(desiredMaxSpeed);
    cmdMessenger.sendCmd(kStatus, "Max speed set");
}

void onStop()
{
    stop();
    cmdMessenger.sendCmd(kStatus, "Motor stopped");
}
