#include "HoldWheels.h"

HoldWheels::HoldWheels()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void HoldWheels::Initialize()
{
	Robot::chassis->SetBLSpeed(0.05);
	Robot::chassis->SetBRSpeed(0.05);
	Robot::chassis->SetFLSpeed(0.05);
	Robot::chassis->SetFRSpeed(0.05);
}

// Called repeatedly when this Command is scheduled to run
void HoldWheels::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool HoldWheels::IsFinished()
{
	return (fabs(Robot::oi->getAxis(0))>0.1 || fabs(Robot::oi->getAxis(1))>0.1);
}

// Called once after isFinished returns true
void HoldWheels::End()
{
	Robot::chassis->AutoDrive(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HoldWheels::Interrupted()
{
	Robot::chassis->AutoDrive(0);
}
