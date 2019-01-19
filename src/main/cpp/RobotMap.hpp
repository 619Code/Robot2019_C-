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
    const int RAMP_RATE = 0.1;
};