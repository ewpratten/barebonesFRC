#include <Commands/DriveWithJoystick.hpp>
#include <Commands/DriveWithTriggers.hpp>
#include <Subsystems/DriveTrain.hpp>
#include <Utilities/Log.hpp>
#include "DriveTrainMap.hpp"

DriveTrain::DriveTrain() : frc::Subsystem( "DriveTrain" )
{
  LOG( "[DriveTrain] Constructed" );
  // Initialize the motors
  this->pLeftFrontMotor = new can::WPI_TalonSRX( DRIVETRAIN_LEFT_FRONT_MOTOR_ID );
  this->pLeftRearMotor = new can::WPI_TalonSRX( DRIVETRAIN_LEFT_REAR_MOTOR_ID );
  this->pLeftRearMotor->Follow( *pLeftFrontMotor );

  this->pLeftFrontMotor->SetInverted( false );  // change this based on test or production robot
  this->pLeftRearMotor->SetInverted( false );   // change this based on test or production robot
  this->pLeftFrontMotor->SetNeutralMode( NeutralMode::Brake );
  this->pLeftRearMotor->SetNeutralMode( NeutralMode::Brake );

  this->pRightFrontMotor = new can::WPI_TalonSRX( DRIVETRAIN_RIGHT_FRONT_MOTOR_ID );
  this->pRightRearMotor = new can::WPI_TalonSRX( DRIVETRAIN_RIGHT_REAR_MOTOR_ID );
  this->pRightRearMotor->Follow( *pRightFrontMotor );

  this->pRightFrontMotor->SetInverted( true );  // change this based on test or production robot
  this->pRightRearMotor->SetInverted( true );   // change this based on test or production robot
  this->pRightFrontMotor->SetNeutralMode( NeutralMode::Brake );
  this->pRightRearMotor->SetNeutralMode( NeutralMode::Brake );

  this->pRobotDrive = new frc::DifferentialDrive( *pLeftFrontMotor, *pRightFrontMotor );

  this->pLeftFrontMotor->SetSafetyEnabled( false );
  this->pLeftRearMotor->SetSafetyEnabled( false );
  this->pRightFrontMotor->SetSafetyEnabled( false );
  this->pRightRearMotor->SetSafetyEnabled( false );
  this->pRobotDrive->SetSafetyEnabled( false );

  // Initialize the gyro
  // (See comment here about which port. We are using MXP, the one physically on
  // top of the RoboRio
  //  https://www.pdocs.kauailabs.com/navx-mxp/software/roborio-libraries/c/)
  this->pGyro = new AHRS( SPI::Port::kMXP );
  this->pGyro->Reset();

  return;
}

DriveTrain::~DriveTrain()
{
  delete this->pRobotDrive;
  delete this->pRightFrontMotor;
  delete this->pRightRearMotor;
  delete this->pLeftFrontMotor;
  delete this->pLeftRearMotor;

  delete this->pGyro;

  return;
}

void DriveTrain::InitAutonomousMode()
{
  LOG( "[DriveTrain] Autonomous Mode Initialized" );

  return;
}

void DriveTrain::InitDefaultCommand()
{
  LOG( "[DriveTrain] Initialized Default Command" );

  SetDefaultCommand( new DriveWithTriggers() );

  return;
}

void DriveTrain::DriveSetup()
{
  DriveTrain::ResetEncoders();

  this->pRightFrontMotor->Follow( *pLeftFrontMotor );

  return;
}

void DriveTrain::ArcadeDrive( double xSpeed, double zRotation )
{
  this->pRobotDrive->ArcadeDrive( zRotation,
				  xSpeed );  // API parameter order is incorrect

  return;
}

void DriveTrain::CurvatureDrive( double xSpeed, double zRotation, bool isQuickTurn )
{
  this->pRobotDrive->CurvatureDrive( xSpeed, zRotation, isQuickTurn );

  return;
}

void DriveTrain::TankDrive( double leftSpeed, double rightSpeed )
{
  this->pRobotDrive->TankDrive( leftSpeed, rightSpeed );

  return;
}

double DriveTrain::GetAngle() { return pGyro->GetAngle(); }

bool DriveTrain::IsDriving() { return this->pGyro->IsMoving(); }

bool DriveTrain::IsTurning() { return this->pGyro->IsRotating(); }

void DriveTrain::ResetGyro()
{
  pGyro->ZeroYaw();

  return;
}
