// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

#include "Subsystems/Chassis.h"
#include "Subsystems/LiftingMech.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/Intake.h"
#include <fstream>
#include "OI.h"

class Robot : public IterativeRobot {
private:
	static int x;
	static bool done;
	static std::unique_ptr<I2C> wire;
public:

	//static std::shared_ptr<Preferences> prefs;


	//std::shared_ptr<SendableChooser> autoChooser;
	std::unique_ptr<Command> autonomousCommand;
	static std::unique_ptr<OI> oi;
	LiveWindow *lw = LiveWindow::GetInstance();
    static std::shared_ptr<Chassis> chassis;
    static std::shared_ptr<LiftingMech> liftingMech;
    static std::shared_ptr<Shooter> shooter;
    static std::shared_ptr<Intake> intake;


	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
};
#endif
