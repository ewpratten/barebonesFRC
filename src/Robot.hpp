#ifndef _ROBOT_HG_
#define _ROBOT_HG_

#include <WPILib.h>
#include <Commands/Command.h>
#include <Commands/DriveWithJoystick.hpp>
#include <Commands/DriveWithTriggers.hpp>
#include <Commands/GenericControl.hpp>
#include <Commands/Scheduler.h>
#include <SmartDashboard/SendableChooser.h>

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

	frc::SendableChooser<int> scRobotPosition;
	frc::SendableChooser<int> scRobotRole;
	frc::SendableChooser<int> scOverrideAuto;
	frc::Command* pAutonomousCommand;

};

#endif
