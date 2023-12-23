/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Inertial19           inertial      19              
// Controller1          controller                    
// Drivetrain           drivetrain    1, 11, 10, 20   
// Catapult             motor         13              
// Intake               motor_group   3, 9            
// Pneumatics           digital_out   A               
// PneumaticsB          digital_out   B               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

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
  //Inertial Code
  Inertial19.calibrate();
    // waits for the Inertial Sensor to calibrate
  while (Inertial19.isCalibrating()) {
    wait(100, msec);
  
  }
  
  
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
  Drivetrain.setDriveVelocity(50, percent);
  Drivetrain.setTurnVelocity(50, percent);
  Catapult.setVelocity(80, percent);
 /* // Turns the robot to the right
  Drivetrain.turn(right);
  // Waits until the motor reaches a 90 degree turn and stops the Left and
  // Right Motors.
  waitUntil((Inertial19.rotation(degrees) >= 90));
  Drivetrain.stop();

  // Turns the robot to the left
  Drivetrain.turn(left);
  //Waits until the motor reached a 90 degree turn and stops the drivetrain
  waitUntil((Inertial19.rotation(degrees) >= 90));
  Drivetrain.stop();
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  waitUntil((Inertial19.rotation(degrees) >= 90));*/
  
  
  //Skills Auton Code
  Drivetrain.driveFor(reverse, 60,inches);
  //Come to Cata Position
  Drivetrain.driveFor (forward, 25, inches);
  Drivetrain.turn(right);
  waitUntil((Inertial19.rotation(degrees) >= 90));
  Drivetrain.driveFor(forward, 15, inches);
  Catapult.spinFor(forward, 5,turns);
  Drivetrain.driveFor(reverse, 10, inches);
  //Working until here, DO NOT TOUCH
  Drivetrain.turn(left);
  //Waits until the motor reached a 90 degree turn and stops the drivetrain
  waitUntil((Inertial19.rotation(degrees) >= 90));
  
  Drivetrain.driveFor(reverse, 15, inches);
  

  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
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
  Drivetrain.setDriveVelocity(100, percent);
  Drivetrain.setTurnVelocity(100, percent);
  Intake.setVelocity(100, percent);
  Catapult.setVelocity(80, percent);
  // User control code here, inside the loop
  while (1) {
       //Pneumatics code:
  if(Controller1.ButtonX.pressing()){
    Pneumatics.set(false);
    PneumaticsB.set(false);
  }
 if(Controller1.ButtonB.pressing()){
    Pneumatics.set(true);
    PneumaticsB.set(true);
   }
  

    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}
/*bool cata_on = true;

void cata_off (void) {
cata_on = false;
}

void cata_on (void) {
cata_on = true;
}*/
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
