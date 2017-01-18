#include "SlopeCalculation.h"

SlopeCalculation::SlopeCalculation()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::shooter.get());
	lastEncoder=Robot::shooter->getEncoder();
	//speed = -1.0;
}

// Called just before this Command runs the first time
void SlopeCalculation::Initialize()
{
	time.Start();
}
// Called repeatedly when this Command is scheduled to run
void SlopeCalculation::Execute()
{
	speed = SmartDashboard::GetNumber("shooter speed", 0);
	Robot::shooter->setSpeed(speed);
	//SmartDashboard::PutNumber("Shooter speed", speed);
	SmartDashboard::PutNumber(" shooter encoder", Robot::shooter->getEncoder());
	SmartDashboard::PutNumber("lat encoder", lastEncoder);
	SmartDashboard::PutNumber("voltage", Robot::shooter->getVolt());
	if(time.HasPeriodPassed(1)){
		double slope = speed / ((Robot::shooter->getEncoder()/1000000.0));
		Robot::shooter->resetEncoder();
		SmartDashboard::PutNumber("Slope", slope);
		//lastEncoder = Robot::shooter->getEncoder();
		//speed += .01;
	}

}

// Make this return true when this Command no longer needs to run execute()
bool SlopeCalculation::IsFinished()
{

	return false;
}

// Called once after isFinished returns true
void SlopeCalculation::End()
{
	Robot::shooter->setSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SlopeCalculation::Interrupted()
{
	Robot::shooter->setSpeed(0);
}
