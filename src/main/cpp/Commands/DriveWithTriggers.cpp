#include <Commands/DriveWithTriggers.hpp>
#include <math.h>
#include <Utilities/Log.hpp>
#include "../RobotCFG.hpp"
#include <ntcore.h>
#include <tuple>
#include <networktables/NetworkTableInstance.h>
#include <Subsystems/CVServer.hpp>

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
	table = NetworkTable::GetTable("SmartDashboard");

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

	// Calculate final speed and rotation
	xSpeed = (xSpeed * dSlow * dReverse);
	zRotation = (zRotation * dSlow);

	// If the vision mode is enabled, get info from table and store in vars
	if(Vision){
		double Speed, Rotation;
		std::tie(Speed, Rotation) = GetMotorSpeeds(table);
		xSpeed = Speed;
		zRotation = Rotation;
	}

	// This is the drive stuff
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
