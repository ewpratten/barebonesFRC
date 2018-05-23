#include <Commands/GenericControl.hpp>
#include <math.h>
#include <Utilities/Log.hpp>
#include "../RobotCFG.hpp"

GenericControl::GenericControl() {
	LOG("[DriveWithJoystick] Constructed");

	if (CommandBase::pGeneric != nullptr) {
		Requires(CommandBase::pGeneric);
	} else {
		LOG("[GenericControl] Generic is null!");
	}

	return;
}

// Called just before this Command runs the first time
void GenericControl::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void GenericControl::Execute() {
	frc::XboxController* pJoyOp = CommandBase::pOI->GetJoystickOperator();

	// Left Hand (Proto Motor 1)
	double xSpeed1 = pJoyOp->GetY(XboxController::kLeftHand) * -1; // Joystick
	if (pJoyOp->GetTriggerAxis(frc::XboxController::kLeftHand) > 0.9) {
		xSpeed1 = 1.0;
	}
	if (pJoyOp->GetBumper(XboxController::kLeftHand)) {
		xSpeed1 = -1.0;
	}

	// Right Hand (Proto Motor 2)
	double xSpeed2 = pJoyOp->GetY(XboxController::kRightHand) * -1; // Joystick
	if (pJoyOp->GetTriggerAxis(frc::XboxController::kRightHand) > 0.9) {
		xSpeed2 = 1.0;
	}
	if (pJoyOp->GetBumper(XboxController::kRightHand)) {
		xSpeed2 = -1.0;
	}

	double dSlow = (pJoyOp->GetAButton()) ? 0.5 : 1;

	CommandBase::pGeneric->setSpeed(1, xSpeed1 * dSlow);
	CommandBase::pGeneric->setSpeed(2, xSpeed2 * dSlow);
}

// Make this return true when this Command no longer needs to run execute()
bool GenericControl::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void GenericControl::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GenericControl::Interrupted() {

}
