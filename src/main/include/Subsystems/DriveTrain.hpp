//! The subsystem in charge of controlling the robot's DriveTrain

#ifndef _DRIVETRAIN_HG_
#define _DRIVETRAIN_HG_

#include <string>
#include <WPILib.h>
#include <Commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include <Drive/DifferentialDrive.h>

// If you get an error including this library, you'll need to get the navX libraries from here:
// https://www.pdocs.kauailabs.com/navx-mxp/software/roborio-libraries/c/
#include <AHRS.h>

class DriveTrain: public frc::Subsystem, PIDOutput {
public:
	DriveTrain(); 	//!< Class constructor
	~DriveTrain();	//!< Class destructor

	void InitAutonomousMode(void);
	void InitDefaultCommand(void) override;
	
	// These are the same as the DifferentialDrive class:
	void ArcadeDrive(double xSpeed, double zRotation);
	void CurvatureDrive(double xSpeed, double zRotation, bool isQuickTurn);
	void TankDrive(double leftSpeed, double rightSpeed);

	double GetAngle(void);

	bool IsDriving(void);
	bool IsTurning(void);

private:
	can::WPI_TalonSRX* pLeftFrontMotor;
	can::WPI_TalonSRX* pLeftRearMotor;
	can::WPI_TalonSRX* pRightFrontMotor;
	can::WPI_TalonSRX* pRightRearMotor;

	frc::DifferentialDrive* pRobotDrive;

	AHRS* pGyro;
};

#endif
