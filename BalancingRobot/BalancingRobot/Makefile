#
# embedXcode
# ----------------------------------
# Embedded Computing on Xcode 4
#
# Copyright © Rei VILO, 2010-2013
# All rights reserved
# http://embedxcode.weebly.com
#
# Last update: Nov 18, 2013 release 114


# Parameters
# ----------------------------------
# Xcode takes BOARD_TAG and BOARD_PORT from the .xcconfig file
# For other IDEs than Xcode,

# BOARD_TAG is required
# If not defined, error BOARD_TAG not defined
#
#BOARD_TAG  = mega2560

# BOARD_PORT is optional
# If not defined, BOARD_PORT = /dev/tty.usb* (default)
#
#BOARD_PORT = /dev/tty.usbmodem*

# Xcode takes SKETCHBOOK_DIR from preferences.txt 
# If not defined, each IDE has its own SKETCHBOOK_DIR (default)
# To share the same SKETCHBOOK_DIR along all IDEs, define
# 
#SKETCHBOOK_DIR =

# SERIAL_BAUDRATE for the serial console, 9600 by default
# Uncomment and specify another speed
#
#SERIAL_BAUDRATE = 19200


# Libraries
# ----------------------------------
# Declare application Arduino/chipKIT/Digispark/Energia/Maple/Teensy/Wiring 
# and users libraries used 
# Short-listing libraries speeds-up building
# Typing = 0 takes none
# Otherwise, leaving empty considers all (default)

# List Arduino/chipKIT/Energia/Maple/Teensy/Wiring libraries here 
#
# ARDUINO = EEPROM SoftwareSerial SPI Wire SPI Wire Esplora 
#	Ethernet Firmata GSM LiquidCrystal SD Servo Stepper WiFi 
#
APP_LIBS_LIST = Wire

# List users libraries here 
#
# USER = AccelStepper Adafruit_Motor_Shield ADXL345 AFMotor 
#	CmdMessenger DueTimer FIR FlexiTimer2 HMC5883L I2Cdev IRremote 
#	Kalman MovingAvarageFilter MPU6050 PID_AutoTune_v0 PID_v1 
#	RobotMotor Streaming Timer 
#
USER_LIBS_LIST = MovingAvarageFilter AccelStepper CmdMessenger DueTimer I2Cdev PID_v1 MPU6050DMP

# List core, application and user libraries to be excluded
# For example, WiFi may crash on Arduino 1.0.2
# For example, Esplora may crash on Arduino 1.0.3
# For example, Firmata may crash on Teensy 3.0
# For example, OneWire may crash on MPIDE 0023
# For example, HardwareSerial may conflict with MarlinSerial
#
EXCLUDE_LIBS = Firmata WiFi Esplora OneWire Robot_Control Robot_Control/utility Robot_Motor

# Manage path with space in the name
#
CURRENT_DIR   := $(shell pwd)
CURRENT_DIR   := $(shell echo '$(CURRENT_DIR)' | sed 's/ /\\\ /g')

# C-compliant project name
#
PROJECT_NAME_AS_IDENTIFIER = BalancingRobot

MAKEFILE_PATH  = $(CURRENT_DIR)/Makefiles
UTILITIES_PATH = $(CURRENT_DIR)/Utilities

include $(MAKEFILE_PATH)/Step1.mk

