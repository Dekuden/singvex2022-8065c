/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                          ry                                                  */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// piston               digital_out   H               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

motor leftfront = motor(PORT19,gearSetting::ratio18_1,false);
motor leftback = motor(PORT20,gearSetting::ratio18_1,false);
motor rightfront = motor(PORT9,gearSetting::ratio18_1,true);
motor rightback = motor(PORT10,gearSetting::ratio18_1,true);

motor topfly = motor(PORT5,gearSetting::ratio18_1,false);
motor botfly = motor(PORT6,gearSetting::ratio18_1,false);
motor topintake = motor(PORT1,gearSetting::ratio18_1, false);
motor botintake = motor(PORT2,gearSetting::ratio18_1,true);
brain Brain;
controller H = controller(primary);
controller V = controller(partner);

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {

  
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    rightfront.spin(vex::directionType::fwd, H.Axis2.value(),vex::velocityUnits::pct);
    leftfront.spin(vex::directionType::fwd, H.Axis3.value(),vex::velocityUnits::pct);
    rightback.spin(vex::directionType::fwd, H.Axis2.value(),vex::velocityUnits::pct);
    leftback.spin(vex::directionType::fwd, H.Axis3.value(),vex::velocityUnits::pct);

    topintake.spin(directionType::fwd,V.Axis2.value(),velocityUnits::pct);
    botintake.spin(directionType::fwd,V.Axis2.value(),velocityUnits::pct);

    if(V.ButtonL2.pressing()==1)
    {
      topfly.spin(directionType::fwd,12,voltageUnits::volt);
      botfly.spin(directionType::fwd,12,voltageUnits::volt);
    }

    else if(V.ButtonL1.pressing()==1)
    {
      topfly.spin(directionType::fwd,9,voltageUnits::volt);
      botfly.spin(directionType::fwd,9,voltageUnits::volt);
    }
    
    else
    {
      topfly.spin(directionType::fwd,0,voltageUnits::volt);
      botfly.spin(directionType::fwd,0,voltageUnits::volt);
    }

    if(V.ButtonR1.pressing()==1)
    {
      DigitalOutH.set(true);
    }

    else
    {
      DigitalOutH.set(false);
    }

    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystik values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
