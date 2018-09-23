//! The main robot class that is called by the RoboRIO

#ifndef _ROBOT_HG_
#define _ROBOT_HG_

// Include required files
#include <WPILib.h>													// Wpilib Toolsuite
#include <Commands/Command.h>								// Wpilib Command handler
#include <Commands/DriveWithJoystick.hpp>		// DriveWithJoystick
#include <Commands/DriveWithTriggers.hpp>		// DriveWithTriggers
#include <Commands/GenericControl.hpp>			// GenericControl
#include <Commands/Scheduler.h>							// Command Scheduler
#include <SmartDashboard/SendableChooser.h>	// Wpilib Smartdashboard Auto Selection

class Robot: public frc::TimedRobot {
public:
	// Robot Positions
	~Robot(); 													//!< The class destructor
	void RobotInit() override;					//!< This code is run when the robot boots up
	void DisabledInit() override; 			//!< This code runs once as soon as the robot is disabled
	void DisabledPeriodic() override; 	//!< This code is run in a loop while the robot is disabled
	void AutonomousInit() override;			//!< This code is run once at the very begining of auto
	void AutonomousPeriodic() override;	//!< This code is run in a loop during auto
	void TeleopInit() override;					//!< This code is run once at the very beginning of teleop
	void TeleopPeriodic() override;			//!< This code is run in a loop suring teleop
	void TestInit() override;						//!< This code is run once at the very benining of test mode
	void TestPeriodic() override;				//!< This code is run in a loop during test mode

	// declare the commands
	DriveWithJoystick* pDriveWithJoystick;	//!< A pointer that contains the DriveWithJoystick class
	DriveWithTriggers* pDriveWithTriggers;	//!< A pointer that contains the DriveWithJoystick class
	GenericControl* pGenericControl;				//!< A pointer the contains the GenericControl class

private:
	int GetAutoType();	//!< Returns the auto type to run based on data from the FMS and Driverstation

	// Declare Vars
	frc::SendableChooser<int> scRobotPosition;	//!< Stores the robot's position from the smartdashboard
	frc::SendableChooser<int> scRobotRole;			//!< Stores the auto mode set by the drivers
	frc::SendableChooser<int> scOverrideAuto;		//!< Stores weather or not to override the normal auto sequence
	frc::Command* pAutonomousCommand;						//!< Stores the auto command to be run

};

#endif
