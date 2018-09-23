#include <Commands/ShiftGears.hpp>
#include <math.h>
#include <Utilities/Log.hpp>
#include "../RobotCFG.hpp"

ShiftGears::ShiftGears() {
	LOG("[ShiftGears] Constructed");

	return;
}

// Called just before this Command runs the first time
void ShiftGears::Initialize() {
    return;
}

// Called repeatedly when this Command is scheduled to run
void ShiftGears::Execute() {
	frc::XboxController* pJoyDriver = CommandBase::pOI->GetJoystickDrive();
    
    //Up
    if(pJoyDriver->GetPOV() == 0){
        *this->pGear = 1.0;
    }

    //Right
    if(pJoyDriver->GetPOV() == 90){
        *this->pGear = 0.75;
    }
    
    //Down
    if(pJoyDriver->GetPOV() == 180){
        *this->pGear = 0.50;
    }

    //Down
    if(pJoyDriver->GetPOV() == 270){
        *this->pGear = 0.25;
    }
    
    return;
	
}

void ShiftGears::SetGearPtr(double *gear){
    this->pGear = gear;
}

// Make this return true when this Command no longer needs to run execute()
bool ShiftGears::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ShiftGears::End() {
    return;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShiftGears::Interrupted() {
    return;
}