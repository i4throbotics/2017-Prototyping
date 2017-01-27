
#ifndef AUTODRIVE_H
#define AUTODRIVE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class AutoDrive: public Command {
private:
	int Distance;
	double Speed;
	int Selection;
	Timer timer;
public:
	AutoDrive(int selection);

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();


};

#endif
