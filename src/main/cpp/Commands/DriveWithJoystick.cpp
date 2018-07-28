#include <Commands/DriveWithJoystick.hpp>
#include <math.h>
#include <Utilities/Log.hpp>
#include "../RobotCFG.hpp"

DriveWithJoystick::DriveWithJoystick() {
	LOG("[DriveWithJoystick] Constructed");

	if (CommandBase::pDriveTrain != nullptr) {
		Requires(CommandBase::pDriveTrain);
	} else {
		LOG("[DriveWithJoystick] driveTrain is null!");
	}

	return;
}

DriveWithJoystick::~DriveWithJoystick() {
	LOG("[DriveWithJoystick] Destroyed");

	return;
}

void DriveWithJoystick::Initialize() {
	LOG("[DriveWithJoystick] Initialized");

	this->isReverse = false;

	return;
}

void DriveWithJoystick::Execute() {
	frc::XboxController* pJoyDrive = CommandBase::pOI->GetJoystickDrive();

	if (pJoyDrive->GetXButtonReleased()) {
		this->isReverse = !this->isReverse;
	}

	// The Y-axis goes from -1 (forward) to 1 (backwards) but we want to
	// set motor from 1 (forward) to -1 (reverse) so multiply by -1
	double xSpeed = pJoyDrive->GetY(XboxController::kLeftHand) * -1;
	double zRotation = pJoyDrive->GetX(XboxController::kLeftHand);

	double dSlow = (pJoyDrive->GetBumper(XboxController::kRightHand)) ? 0.5 : 1;
	double dReverse = (this->isReverse) ? -1 : 1;

	if (fabs(xSpeed) <= XBOX_DEADZONE_LEFT_JOY) {
		xSpeed = 0.0;
	}

	if (fabs(zRotation) <= XBOX_DEADZONE_LEFT_JOY) {
		zRotation = 0.0;
	}

	CommandBase::pDriveTrain->ArcadeDrive((xSpeed * dSlow * dReverse),
			(zRotation * dSlow));

	return;
}

bool DriveWithJoystick::IsFinished() {
	return false;
}

void DriveWithJoystick::End() {
	return;
}

void DriveWithJoystick::Interrupted() {
	return;
}
