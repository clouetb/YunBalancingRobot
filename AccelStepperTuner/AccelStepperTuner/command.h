//
//  command.h
//  AccelStepperTuner
//
//  Created by Benoît Clouet on 17/12/2013.
//  Copyright (c) 2013 Benoît Clouet. All rights reserved.
//

#ifndef AccelStepperTuner_command_h
#define AccelStepperTuner_command_h

#include "CmdMessenger.h"
#include "DueTimer.h"

#include "move.h"

enum
{
    kMoveTo = 1,
    kSetSpeed = 2,
    kSetMaxSpeed = 3,
    kSetAcceleration = 4,
    kStop = 5,
    kStatus = 0, // Command to report status
};

void initCommand();
void processCommands();

void onUnknownCommand();

void onMoveTo();
void onSetSpeed();
void onSetAcceleration();
void onSetMaxSpeed();
void onStop();

#endif
