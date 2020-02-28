/*
 * Elevator.cpp
 *
 *  Created on: Feb 13, 2015
 *      Author: Yeshy
 */

#include "Elevator.h"

#include "WPILib.h"

Elevator::Elevator(int eleMotorID, int EncoderA, int EncoderB):
	eleMotor(eleMotorID),
	ArmInCoder(EncoderA,EncoderB,Encoder::k4X),
	TimeKeeper()
{
	eleMotor.ConfigNeutralMode(CANSpeedController::kNeutralMode_Brake);
	FirstIt = true;
	LastIt = false;
}
void Elevator::driveElevator(float movementValue)
{
	eleMotor.Set(movementValue);
}
void Elevator::liftToPos(float pos)
{
	float Encoderval = float(ArmInCoder.Get());
	if((Encoderval-pos)/30>.3)
	{
		SmartDashboard::PutNumber("DB/Slider 0",.3);
		eleMotor.Set(.3);
	}
	else if((Encoderval-pos)/30<-.65)
	{
		SmartDashboard::PutNumber("DB/Slider 0",-.65);
		eleMotor.Set(-.65);
	}
	else
	{
		SmartDashboard::PutNumber("DB/Slider 0",(Encoderval-pos)/30);
		eleMotor.Set((Encoderval-pos)/30);
	}
}
void Elevator::Stack(float intpos,float wantpos)
{
	if(FirstIt&&!LastIt)
	{
		TimeKeeper.Stop();
		TimeKeeper.Reset();
		TimeKeeper.Start();
		FirstIt = false;
	}
	if(TimeKeeper.Get()<1.5&&!LastIt)
	{
		posy = wantpos;//dad saw an innuendo here hmm
	}
	else if(TimeKeeper.Get()<3 &&!LastIt)
	{
		posy = intpos;
		LastIt = true;
	}
	SmartDashboard::PutNumber("DB/Slider 1",ArmInCoder.Get()+1);
	float Encoderval = float(ArmInCoder.Get());
	eleMotor.Set((Encoderval-posy)/30);
}

