/*
 * Accumulator.h
 *
 *  Created on: Feb 10, 2015
 *      Author: Yeshy
 */
#ifndef SRC_ACCUMULATOR_H_
#define SRC_ACCUMULATOR_H_


#include "WPILib.h"

class Accumulator{
	private:

	public:
		CANTalon l_roller;//because no one likes plural nouns.
		CANTalon r_roller;



		Accumulator(int lRollerID, int rRollerID); //this is the accumulator thingy


		/*
		 * IMPORTANT!!!!!!!
		 * place the following functions within an if statement
		 * 	While the button is held, the given motors will rotate
		 * 	One has to rotate counterclockwise to the other
		 */
		void rollLeftIn(float speed);
		void rollLeftOut(float speed);

		void rollRightIn(float speed);
		void rollRightOut(float speed);

		void toteIn(float speed);//function which takes in tote
		void toteOut(float speed);//function which pushes out tote
};

#endif /* SRC_ACCUMULATOR_H_ */
