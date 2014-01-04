///
/// @mainpage	AccelStepperTuner
///
/// @details	Tuner for the accel stepper library
/// @n
/// @n
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Benoît Clouet
/// @author		Benoît Clouet
/// @date		15/12/2013 23:05
/// @version	<#version#>
///
/// @copyright	(c) Benoît Clouet, 2013
/// @copyright	GNU General Public License
///
/// @see		ReadMe.txt for references
///


///
/// @file		AccelStepperTuner.ino
/// @brief		Main sketch
///
/// @details	<#details#>
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Benoît Clouet
/// @author		Benoît Clouet
/// @date		15/12/2013 23:05
/// @version	<#version#>
///
/// @copyright	(c) Benoît Clouet, 2013
/// @copyright	GNU General Public License
///
/// @see		ReadMe.txt for references
/// @n
///


// Core library for code-sense
#if defined(WIRING) // Wiring specific
#include "Wiring.h"
#elif defined(MAPLE_IDE) // Maple specific
#include "WProgram.h"
#elif defined(MPIDE) // chipKIT specific
#include "WProgram.h"
#elif defined(DIGISPARK) // Digispark specific
#include "Arduino.h"
#elif defined(ENERGIA) // LaunchPad MSP430, Stellaris and Tiva, Experimeter Board FR5739 specific
#include "Energia.h"
#elif defined(CORE_TEENSY) // Teensy specific
#include "WProgram.h"
#elif defined(ARDUINO) && (ARDUINO >= 100) // Arduino 1.0 and 1.5 specific
#include "Arduino.h"
#elif defined(ARDUINO) && (ARDUINO < 100) // Arduino 23 specific
#include "WProgram.h"
#else // error
#error Platform not defined
#endif

// Prototypes
#include "CmdMessenger.h"
#include "DueTimer.h"

#include "move.h"
#include "command.h"

// Add setup code
void setup() {
    initSteppers();
    initCommand();
}

// Add loop code
void loop() {
    
}
