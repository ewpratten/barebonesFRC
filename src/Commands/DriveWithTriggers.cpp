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

	// The Y-axis goes from -1 (forward) to 1 (backwards) but we want to
	// set motor from 1 (forward) to -1 (reverse) so multiply by -1
	double xSpeed = pJoyDrive->GetTriggerAxis(frc::XboxController::kRightHand)
			- pJoyDrive->GetTriggerAxis(frc::XboxController::kLeftHand);
	double zRotation = pJoyDrive->GetX(XboxController::kLeftHand);

	if (fabs(zRotation) <= XBOX_DEADZONE_LEFT_JOY) {
		zRotation = 0.0;
	}

	CommandBase::pDriveTrain->ArcadeDrive(xSpeed, zRotation);

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
