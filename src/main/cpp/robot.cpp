#include <Robot.hpp>
#include <string>
#include "RobotCFG.hpp"
#include <Utilities/Log.hpp>

Robot::~Robot() {
	delete this->pDriveWithJoystick;
	delete this->pDriveWithTriggers;

	if (this->pAutonomousCommand != nullptr)
		delete this->pAutonomousCommand;

	return;
}

void Robot::RobotInit() {
	LOG("[Robot] Initialized");

	// initialize the commands
	this->pDriveWithJoystick = new DriveWithJoystick();
	this->pDriveWithTriggers = new DriveWithTriggers();

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

void Robot::TeleopInit() {
	LOG("[Robot] Teleop Initialized");

	if (JoyDrive == true) {
		if (this->pDriveWithJoystick != nullptr) {
			this->pDriveWithJoystick->Start();
		}
	} else {
		if (this->pDriveWithTriggers != nullptr) {
			this->pDriveWithTriggers->Start();
		}
	}

	if (this->pGenericControl != nullptr) {
		this->pGenericControl->Start();
		LOG("USE OP CONTROLLER FOR PROTOTYPING")
	}

	return;
}

void Robot::TeleopPeriodic() {
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
