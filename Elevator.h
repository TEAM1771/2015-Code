/*
 * Elevator.h
 *
 *  Created on: Feb 13, 2015
 *      Author: Yeshy
 */

#ifndef SRC_ELEVATOR_H_
#define SRC_ELEVATOR_H_

#include "WPILib.h"
#include <math.h>

class Elevator
{
public:
	CANTalon eleMotor;//motor which controls the movement of the elevator
	Encoder ArmInCoder;
	Timer TimeKeeper;
	bool FirstIt;
	bool LastIt;
	float posy;

	Elevator(int eleMotorID, int EncoderA, int EncoderB);//Elevator initializer
	void driveElevator(float movementValue);//manual-drive for elevator: Uses a 3rd joystick
	void liftToPos(float pos);//go to posision
	void Stack(float intpos,float wantpos);//stack a tote


};



#endif /* SRC_ELEVATOR_H_ */
