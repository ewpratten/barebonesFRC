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
	void InitMotionProfilingMode(void);

	// Used for autonomous mode
	void DriveSetup(void);
	void Drive(double distance, double speed);
	void TurnSetup(void);
	void Turn(void);

	// These are the same as the DifferentialDrive class:
	void ArcadeDrive(double xSpeed, double zRotation);
	void CurvatureDrive(double xSpeed, double zRotation, bool isQuickTurn);
	void TankDrive(double leftSpeed, double rightSpeed);

	double GetAngle(void);

	can::WPI_TalonSRX* GetLeftFrontMotor();  // Needed by Motion Profiler
	int GetLeftClosedLoopError(void);
	double GetLeftDistance(void);
	double GetLeftPosition(void);
	int GetLeftVelocity(void);

	can::WPI_TalonSRX* GetRightFrontMotor(); // Needed by Motion Profiler
	int GetRightClosedLoopError(void);
	double GetRightDistance(void);
	double GetRightPosition(void);
	int GetRightVelocity(void);

	double GetRotateToAngleRate(void);
	double GetTargetPosition(void);

	bool IsDriving(void);
	bool IsTurning(void);

	void ResetDrive(void);
	void ResetEncoders(void);
	void ResetGyro(void);

	void SetEncoders(void);
	void SetRotateToAngleRate(double rate);
	void SetSetpoint(double setpoint);
	void SetTargetPosition(double target);

	// Send motor data to SmartDashboard
	void Trace(void);
	void Trace(WPI_TalonSRX* pTalonSRX, const std::string name);

	virtual void PIDWrite(double output) override;

private:
	can::WPI_TalonSRX* pLeftFrontMotor;
	can::WPI_TalonSRX* pLeftRearMotor;
	can::WPI_TalonSRX* pRightFrontMotor;
	can::WPI_TalonSRX* pRightRearMotor;

	frc::DifferentialDrive* pRobotDrive;

	AHRS* pGyro;
	PIDController* pTurnController;

	double dTargetPostionRotations = 0.00;
	double dRotateToAngleRate;
};

#endif
