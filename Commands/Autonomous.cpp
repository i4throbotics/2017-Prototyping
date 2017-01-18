#include "Autonomous.h"
#include "../RobotMap.h"
#include "AutoDrive.h"
#include "AutoIntake.h"
#include "HoldBall.h"
Autonomous::Autonomous(int selection)
{
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
	if(selection == LOWBAR){

		AddSequential(new AutoIntake(LOWBAR));
		AddParallel(new HoldBall());
		AddSequential(new AutoDrive(LOWBAR));
	}
	else if(selection == PORTCULLIS){
		AddParallel(new AutoDrive(PORTCULLIS1));
		AddSequential(new AutoIntake(PORTCULLIS1));
		AddParallel(new AutoDrive(PORTCULLIS2));
		AddSequential(new AutoIntake(PORTCULLIS2));
		AddSequential(new AutoDrive(PORTCULLIS3));
	}
	else if(selection == CHEVALDEFRISE){
		AddSequential(new AutoDrive(CHEVALDEFRISE1));
		AddSequential(new AutoIntake(CHEVALDEFRISE2));
		AddParallel(new AutoDrive(CHEVALDEFRISE3));
		AddSequential(new AutoIntake(CHEVALDEFRISE3));
	}
	else if(selection==RAMPARTS){
		AddSequential(new AutoDrive(RAMPARTS));
	}
	else if(selection==ROUGH_TERRAIN){
		AddSequential(new AutoDrive(ROUGH_TERRAIN));
	}
}
