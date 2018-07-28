#include <CommandBase.hpp>
#include <Subsystems/DriveTrain.hpp>
#include <Subsystems/Generic.hpp>
#include <Utilities/Log.hpp>

// static variables in C++ have to be declared here
// (not in the .hpp file)
DriveTrain* CommandBase::pDriveTrain = NULL;
Generic* CommandBase::pGeneric = NULL;
OI* CommandBase::pOI = NULL;

CommandBase::CommandBase() :
		Command() {
	LOG("[CommandBase] Constructed");

	// Note: These aren't "this" because they are static,
	//	so there is only one instance of these variables in
	//	the CommandBase class. "this" pointers refer to
	//	regular variables that are created (and are unique)
	//	to the 'instance' of the object.

	if (CommandBase::pOI == nullptr) {
		CommandBase::pOI = new OI();
	}

	if (CommandBase::pDriveTrain == nullptr) {
		CommandBase::pDriveTrain = new DriveTrain();
	}

	if (CommandBase::pGeneric == nullptr) {
		CommandBase::pGeneric = new Generic();
	}

	return;
}

CommandBase::~CommandBase() {
	delete this->pDriveTrain;
	delete this->pGeneric;
	delete this->pOI;

	return;
}
