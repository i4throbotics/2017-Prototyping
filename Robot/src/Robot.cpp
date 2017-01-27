#include "Robot.h"
#include <climits>//added
#include <iostream>
#include "Commands/Autonomous.h"
std::shared_ptr<Chassis> Robot::chassis;
std::shared_ptr<LiftingMech> Robot::liftingMech;
std::shared_ptr<Intake> Robot::intake;
std::shared_ptr<Shooter> Robot::shooter;
std::unique_ptr<OI> Robot::oi;
std::unique_ptr<I2C> Robot::wire;
int Robot::x;
bool Robot::done;
std::ofstream file;


void Robot::RobotInit() {
	RobotMap::init();

	chassis.reset(new Chassis());
	liftingMech.reset(new LiftingMech());
	intake.reset(new Intake());
	shooter.reset(new Shooter());

	oi.reset(new OI());
	wire.reset(new I2C(I2C::Port::kOnboard, 4));
	x = 0;
	done = false;
	file.open("/home/lvuser/cameratestoutput.txt");
	//file<<"hell ojgfhslk;fhgfdhf djkhf dlkjfd"<<std::endl;
	//CameraServer::GetInstance()->SetQuality(75);
	//CameraServer::GetInstance()->StartAutomaticCapture("cam0");

	SmartDashboard::PutString("Auto Program", "Low Bar");
	SmartDashboard::PutBoolean("Backwards", false);

	SmartDashboard::PutBoolean("Custom Auto", false);
	SmartDashboard::PutNumber("Auto Drive Distance", 1100);
	SmartDashboard::PutNumber("Auto Drive Speed", 0.5);
	SmartDashboard::PutNumber("shooter speed", 0);
	SmartDashboard::PutNumber("kP", 1);
	SmartDashboard::PutNumber("kI", 0);
	SmartDashboard::PutNumber("kD", 0.1);


	/**SmartDashboard::PutNumber("Auto Drive Speed",	0.5);
	 SmartDashboard::PutNumber("Auto Drive Distance", 1600);
	 SmartDashboard::PutNumber("Auto Portcullis - Drive Up Distance",	200.0);
	 SmartDashboard::PutNumber("Auto Portcullis - Intake Down Position",	450);
	 SmartDashboard::PutNumber("Auto Portcullis - Drive and Lift Distance",	50.0);
	 SmartDashboard::PutNumber("Auto Portcullis - Lifting Drive Speed",	0.6);
	 SmartDashboard::PutNumber("Auto Portcullis - Lifting Intake Speed",	0.4);
	 SmartDashboard::PutNumber("Auto Portcullis - Drive Away Distance",	500.0);
	 SmartDashboard::PutNumber("Auto Cheval De Frise - Drive Up Distance",	200.0);
	 SmartDashboard::PutNumber("Auto Cheval De Frise - Intake Down Position",	250.0);
	 SmartDashboard::PutNumber("Auto Cheval De Frise - Intake Up Speed",	0.4);
	 SmartDashboard::PutNumber("Auto Cheval De Frise - Drive Away Distance",	500.0);
	 SmartDashboard::PutNumber("Intake Lift Speed",	0.8);
	 SmartDashboard::PutNumber("Intake Down Position",	290.0);**/
	/**SmartDashboard::PutNumber("Auto Drive Speed", 0.5);
	 SmartDashboard::PutNumber("Auto Drive Distance", 100);
	 SmartDashboard::PutNumber("Auto Intake Grab Position", 200);

	 SmartDashboard::PutNumber("Auto Portcullis - Drive Up Distance", 200);
	 SmartDashboard::PutNumber("Auto Portcullis - Drive and Lift Distance", 100);
	 SmartDashboard::PutNumber("Auto Portcullis - Drive Away Distance", 100);
	 SmartDashboard::PutNumber("Auto Portcullis - Lifting Drive Speed", 0.3);
	 SmartDashboard::PutNumber("Auto Portcullis - Lifting Intake Speed", 0.2);
	 SmartDashboard::PutNumber("Auto Portcullis - Intake Down Position", 100);
	 SmartDashboard::PutNumber("Auto Portcullis - Intake Up Position", 50);

	 SmartDashboard::PutNumber("Auto Cheval De Frise - Drive Up Distance", 200);
	 SmartDashboard::PutNumber("Auto Cheval De Frise - Drive 2 Distance", 1000);
	 SmartDashboard::PutNumber("Auto Cheval De Frise - Intake Down Position", 100);
	 SmartDashboard::PutNumber("Auto Cheval De Frise - Intake Up Position", 50);

	 SmartDashboard::PutNumber("BL Adjustment", 1);
	 SmartDashboard::PutNumber("BR Adjustment", 1);
	 SmartDashboard::PutNumber("FL Adjustment", 1);
	 SmartDashboard::PutNumber("FR Adjustment", 1);**/

}

void Robot::DisabledInit() {
	file.close();
}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {

	if (SmartDashboard::GetString("Auto Program", "") == "Low Bar") {
		autonomousCommand.reset(new Autonomous(LOWBAR));
	} else if (SmartDashboard::GetString("Auto Program", "") == "Portcullis") {
		autonomousCommand.reset(new Autonomous(PORTCULLIS));
	} else if (SmartDashboard::GetString("Auto Program", "")
			== "Cheval De Frise") {
		autonomousCommand.reset(new Autonomous(CHEVALDEFRISE));
	} else if (SmartDashboard::GetString("Auto Program", "") == "Ramparts") {
		autonomousCommand.reset(new Autonomous(RAMPARTS));
	} else if (SmartDashboard::GetString("Auto Program", "")
			== "Rough Terrain") {
		autonomousCommand.reset(new Autonomous(ROUGH_TERRAIN));
	} else {
		autonomousCommand.reset(new Autonomous(DEADBOT));
	}
	//autonomousCommand = std::dynamic_pointer_cast<Command>( autoChooser->GetSelected());
	if (autonomousCommand.get() != nullptr) {
		autonomousCommand->Start();
	}
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();

	SmartDashboard::PutNumber("BL Encoder", Robot::chassis->GetBLEncoder());
	SmartDashboard::PutNumber("BR Encoder", Robot::chassis->GetBREncoder());
	SmartDashboard::PutNumber("FL Encoder", Robot::chassis->GetFLEncoder());
	SmartDashboard::PutNumber("FR Encoder", Robot::chassis->GetFREncoder());
	SmartDashboard::PutNumber("FlippyLifty Encoder",
			Robot::intake->GetEncoder());

	/**SmartDashboard::PutNumber("BL Speed", Robot::chassis->GetBLSpeed());
	 SmartDashboard::PutNumber("BR Speed", Robot::chassis->GetBRSpeed());
	 SmartDashboard::PutNumber("FL Speed", Robot::chassis->GetFLSpeed());
	 SmartDashboard::PutNumber("FR Speed", Robot::chassis->GetFRSpeed());**/
}

void Robot::TeleopInit() {
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();

	std::cout << x;

}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();

	uint8_t buffer[sizeof(float)];
	float result;
	Robot::wire->Read(0, sizeof(float), &buffer[0]);
	std::memcpy(&result, &buffer[0], sizeof(float));
	std::cout<<result<<std::endl;

	SmartDashboard::PutNumber("BL Encoder", Robot::chassis->GetBLEncoder());
	SmartDashboard::PutNumber("BR Encoder", Robot::chassis->GetBREncoder());
	SmartDashboard::PutNumber("FL Encoder", Robot::chassis->GetFLEncoder());
	SmartDashboard::PutNumber("FR Encoder", Robot::chassis->GetFREncoder());
	SmartDashboard::PutNumber("FlippyLifty Encoder",
			Robot::intake->GetEncoder());

}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

