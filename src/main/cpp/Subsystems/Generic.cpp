#include <Commands/GenericControl.hpp>
#include <Subsystems/Generic.hpp>
#include "./GenericMap.hpp"
#include <Utilities/Log.hpp>
#include "../RobotCFG.hpp"

Generic::Generic() :
		frc::Subsystem("Generic") {
	LOG("[Generic] Constructed");

	// Initialize the motors
	this->pMotor1 = new can::WPI_TalonSRX(PROTO_1_MOTOR_ID);
	this->pMotor2 = new can::WPI_TalonSRX(PROTO_2_MOTOR_ID);

	this->pMotor1->SetNeutralMode(
			ctre::phoenix::motorcontrol::NeutralMode::ProtoBrakeMode);
	this->pMotor2->SetNeutralMode(
			ctre::phoenix::motorcontrol::NeutralMode::ProtoBrakeMode);
//
//	this->pRightFrontMotor = new can::WPI_TalonSRX(
//			Generic_RIGHT_FRONT_MOTOR_ID);
//	this->pRightRearMotor = new can::WPI_TalonSRX(
//			Generic_RIGHT_REAR_MOTOR_ID);
//	this->pRightRearMotor->Follow(*pRightFrontMotor);

//	this->pRobotDrive = new frc::DifferentialDrive(*pLeftFrontMotor,
//			*pRightFrontMotor);

	this->pMotor1->SetSafetyEnabled(false);
	this->pMotor2->SetSafetyEnabled(false);

	return;
}

Generic::~Generic() {
//	delete this->pRobotDrive;
	delete this->pMotor1;
	delete this->pMotor2;

	return;
}

//void Generic::InitDefaultCommand() {
//	LOG("[Generic] Initialized Default Command");
//
//	SetDefaultCommand(new GenericControl());
//
//	return;
//}

void Generic::setSpeed(int ID, double speed) {
	if (ID == 1) {
		this->pMotor1->Set(speed);
	} else if (ID == 2) {
		this->pMotor2->Set(speed);
	} else {
		LOG("[Generic] ERROR!! INVALID MOTOR ID IN setSpeed");
	}
}
