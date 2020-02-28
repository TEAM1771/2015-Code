/*
 * OmniDriveTrain.h
 *
 *  Created on: Feb 8, 2015
 *      Author: Yeshy
 */

#ifndef SRC_OMNIDRIVETRAIN_H_
#define SRC_OMNIDRIVETRAIN_H_

#include "WPILib.h"

class OmniDriveTrain {
private:

public:
	CANTalon l_motor;
	CANTalon r_motor;

	OmniDriveTrain();
	void TankDrive(float lYAxis, float rYAxis);
};



#endif /* SRC_OMNIDRIVETRAIN_H_ */
