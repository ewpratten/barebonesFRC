//Header
#ifndef _DRIVEWITHTRIGGERS_HG_
#define _DRIVEWITHTRIGGERS_HG_

// Include Required Files
#include <CommandBase.hpp>						// Wpilib CommandBase
#include <WPILib.h>								// Wpilib
#include <ntcore.h>								// Wpilib NetworkTables Core Lib
#include <networktables/NetworkTableInstance.h>	// Wpilib NetworkTables
#include <Subsystems/CVServer.hpp>				// NetworkTables-Based Control Server
#include <tuple>							// STD tuple Lib

class DriveWithTriggers: public CommandBase {
public:
	// Functions
	DriveWithTriggers();
	~DriveWithTriggers();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
	double* GetGearPtr();
private:
	// Define Vars
	double gear = 1.0;
	bool isReverse = false;
	std::shared_ptr<NetworkTable> table;
};

#endif