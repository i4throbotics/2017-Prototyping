#include "HoldBall.h"

HoldBall::HoldBall()
{
	// Use Requires() here to declare subsystem dependencies
}

// Called just before this Command runs the first time
void HoldBall::Initialize()
{
	if(Robot::intake->GetBallHeld()){
		Robot::intake->In(.0);
		Robot::intake->SetBallHeld(false);
	}
	else{
		Robot::intake->In(.25);
		Robot::intake->SetBallHeld(true);
	}
}

// Called repeatedly when this Command is scheduled to run
void HoldBall::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool HoldBall::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void HoldBall::End()
{
	if(Robot::intake->GetBallHeld()){
		Robot::intake->In(.0);
		Robot::intake->SetBallHeld(false);
	}
	else{
		Robot::intake->In(.4);
		Robot::intake->SetBallHeld(true);
	}
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HoldBall::Interrupted()
{
	if(Robot::intake->GetBallHeld()){
		Robot::intake->In(.0);
		Robot::intake->SetBallHeld(false);
	}
	else{
		Robot::intake->In(.4);
		Robot::intake->SetBallHeld(true);
	}
}
