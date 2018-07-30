// Include required files
#include <Robot.hpp>			// Robot header file (containes includes for all other files)
#include "RobotCFG.hpp"			// Robot-wide configuration file
#include <Utilities/Log.hpp>	// LOG tool. Used for printing to the RIOlog console

// Robot Destructor
Robot::~Robot() {
	// Delete command pointers
	delete this->pDriveWithJoystick;
	delete this->pDriveWithTriggers;

	if (this->pAutonomousCommand != nullptr)
		delete this->pAutonomousCommand;

	return;
}

// Robot Initialization
void Robot::RobotInit() {
	LOG("[Robot] Initialized");

	// Initialize the drive commands
	this->pDriveWithJoystick = new DriveWithJoystick();
	this->pDriveWithTriggers = new DriveWithTriggers();


	if(Camera_Server){ // If the Camera_server setting is set in RobotCFG.
		// Initialize the camera server
		LOG("CSCORE INIT");
		CameraServer::GetInstance()->StartAutomaticCapture();
	}else{
		LOG("CSCORE not running due to config setting");
	}

	return;
}

void Robot::DisabledInit() {
	return;
}

void Robot::DisabledPeriodic() {
	frc::Scheduler::GetInstance()->Run();

	return;
}

void Robot::AutonomousInit() {
	LOG("[Robot] Autonomous Initialized");

	// Remove this when auto is added
	LOG("[Robot] Auto aborted due to no code")

	return;
}

void Robot::AutonomousPeriodic() {
	frc::Scheduler::GetInstance()->Run();

	return;
}

// Robot Teleop Initialization
void Robot::TeleopInit() {
	LOG("[Robot] Teleop Initialized");

	// If Joydrive setting is enabled, use joystick drive, else use trigger drive
	if (JoyDrive == true) {
		if (this->pDriveWithJoystick != nullptr) {
			this->pDriveWithJoystick->Start();
		}
	} else {
		if (this->pDriveWithTriggers != nullptr) {
			this->pDriveWithTriggers->Start();
		}
	}

	// Use Generic Control to control other on-board motors
	if (this->pGenericControl != nullptr) {
		this->pGenericControl->Start();
		LOG("USE OP CONTROLLER FOR PROTOTYPING")
	}
	// Replace above with commands for other hardware controlls

	return;
}

void Robot::TeleopPeriodic() {
	// Run Teleop
	frc::Scheduler::GetInstance()->Run();

	return;
}

void Robot::TestInit() {
	return;
}

void Robot::TestPeriodic() {
	return;
}

// The main() function is hidden in this
//	pre-processor macro...
START_ROBOT_CLASS(Robot)
