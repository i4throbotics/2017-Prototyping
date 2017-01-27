#include "IntakeLift.h"

IntakeLift::IntakeLift(bool up)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::intake.get());
	this->up=up;
}

// Called just before this Command runs the first time
void IntakeLift::Initialize()
{

	if(up){
		Robot::intake->Up(0.5);
	}
	else{
		Robot::intake->Down(0.5);
	}
}

// Called repeatedly when this Command is scheduled to run
void IntakeLift::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool IntakeLift::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void IntakeLift::End()
{
	//if(Up){
	//Robot::intake->Up(0.05);
	/**}
	else{
		new StopIntakeDown(Robot::intake->GetEncoder());
	}**/
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeLift::Interrupted()
{

	//Robot::intake->Up(0.05);

}
