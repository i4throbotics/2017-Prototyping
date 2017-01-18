#include "AutoIntake.h"
#include "../RobotMap.h"
AutoIntake::AutoIntake(int selection)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Selection = selection;
}

// Called just before this Command runs the first time
void AutoIntake::Initialize()
{
	if(Selection == LOWBAR){
		Encoder = 450;
		Up=false;
	}
	else if(Selection == PORTCULLIS1){
		Encoder = SmartDashboard::GetNumber("Auto Portcullis - Intake Down Position", 450);
		Speed=SmartDashboard::GetNumber("Auto Portcullis - Lifting Intake Speed",	0.4);
		Up=false;

	}
	else if(Selection==PORTCULLIS2 || Selection==CHEVALDEFRISE3){
		Encoder = 15;
		Up=true;
	}
	else if(Selection ==CHEVALDEFRISE2){
		Encoder = SmartDashboard::GetNumber("Auto Cheval De Frise - Intake Down Position",250);
		Up=false;
	}

}

// Called repeatedly when this Command is scheduled to run
void AutoIntake::Execute(){
	if(Up){
		Robot::intake->Up(0.8);
	}
	else{
		Robot::intake->Down(0.8);
	}

}

// Make this return true when this Command no longer needs to run execute()
bool AutoIntake::IsFinished()
{
	bool done;
	if(Up){
		done=Robot::intake->GetEncoder()<Encoder;
	}
	else{
		done=Robot::intake->GetEncoder()>Encoder;
	}
	return done;
}

// Called once after isFinished returns true
void AutoIntake::End()
{
	if(Robot::intake->GetEncoder()>253){
			Robot::intake->Up(.05);
		}
		else{
			Robot::intake->Up(0);
		}
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoIntake::Interrupted()
{

}
