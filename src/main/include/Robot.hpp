#ifndef _ROBOT_HG_
#define _ROBOT_HG_

// Include required files
#include <WPILib.h>							// Wpilib Toolsuite
#include <Commands/Command.h>				// Wpilib Command handler
#include <Commands/DriveWithJoystick.hpp>	// DriveWithJoystick
#include <Commands/DriveWithTriggers.hpp>	// DriveWithTriggers
#include <Commands/GenericControl.hpp>		// GenericControl
#include <Commands/Scheduler.h>				// Command Scheduler
#include <SmartDashboard/SendableChooser.h>	// Wpilib Smartdashboard Auto Selection

class Robot: public frc::TimedRobot {
public:
	// Robot Positions
	~Robot();
	void RobotInit() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestInit() override;
	void TestPeriodic() override;

	// declare the commands
	DriveWithJoystick* pDriveWithJoystick;
	DriveWithTriggers* pDriveWithTriggers;
	GenericControl* pGenericControl;

private:
	int GetAutoType();

	// Declare Vars
	frc::SendableChooser<int> scRobotPosition;
	frc::SendableChooser<int> scRobotRole;
	frc::SendableChooser<int> scOverrideAuto;
	frc::Command* pAutonomousCommand;

};

#endif
