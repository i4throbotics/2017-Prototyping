#include "AutoDrive.h"
#include "../RobotMap.h"
#include "../Robot.h"
AutoDrive::AutoDrive(int selection)
{
	Requires(Robot::chassis.get());
	Selection=selection;
}

// Called just before this Command runs the first time
void AutoDrive::Initialize()
{
	Robot::chassis->ResetBREncoder();
	Robot::chassis->ResetBLEncoder();
	Robot::chassis->ResetFREncoder();
	Robot::chassis->ResetFLEncoder();
	if(SmartDashboard::GetBoolean("Custom Auto", false)){
		Speed=SmartDashboard::GetNumber("Auto Drive Speed", 0.5);
		Distance=SmartDashboard::GetNumber("Auto Drive Distance", 1100);
		if(SmartDashboard::GetBoolean("Backwards", false)){
			Speed=Speed*-1;
		}
	}
	else{
		if(Selection == LOWBAR){
			Speed = 0.5;
			Distance = 1100;
		}
		else if(Selection == RAMPARTS){
			Speed=-0.7;
			Distance = 1250;
		}
		else if(Selection == ROUGH_TERRAIN){
			Speed=-0.7;
			Distance = 1100;
		}
	}
	timer.Start();
	/**
	else if(Selection == PORTCULLIS1){
		Speed = SmartDashboard::GetNumber("Auto Drive Speed",	0.5);
		Distance = SmartDashboard::GetNumber("Auto Portcullis - Drive Up Distance",	200.0);
	}
	else if(Selection == PORTCULLIS3){
		Speed = SmartDashboard::GetNumber("Auto Drive Speed",	0.5);
		Distance = SmartDashboard::GetNumber("Auto Portcullis - Drive Away Distance",	500.0);
	}
	else if(Selection==CHEVALDEFRISE1){
		Speed = SmartDashboard::GetNumber("Auto Drive Speed",	0.5);
		Distance = SmartDashboard::GetNumber("Auto Cheval De Frise - Drive Up Distance",	200.0);
	}
	else if(Selection==CHEVALDEFRISE3){
		Speed = SmartDashboard::GetNumber("Auto Drive Speed",	0.5);
		Distance = SmartDashboard::GetNumber("Auto Cheval De Frise - Drive Away Distance",	500.0);
	}
	else if(Selection == PORTCULLIS2){
		Speed = SmartDashboard::GetNumber("Auto Portcullis - Lifting Drive Speed",	0.6);

		Distance = SmartDashboard::GetNumber("Auto Portcullis - Drive and Lift Distance",	50.0);
	}**/
}

// Called repeatedly when this Command is scheduled to run
void AutoDrive::Execute()
{
	Robot::chassis->AutoDrive(Speed);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDrive::IsFinished()
{
	double encodertotal=0;
	int encoders=0;
	if(Robot::chassis->GetBLEncoder()!=0){
		encodertotal+=abs(Robot::chassis->GetBLEncoder());
		encoders++;
	}
	if(Robot::chassis->GetBREncoder()!=0){
			encodertotal+=abs(Robot::chassis->GetBREncoder());
			encoders++;
	}
	if(Robot::chassis->GetFLEncoder()!=0){
			encodertotal+=abs(Robot::chassis->GetFLEncoder());
			encoders++;
	}
	if(Robot::chassis->GetFREncoder()!=0){
			encodertotal+=abs(Robot::chassis->GetFREncoder());
			encoders++;
	}
	if(encoders==0){
		return timer.HasPeriodPassed(4);
	}
	else{
		double encodermean = encodertotal/encoders;
		return encodermean>Distance;
	}
}

// Called once after isFinished returns true
void AutoDrive::End()
{
	Robot::chassis->AutoDrive(0);
	timer.Stop();
	timer.Reset();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDrive::Interrupted()
{
	Robot::chassis->AutoDrive(0);
	timer.Stop();
	timer.Reset();
}
