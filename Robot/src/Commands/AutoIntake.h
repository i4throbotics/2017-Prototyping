
#ifndef AUTOINTAKE_H
#define AUTOINTAKE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class AutoIntake: public Command {
private:
	int Encoder;
	double Speed;
	int Selection;
	bool Up;
public:
	AutoIntake(int selection);

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();


};

#endif
