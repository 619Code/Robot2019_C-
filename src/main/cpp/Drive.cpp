/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Drive.h"
#include "RobotMap.hpp"
#include "rev/CANSparkMax.h"
#include <frc/Joystick.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include "RobotMap.hpp"

using namespace frc;
using namespace rev;

CANSparkMax leftMotorFront{RobotMap::Get().LEFT_FRONT, CANSparkMax::MotorType::kBrushless};
CANSparkMax leftMotorMiddle{RobotMap::Get().LEFT_MIDDLE, CANSparkMax::MotorType::kBrushless};
CANSparkMax leftMotorRear{RobotMap::Get().LEFT_REAR, CANSparkMax::MotorType::kBrushless};

CANSparkMax rightMotorFront{RobotMap::Get().RIGHT_FRONT, CANSparkMax::MotorType::kBrushless};
CANSparkMax rightMotorMiddle{RobotMap::Get().RIGHT_MIDDLE, CANSparkMax::MotorType::kBrushless};
CANSparkMax rightMotorRear{RobotMap::Get().RIGHT_REAR, CANSparkMax::MotorType::kBrushless};

DifferentialDrive robotDrive{leftMotorMiddle, rightMotorMiddle};

Drive::Drive() : Subsystem("Drive") {
  robotDrive.SetMaxOutput(RobotMap::Get().SPEED_MAX);
  initSparkMax();
}

void Drive::initSparkMax()
{
  leftMotorMiddle.SetRampRate(RobotMap::Get().RAMP_RATE);
  leftMotorMiddle.SetIdleMode(CANSparkMax::IdleMode::kCoast);
  leftMotorRear.Follow(leftMotorMiddle);
  leftMotorFront.Follow(leftMotorMiddle);

  rightMotorMiddle.SetRampRate(RobotMap::Get().RAMP_RATE);
  rightMotorMiddle.SetIdleMode(CANSparkMax::IdleMode::kCoast);
  rightMotorRear.Follow(rightMotorMiddle);
  rightMotorFront.Follow(rightMotorMiddle);
}

double Drive::deadzone(double input)
{
   return std::abs(input) > 0.07 ? std::abs(input)*input : 0; 
}

void Drive::defaultDrive(double speed, double rot)
{
  double speedActual = deadzone(speed);
  double rotActual = -deadzone(rot*RobotMap::Get().ROT_MAX);
  robotDrive.CurvatureDrive(speedActual, rotActual, true);
}

void Drive::InitDefaultCommand() {}

