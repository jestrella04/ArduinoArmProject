#include <Servo.h>
#include <MyCommon.h>

// Instantiate the servo objects
Servo armServo[12];

// Initialize variables
const int armDelayInit = 5000;
const int armDelayExit = 5000;
const int servoMoveDelay = 10;
const int servoStopDelay = 100;
const int servoCount = (sizeof(armServo) / sizeof(*armServo));
const int servoInitialPositionMatrix[servoCount] = {90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90};

void setup()
{
    // Attach servo objects to the Arduino digital ports
    for (int i = 0; i <= servoCount; i++) {
        armServo[i].attach(i);
    }

    // Move Servos to the initial positions
    setInitialPosition();
    
    // Delay before starting the loop
    delay(armDelayInit);
}

void loop()
{
    for (int i = 0; i <= servoCount; i++) {
        // Base positions: 0, 4, 8
        // Horizontal drive positions: 1, 5, 9
        // Vertical drive positions: 2, 6, 10
        // Gripper positions: 3, 7, 11
        
        // Hardcoded for now
        int servoPos = 30;

        // Move the servo
        armServoMove(armServo[i], servoPos);
    }

    // Move servos back to initial position
    setInitialPosition();
    
    // Delay before entering the loop again
    delay(armDelayExit);
}

void setInitialPosition()
{
    // Move servos to initial position
    for (int i = 0; i <= servoCount; i++) {
        armServoMove(armServo[i], servoInitialPositionMatrix[i]);
    }
}

void armServoMove(Servo myServo, int degree)
{
    servoMoveStepFrom(myServo, myServo.read(), degree, servoMoveDelay);
}
