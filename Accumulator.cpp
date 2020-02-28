/*
 * Accumulator.cpp
 *
 *  Created on: Feb 10, 2015
 *      Author: Yeshy
 */

#include "Accumulator.h"

#include "WPILib.h"


Accumulator::Accumulator(int lRollerID, int rRollerID):
	l_roller(lRollerID),
	r_roller(rRollerID)
{

}

void Accumulator::rollLeftIn(float speed) //negative value needed in main Robot.cpp file
{
	l_roller.Set(-speed);
}

void Accumulator::rollLeftOut(float speed)
{
	l_roller.Set(speed);
}

void Accumulator::rollRightIn(float speed)
{
	r_roller.Set(speed);
}

void Accumulator::rollRightOut(float speed)
{
	r_roller.Set(-speed);
}


void Accumulator::toteIn(float speed)
{
	this->rollLeftIn(speed);
	this->rollRightIn(speed);
}

void Accumulator::toteOut(float speed)
{
	this->rollLeftOut(speed);
	this->rollRightOut(speed);
}


