//! Generic controls for motors

#ifndef _GENERIC_HG_
#define _GENERIC_HG_

#include <string>
#include <WPILib.h>
#include <Commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include <Drive/DifferentialDrive.h>

class Generic: public frc::Subsystem {
public:
	Generic();	//!< Class constructor
	~Generic(); //!< Class destructor

	/*! \fn setSpeed(int ID, double speed)
			\breif Set the raw speed of a motor
			\param ID The id of the motor to manipulate
			\param speed The speed to set the motor too
	*/
	void setSpeed(int ID, double speed);

private:
	can::WPI_TalonSRX* pMotor1;	//!< Pointer to a Talon
	can::WPI_TalonSRX* pMotor2;	//!< Pointer to a Talon

};

#endif
