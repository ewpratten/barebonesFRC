#ifndef _DRIVEWITHTRIGGERS_HG_
#define _DRIVEWITHTRIGGERS_HG_

#include <CommandBase.hpp>
#include <WPILib.h>

class DriveWithTriggers: public CommandBase {
public:
	DriveWithTriggers();
	~DriveWithTriggers();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:
	bool isReverse = false;
};

#endif
