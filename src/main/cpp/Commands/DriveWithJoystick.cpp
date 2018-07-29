#include <Commands/DriveWithJoystick.hpp>
#include <math.h>
#include <Utilities/Log.hpp>
#include "../RobotCFG.hpp"
#include <ntcore.h>
#include <networktables/NetworkTableInstance.h>
#include <Subsystems/CVServer.hpp>

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
	table = NetworkTable::GetTable("SmartDashboard");
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

	// Calculate final speed and rotation
	xSpeed = (xSpeed * dSlow * dReverse);
	zRotation = (zRotation * dSlow);

	// If the vision mode is enabled, get info from table and store in vars
	if(Vision && pJoyDrive->GetBButton()){
		double Speed, Rotation;
		std::tie(Speed, Rotation) = GetMotorSpeeds(table);
		xSpeed = Speed;
		zRotation = Rotation;
	}

	// This is the drive stuff
	CommandBase::pDriveTrain->ArcadeDrive(xSpeed, zRotation);

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
