using namespace vex;

extern brain Brain;

// VEXcode devices
extern inertial Inertial19;
extern controller Controller1;
extern drivetrain Drivetrain;
extern motor Catapult;
extern motor_group Intake;
extern digital_out Pneumatics;
extern digital_out PneumaticsB;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );