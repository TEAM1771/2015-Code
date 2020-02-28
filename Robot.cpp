#include "WPILib.h"
#include <math.h>

#include "OmniDriveTrain.h"
#include "Elevator.h"
#include "Accumulator.h"
#include "RobotMap.h"
#include "IMU.h"
#include "IMUAdvanced.h"
#include "AHRS.h"


class Robot: public SampleRobot
{
	OmniDriveTrain ODT;//look at header files.
	Elevator toteMover;
	Accumulator toteGrabber;
	Elevator toteStacker;
	Elevator canMover;

	Joystick l_stick;
	Joystick r_stick;
	Joystick c_stick; //smash moves for the totes
	Solenoid ArmWheels;
	Solenoid TheDrawBridgeOfDeath;
	PowerDistributionPanel PDP;
	float rollerSpeed;
	float elevatorSpeed;
	float throttle;
	float motorStall;
	float Encoderval;
	bool NotAtRobotPos;
	bool NotAtStackPos;
	bool StayDown;
	bool Auto;
	float Pos;
	float Pos4StackTop;
	float Pos4StackBot;
	unsigned int brightness = 16;
public:
	Robot() :
			ODT(), //make sure these values match...
			toteMover(CAN_ELEVATOR_MOTOR,DIGITAL_ROBOT_LIFTA,DIGITAL_ROBOT_LIFTB),
			toteGrabber(CAN_LEFT_GRABBER_MOTOR,CAN_RIGHT_GRABBER_MOTOR),
			toteStacker(CAN_ONLY_STACKER_MOTOR,DIGITAL_STACKER_LIFTA,DIGITAL_STACKER_LIFTB),
			canMover(CAN_CAN_MOTOR,DIGITAL_CAN_LIFTA,DIGITAL_CAN_LIFTB),
			l_stick(0),
			r_stick(1),
			c_stick(2),
			ArmWheels(0),
			TheDrawBridgeOfDeath(1),
			PDP()

	{

		NotAtRobotPos=false;
		NotAtStackPos=false;
		rollerSpeed = 1;
		elevatorSpeed = 0.5;
		throttle = 1;
		motorStall = 0.1;
		StayDown = false;
		TheDrawBridgeOfDeath.Set(0);
		//toteStacker.eleMotor.SetVoltageRampRate(120);

	}


	void Autonomous()
	{
		while(1)
		SmartDashboard::PutNumber("DB/Slider 1",toteStacker.ArmInCoder.Get());

	}


	void OperatorControl()
	{
		NotAtStackPos=0;
		while (IsOperatorControl() && IsEnabled())
		{
/*
 * *********************************************************************************************
 * DRIVE TRAIN
 * *********************************************************************************************
 */

				ODT.TankDrive(l_stick.GetY(), r_stick.GetY());
/*
 * ********************************************************************************************
 * ELEVATOR STUFF
 * ********************************************************************************************
 */

//robot
			Encoderval=toteMover.ArmInCoder.Get();
			SmartDashboard::PutNumber("DB/Slider 3",PDP.GetCurrent(13));
			if(l_stick.GetRawButton(6))
			{
				Pos = POS_PICK_UP;
				NotAtRobotPos=true;
			}
			else if(r_stick.GetRawButton(11))
			{
				Pos = POS_DROP_IT;
				NotAtRobotPos=true;
			}
			else if(r_stick.GetRawButton(9))
			{
				Pos = POS_COOP_IT;
				NotAtRobotPos=true;
			}


			SmartDashboard::PutNumber("DB/Slider 2",Pos);
//stacker
			if(c_stick.GetRawButton(1))
			{
				Pos4StackTop=POS_TOP;
				Pos4StackBot=POS_MID;
				NotAtStackPos = true;
				StayDown = false;
				TheDrawBridgeOfDeath.Set(0);
				if(!toteStacker.FirstIt)
				{
					toteStacker.LastIt = false;
					toteStacker.FirstIt = true;
				}
			}
			if(c_stick.GetRawButton(2)){
							NotAtStackPos = true;
							StayDown = true;
							TheDrawBridgeOfDeath.Set(1);
							Pos4StackBot=POS_BOT;
			}

			if(NotAtStackPos&&!StayDown)
			{
				//toteStacker.liftToPos(Pos4StackBot);
				toteStacker.Stack(Pos4StackTop,Pos4StackBot);
			}
			else if(StayDown)
			{
				toteStacker.liftToPos(Pos4StackBot);
			}
			if(NotAtRobotPos)
			{
				toteMover.liftToPos(Pos);
			}

//can mover

/*
 * ********************************************************************************************
 * ACCUMULATOR STUFF
 * ********************************************************************************************
 */
			//for the rollers
			if(c_stick.GetRawButton(8))
			{
				toteGrabber.rollLeftIn(rollerSpeed);
				toteGrabber.rollRightIn(rollerSpeed);
				ArmWheels.Set(1);
			}
			else if(c_stick.GetRawButton(7))
			{
				toteGrabber.rollLeftIn(-rollerSpeed);
				toteGrabber.rollRightIn(-rollerSpeed);
				ArmWheels.Set(1);
			}
			else
			{
				toteGrabber.rollLeftIn(.1);
				toteGrabber.rollRightIn(.1);
				ArmWheels.Set(0);
			}

			Wait(0.005);// wait for a motor update time
		}
	}

	/**
	 * Runs during test mode
	 */
	void Test()//hello world im pointless!
	{

	}
};

START_ROBOT_CLASS(Robot);
