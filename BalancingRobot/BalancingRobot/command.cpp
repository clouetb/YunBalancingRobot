#include "command.h"

bool mustUseAverage = 0;

double angleKp = 1, angleKi = 1, angleKd = 0;

PID anglePID(&angleInput, &angleOutput, &angleSetpoint, angleKp, angleKi, angleKd, REVERSE);

MovingAvarageFilter movingAvarageFilter(10);

CmdMessenger cmdMessenger = CmdMessenger(Serial1);

enum
{
    kSetAnglePID = 1,
    kSetAngleOutputLimits = 2,
    kSetAcceleration = 3,
    kSetSpeed = 4,
    kSetAverage = 5,
    kRecalibrate = 9,
    kStatus = 0, // Command to report status
};

void initCommands()
{
    Serial.println("Init command...");
    Serial1.begin(57600);
    cmdMessenger.printLfCr();
    
    cmdMessenger.attach(onUnknownCommand);
    cmdMessenger.attach(kSetAnglePID, onSetAnglePID);
    cmdMessenger.attach(kSetAngleOutputLimits, onSetAngleOutputLimits);
    cmdMessenger.attach(kSetAcceleration, onSetAcceleration);
    cmdMessenger.attach(kSetSpeed, onSetSpeed);
    cmdMessenger.attach(kSetAverage, onSetAverage);
    cmdMessenger.attach(kRecalibrate, onRecalibrate);
    Timer3.getAvailable().attachInterrupt(processCommands).setPeriod(100000).start();
    cmdMessenger.sendCmd(kStatus, "System ready");
}

void onUnknownCommand()
{
    Serial.println("Receiving unknown command...");
    cmdMessenger.sendCmd(kStatus, "Command without attached callback");
}

void onSetAnglePID()
{
    Serial.println("Receiving Angle tuning command...");
    float Kp, Ki, Kd;
    readTuningArgs(&Kp, &Ki, &Kd);
    anglePID.SetTunings(Kp, Ki, Kd);
    cmdMessenger.sendCmd(kStatus, "Angle PID tuned");
}


void onSetAngleOutputLimits()
{
    Serial.println("Receiving Angle output limits command...");
    float lMin, lMax;
    readLimitsArgs(&lMin, &lMax);
    anglePID.SetOutputLimits(lMin, lMax);
    cmdMessenger.sendCmd(kStatus, "Angle output limits set");
}

void readTuningArgs(float *Kp, float *Ki, float *Kd)
{
    *Kp = cmdMessenger.readFloatArg();
    *Ki = cmdMessenger.readFloatArg();
    *Kd = cmdMessenger.readFloatArg();
}

void readLimitsArgs(float *lMin, float *lMax)
{
    *lMin = cmdMessenger.readFloatArg();
    *lMax = cmdMessenger.readFloatArg();
}

void onSetAcceleration()
{
    float accel = cmdMessenger.readFloatArg();
    leftStepper.setAcceleration(accel);
    rightStepper.setAcceleration(accel);
    cmdMessenger.sendCmd(kStatus, "Acceleration set");
}

void onSetSpeed()
{
    float speed = cmdMessenger.readFloatArg();
    leftStepper.setSpeed(speed);
    rightStepper.setSpeed(speed);
    cmdMessenger.sendCmd(kStatus, "Speed set");
}

void onSetAverage()
{
    bool _mustUseAverage = cmdMessenger.readBoolArg();
    mustUseAverage = _mustUseAverage;
    cmdMessenger.sendCmd(kStatus, "Use of average toggled");
}

void onRecalibrate()
{
    angleSetpoint = calibrateSensor();
    cmdMessenger.sendCmd(kStatus, "Calibration done");
}

void processCommands()
{
    cmdMessenger.feedinSerialData();
}