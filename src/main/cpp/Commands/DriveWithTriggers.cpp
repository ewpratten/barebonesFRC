#include <Commands/DriveWithTriggers.hpp>
#include <math.h>
#include <Utilities/Log.hpp>
#include "../RobotCFG.hpp"

DriveWithTriggers::DriveWithTriggers() {
	LOG("[DriveWithTriggers] Constructed");

	if (CommandBase::pDriveTrain != nullptr) {
		Requires(CommandBase::pDriveTrain);
	} else {
		LOG("[DriveWithTriggers] driveTrain is null!");
	}

	return;
}

DriveWithTriggers::~DriveWithTriggers() {
	LOG("[DriveWithTriggers] Destroyed");

	return;
}

void DriveWithTriggers::Initialize() {
	LOG("[DriveWithTriggers] Initialized");

	return;
}

void DriveWithTriggers::Execute() {
	frc::XboxController* pJoyDrive = CommandBase::pOI->GetJoystickDrive();

	if (pJoyDrive->GetXButtonReleased()) {
		this->isReverse = !this->isReverse;
	};

	// The Y-axis goes from -1 (forward) to 1 (backwards) but we want to
	// set motor from 1 (forward) to -1 (reverse) so multiply by -1
	double xSpeed = pJoyDrive->GetTriggerAxis(frc::XboxController::kRightHand)
			- pJoyDrive->GetTriggerAxis(frc::XboxController::kLeftHand);
	double zRotation = pJoyDrive->GetX(XboxController::kLeftHand);

	// Test the right bumper for setting slow mode
	double dSlow = (pJoyDrive->GetBumper(XboxController::kRightHand)) ? 0.5 : 1;
	// Set dReverse based on value of isReversed
	double dReverse = (this->isReverse) ? -1 : 1;

	if (fabs(zRotation) <= XBOX_DEADZONE_LEFT_JOY) {
		zRotation = 0.0;
	}
	
	// cv goes here

	CommandBase::pDriveTrain->ArcadeDrive((xSpeed * dSlow * dReverse),
			(zRotation * dSlow));

	return;
}

bool DriveWithTriggers::IsFinished() {
	return false;
}

void DriveWithTriggers::End() {
	return;
}

void DriveWithTriggers::Interrupted() {
	return;
}
