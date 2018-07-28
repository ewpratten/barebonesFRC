#ifndef _DRIVEWITHJOYSTICK_HG_
#define _DRIVEWITHJOYSTICK_HG_

#include <CommandBase.hpp>
#include <WPILib.h>

class DriveWithJoystick: public CommandBase {
public:
	DriveWithJoystick();
	~DriveWithJoystick();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:
	bool isReverse = false;
};

#endif
