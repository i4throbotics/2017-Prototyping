#ifndef Intake_H
#define Intake_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Intake: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<SpeedController> Lift;
	std::shared_ptr<CANTalon> Wheels;
	std::shared_ptr<Encoder> LiftEncoder;
	bool BallHeld;
public:
	Intake();
	void InitDefaultCommand();

	void Up(double s);
	void Down(double s);
	void In(double s);
	void Out(double s);

	double GetEncoder();

	bool GetBallHeld();
	void SetBallHeld(bool held);
};

#endif
