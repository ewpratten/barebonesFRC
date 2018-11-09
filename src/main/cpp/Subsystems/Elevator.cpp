#include <Subsystems/Elevator.hpp>  //!< Elevator subsystem header
#include <Utilities/Log.hpp>	//!< Printing to the Riolog
#include "../RobotCFG.hpp"	  //!< Robot config

//!< Constructor
Elevator::Elevator() : frc::Subsystem( "Elevator" )
{
  LOG( "[Elevator] Constructed" );  //!< Print to screen

  //!< Construct a new tallon
  this->pLiftMotor = new can::WPI_TalonSRX( 5 );
  //!< Enable brake mode
  this->pLiftMotor->SetNeutralMode( ctre::phoenix::motorcontrol::NeutralMode::ProtoBrakeMode );

  //!< Disable saftey mode
  this->pLiftMotor->SetSafetyEnabled( false );
  return;
}

Elevator::~Elevator()
{
  LOG( "[Elevator] Destructed" )
  delete this->pLiftMotor;
  return;
}

//!< Sets the speed of a motor
void setSpeed( double speed ) { this->pLiftMotor->set( speed ); }