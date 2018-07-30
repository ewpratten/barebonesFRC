
//This file contains all of the configurations / settings for the robot

#ifndef SRC_ROBOTCFG_HPP_
#define SRC_ROBOTCFG_HPP_

// Config
#define JoyDrive true
#define IS_QBERT true // change this to false if using the test bot
#define ProtoBrakeMode Brake // change "break" to "coast" to turn off breaking on the prototyping motors

#define Vision true
#define Camera_Server true

// Xbox Controller
#define XBOX_CONTROLLER_DRIVE_PORT 0 //Int
#define XBOX_CONTROLLER_OPERATOR_PORT 1 //Int
#define XBOX_DEADZONE_LEFT_JOY 0.1 //Double
#define XBOX_DEADZONE_RIGHT_JOY 0.1 //Double

#endif
