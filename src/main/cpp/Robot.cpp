/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"
#include "RobotMap.hpp"
#include "rev/CANSparkMax.h"

#include <iostream>
#include <vector>

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Joystick.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>

using namespace frc;
using namespace rev;

CANSparkMax leftMotorFront{RobotMap::Get().LEFT_FRONT, CANSparkMax::MotorType::kBrushless};
CANSparkMax leftMotorMiddle{RobotMap::Get().LEFT_MIDDLE, CANSparkMax::MotorType::kBrushless};
CANSparkMax leftMotorRear{RobotMap::Get().LEFT_REAR, CANSparkMax::MotorType::kBrushless};

CANSparkMax rightMotorFront{RobotMap::Get().RIGHT_FRONT, CANSparkMax::MotorType::kBrushless};
CANSparkMax rightMotorMiddle{RobotMap::Get().RIGHT_MIDDLE, CANSparkMax::MotorType::kBrushless};
CANSparkMax rightMotorRear{RobotMap::Get().RIGHT_REAR, CANSparkMax::MotorType::kBrushless};

DifferentialDrive robotDrive{leftMotorMiddle, rightMotorMiddle};

Joystick jstick{0};

void initSparkMax()
{
  leftMotorMiddle.SetRampRate(RobotMap::Get().RAMP_RATE);
  leftMotorMiddle.SetIdleMode(CANSparkMax::IdleMode::kBrake);
  leftMotorRear.Follow(leftMotorMiddle);
  leftMotorFront.Follow(leftMotorMiddle);

  rightMotorMiddle.SetRampRate(RobotMap::Get().RAMP_RATE);
  rightMotorMiddle.SetIdleMode(CANSparkMax::IdleMode::kBrake);
  rightMotorRear.Follow(rightMotorMiddle);
  rightMotorFront.Follow(rightMotorMiddle);
}

void Robot::RobotInit() 
{
  initSparkMax();
  robotDrive.SetMaxOutput(0.7);
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() 
{

}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() 
{

}

void Robot::AutonomousPeriodic() 
{

}

void Robot::TeleopInit() {}

double deadzone(double deadzone)
{
  return std::abs(deadzone) > 0.07 ? std::abs(deadzone)*deadzone : 0; 
}

void Robot::TeleopPeriodic() 
{
  robotDrive.CurvatureDrive(deadzone(jstick.GetRawAxis(1)), -deadzone(jstick.GetRawAxis(4)*0.5), true);
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
