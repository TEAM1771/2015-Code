/*
 * OmniDriveTrain.cpp
 *
 *  Created on: Feb 8, 2015
 *      Author: Yeshy
 */

#include "OmniDriveTrain.h"
#include "RobotMap.h"
#include "WPILib.h"

OmniDriveTrain::OmniDriveTrain():
	l_motor(CAN_LEFT_MOTOR),
	r_motor(CAN_RIGHT_MOTOR)
{
	l_motor.ConfigNeutralMode(CANTalon::kNeutralMode_Coast);
	r_motor.ConfigNeutralMode(CANTalon::kNeutralMode_Coast);
}
void OmniDriveTrain::TankDrive(float lYAxis, float rYAxis)
{
	l_motor.Set(-lYAxis);
	r_motor.Set(rYAxis);
}
