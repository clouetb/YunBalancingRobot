/// 
/// @mainpage	BalancingRobot 
///
/// @details	Balancing robot project
/// @n 		
/// @n 
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
/// 
/// @author		Benoît Clouet
/// @author		Benoît Clouet
///
/// @date		23/12/2013 00:12
/// @version	<#version#>
/// 
/// @copyright	(c) Benoît Clouet, 2013
/// @copyright	GNU General Public License
///
/// @see		ReadMe.txt for references
///


///
/// @file		BalancingRobot.ino
/// @brief		Main sketch
///
/// @details	<#details#>
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
/// 
/// @author		Benoît Clouet
/// @author		Benoît Clouet
/// @date		23/12/2013 00:12
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

// Include application, user and local libraries
#include "sense.h"
#include "move.h"
#include "command.h"

// Prototypes


// Define variables and constants


// Add setup code 
void setup() 
{

}

// Add loop code 
void loop() 
{

}
