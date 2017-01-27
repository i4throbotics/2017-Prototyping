#include "IntakeWheels.h"

IntakeWheels::IntakeWheels(bool out)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	this->out=out;
}

// Called just before this Command runs the first time
void IntakeWheels::Initialize()
{
	Robot::intake->SetBallHeld(false);
	if(out){
		Robot::intake->Out(.7);
	}
	else{
		Robot::intake->In(.7);
	}
}

// Called repeatedly when this Command is scheduled to run
void IntakeWheels::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool IntakeWheels::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void IntakeWheels::End()
{
	Robot::intake->In(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeWheels::Interrupted()
{
	Robot::intake->In(0);
}
