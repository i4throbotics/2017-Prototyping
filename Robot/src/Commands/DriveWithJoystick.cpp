

#include "DriveWithJoystick.h"


DriveWithJoystick::DriveWithJoystick(): Command() {
	Requires(Robot::chassis.get());


}


void DriveWithJoystick::Initialize() {
	time.Start();
}

void DriveWithJoystick::Execute() {
		Robot::chassis->Drive();



}

bool DriveWithJoystick::IsFinished() {
    return false;
}

void DriveWithJoystick::End() {

}

void DriveWithJoystick::Interrupted() {

}
