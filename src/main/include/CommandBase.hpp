#ifndef _COMMANDBASE_HG_
#define _COMMANDBASE_HG_

#include <OI.hpp>
#include <Subsystems/DriveTrain.hpp>
#include <Subsystems/Generic.hpp>
#include <WPILib.h>
#include "Commands/Command.h"

class CommandBase: public frc::Command {
public:
	CommandBase();
	~CommandBase();

	static OI* pOI;
	static DriveTrain* pDriveTrain;
	static Generic* pGeneric;
};

#endif
