#include "StopIntakeDown.h"

StopIntakeDown::StopIntakeDown()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::intake.get());
	//Encoder=encoder;
}

// Called just before this Command runs the first time
void StopIntakeDown::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void StopIntakeDown::Execute()
{
	if(Robot::intake->GetEncoder()>253){
		Robot::intake->Up(.05);
	}
	else{
		Robot::intake->Up(0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool StopIntakeDown::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void StopIntakeDown::End()
{
	Robot::intake->Up(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StopIntakeDown::Interrupted()
{
	Robot::intake->Up(0);
}
