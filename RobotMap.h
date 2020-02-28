#ifndef ROBOT_MAP_H_
#define ROBOT_MAP_H_

//assinged names for CAN
#define CAN_LEFT_MOTOR 2//left wheel
#define CAN_RIGHT_MOTOR 1//right wheel
#define CAN_CAN_MOTOR 4 //can motor
#define CAN_ELEVATOR_MOTOR 3
#define CAN_LEFT_GRABBER_MOTOR 5
#define CAN_ONLY_STACKER_MOTOR 6
#define CAN_RIGHT_GRABBER_MOTOR 7

//assigned solenid ports
#define SOLENOID_HINGE 0
#define SOLENOID_ARM 1

//assigned analog ports
#define ANALOG_GYRO 0

//assigned digital ports
#define DIGITAL_ROBOT_LIFTA 0
#define DIGITAL_ROBOT_LIFTB 1
#define DIGITAL_STACKER_LIFTA 2
#define DIGITAL_STACKER_LIFTB 3
#define DIGITAL_RIGHT_DRIVEA 4
#define DIGITAL_CAN_LIFTA 5
#define DIGITAL_CAN_LIFTB 6
#define DIGITAL_RIGHT_DRIVEB 7
#define DIGITAL_LEFT_DRIVEA 8
#define DIGITAL_LEFT_DRIVEB 9
#define DIGITAL_MIDDLE_DRIVEA 10
#define DIGITAL_MIDDLE_DRIVEB 11

//Posisions for elevators
#define POS_PICK_UP 15
#define POS_DROP_IT 90
#define POS_COOP_IT 235
#define POS_TOP 100
#define POS_MID 945
#define POS_BOT 1120

#endif // ROBOT_MAP_H_
