//! Subsystem to control the elevator

#ifndef _ELEVATOR_HG_
#define _ELEVATOR_HG_

#include <WPILib.h>
#include <Commands/Subsystem.h>
#include <ctre/Phoenix.h>

//!< Create a class for our subsystem
class Elevator: public frc::Subsystem {
public:
	Elevator();	//!< Class constructor
	~Elevator(); //!< Class destructor
	
	void setSpeed(double speed);

private:
	can::WPI_TalonSRX* pLiftMotor;	//!< Pointer to a Talon
	
};
#endif
