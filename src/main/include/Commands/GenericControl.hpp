
#pragma once

#include <CommandBase.hpp>
#include <WPILib.h>

class GenericControl : public frc::Command {
public:
	GenericControl();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

