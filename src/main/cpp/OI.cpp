#include <OI.hpp>
#include <Utilities/Log.hpp>
#include "RobotCFG.hpp"

OI::OI()
{
  LOG( "[OI] Constructed" );

  // NOTE: For some reason, Eclipse complains about not finding
  //	the XboxController class, even though it compiles 100% OK.
  // This appears to be because we are using the depricated wpi class and not the frc one.
  this->pJoystickDrive = new XboxController( XBOX_CONTROLLER_DRIVE_PORT );
  this->pJoystickOperator = new XboxController( XBOX_CONTROLLER_OPERATOR_PORT );

  return;
}

OI::~OI()
{
  delete this->pJoystickDrive;
  delete this->pJoystickOperator;

  return;
}

frc::XboxController *OI::GetJoystickDrive() { return this->pJoystickDrive; }

frc::XboxController *OI::GetJoystickOperator() { return this->pJoystickOperator; }
