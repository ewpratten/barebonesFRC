//! The robot's IO management class.
//! Used to get things like the xbox controllers

#ifndef _OI_HG_
#define _OI_HG_

#include <WPILib.h>
#include <XboxController.h>

class OI {
public:
	OI();		//!< Class constructor
	~OI();	//!< Class destructor
	frc::XboxController* GetJoystickDrive(void);		//!< Function to return pJoystickDrive
	frc::XboxController* GetJoystickOperator(void);	//!< Function to return pJoystickOperator

private:
	frc::XboxController* pJoystickDrive;		//!< Pointer to store the driver's xbox controller info
	frc::XboxController* pJoystickOperator;	//!< Pointer to store the operator's xbox controller info
};

#endif
