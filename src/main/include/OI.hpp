#ifndef _OI_HG_
#define _OI_HG_

#include <WPILib.h>
#include <XboxController.h>

class OI {
public:
	OI();
	~OI();
	frc::XboxController* GetJoystickDrive(void);
	frc::XboxController* GetJoystickOperator(void);

private:
	frc::XboxController* pJoystickDrive;
	frc::XboxController* pJoystickOperator;
};

#endif
