#include "PIDShoot.h"

PIDShoot::PIDShoot() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::shooter.get());
	errorLast = 0;
	errorDifference = 0;
	errorSum = 0;
}

// Called just before this Command runs the first time
void PIDShoot::Initialize() {
	speedGoal = SmartDashboard::GetNumber("shooter speed", 0);
	speed = speedGoal;
	Robot::shooter->setSpeed(speed);
	Robot::shooter->resetEncoder();
	time.Reset();
	time.Start();

}
// Called repeatedly when this Command is scheduled to run
void PIDShoot::Execute() {
	SmartDashboard::PutNumber("Actual encoder value", Robot::shooter->getEncoder());
	if (time.HasPeriodPassed(.01)) {
		SmartDashboard::PutNumber("encoder speed",
				(Robot::shooter->getEncoder() * (ENCODER_TO_SPEED) / .01));
		double error = speedGoal
				- (Robot::shooter->getEncoder() * (ENCODER_TO_SPEED) / .01);
		Robot::shooter->resetEncoder();
		//time.Reset();
		errorDifference = error - errorLast;
		errorSum += error;
		double acceleration = (SmartDashboard::GetNumber("kP", 1) * error)
				+ (SmartDashboard::GetNumber("kI", 0) * errorSum)
				+ (SmartDashboard::GetNumber("kD", 0.1) * errorDifference);
		speed += acceleration;
		Robot::shooter->setSpeed(speed);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool PIDShoot::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void PIDShoot::End() {
	Robot::shooter->setSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PIDShoot::Interrupted() {
	Robot::shooter->setSpeed(0);
}
