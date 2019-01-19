#include "Singleton.hpp"
class RobotMap : public Singleton<RobotMap>
{
public:
    //CAN IDS
    const int LEFT_FRONT = 10;
    const int LEFT_MIDDLE = 11;
    const int LEFT_REAR = 12;

    const int RIGHT_FRONT = 13;
    const int RIGHT_MIDDLE = 14;
    const int RIGHT_REAR = 15;

    //ramp constant (only works if in coast)
    const double RAMP_RATE = 0.3;

    //drive consts
    const double ROT_MAX = 0.5;
    const double SPEED_MAX = 1.0;

    //controller consts
    const int SPEED_AXIS = 1;
    const int ROT_AXIS = 4;
};