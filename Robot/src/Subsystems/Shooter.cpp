// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "Shooter.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

Shooter::Shooter() :
		Subsystem("Shooter") {
	Motor = RobotMap::shooterMotor;
	//ShooterEncoder = RobotMap::shooterEncoder;
	//ShooterEncoder->Reset();
}

void Shooter::InitDefaultCommand() {

}

void Shooter::setSpeed(double speed) {
	Motor->Set(speed);

}
int Shooter::getEncoder() {
	return Motor->GetEncPosition();
}

void Shooter::resetEncoder(){
	Motor->SetEncPosition(0);
}

double Shooter::getVolt(){
	return Motor->GetOutputVoltage();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

