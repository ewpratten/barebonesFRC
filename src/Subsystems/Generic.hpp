#ifndef _GENERIC_HG_
#define _GENERIC_HG_

#include <string>
#include <WPILib.h>
#include <Commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include <Drive/DifferentialDrive.h>

class Generic: public frc::Subsystem {
public:
	Generic();
	~Generic();

//	void InitDefaultCommand(void) override;
	void setSpeed(int ID, double speed);

private:
	can::WPI_TalonSRX* pMotor1;
	can::WPI_TalonSRX* pMotor2;

};

#endif
