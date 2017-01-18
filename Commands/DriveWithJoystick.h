
#ifndef DRIVEWITHJOYSTICK_H
#define DRIVEWITHJOYSTICK_H


#include "Commands/Subsystem.h"
#include "../Robot.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class DriveWithJoystick: public Command {
private:

	std::vector<double> BLEncoderVals;
	std::vector<double> BREncoderVals;
	std::vector<double> FLEncoderVals;
	std::vector<double> FREncoderVals;
	double BLEncoderVal;
	double BREncoderVal;
	double FLEncoderVal;
	double FREncoderVal;

	Timer time;
	double lasttime;
	double currenttime;

	double lastBLencoder;
	double lastBRencoder;
	double lastFLencoder;
	double lastFRencoder;

	double BLerrorsimple;
	double BLerrorsum;
	double BLerrorchange;
	double BLolderror;

	double BRerrorsimple;
	double BRerrorsum;
	double BRerrorchange;
	double BRolderror;

	double FLerrorsimple;
	double FLerrorsum;
	double FLerrorchange;
	double FLolderror;

	double FRerrorsimple;
	double FRerrorsum;
	double FRerrorchange;
	double FRolderror;

	double BLAdjustment;
	double BRAdjustment;
	double FLAdjustment;
	double FRAsjustment;


public:
	DriveWithJoystick();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();


};

#endif
