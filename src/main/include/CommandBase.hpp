//! The base class for all commands

#ifndef _COMMANDBASE_HG_
#define _COMMANDBASE_HG_

#include <OI.hpp>
#include <Subsystems/DriveTrain.hpp>
#include <Subsystems/Generic.hpp>
#include <WPILib.h>
#include "Commands/Command.h"

class CommandBase: public frc::Command {
public:
	CommandBase();	//!< Class constructor
	~CommandBase();	//!< Class destructor

	static OI* pOI;									//!< Pointer to the OI class
	static DriveTrain* pDriveTrain;	//!< Pointer to the DriveTrain subsystem
	static Generic* pGeneric;				//!< Pointer to the Generic subsystem
};

#endif
