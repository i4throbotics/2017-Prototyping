#ifndef HoldWheels_H
#define HoldWheels_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class HoldWheels: public Command {
public:
	HoldWheels();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();


};

#endif
