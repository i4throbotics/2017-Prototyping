#ifndef HoldBall_H
#define HoldBall_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class HoldBall: public Command {

public:
	HoldBall();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();


};
#endif
