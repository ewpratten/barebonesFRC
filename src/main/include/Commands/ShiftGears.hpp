#ifndef _SHIFTGEARS_HG_
#define _SHIFTGEARS_HG_

#include <CommandBase.hpp>
#include <WPILib.h>

class ShiftGears : public frc::Command {
public:
	ShiftGears();
	~ShiftGears();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
    void SetGearPtr(double *gear);
private:
    double* pGear;
};

#endif