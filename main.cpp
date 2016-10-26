#include "mbed.h"
#include "AVEncoder.h"
#include "pinouts.h"
#include "PID/pidConstants.h"

DigitalOut myled(LED1);
DigitalIn mybutton(USER_BUTTON);

//RNG from https://developer.mbed.org/questions/61158/Random-number-in-C/
AnalogIn rng_read (RNG_SEED);

// Controllers for left and right encoders
AVEncoder LeftEncoder(L_ENCODER_A, L_ENCODER_B);
AVEncoder RightEncoder(R_ENCODER_A, R_ENCODER_B);

// Controllers for right motor
PwmOut RMotorReverse(R_MOTOR_REVERSE);
PwmOut RMotorForward(R_MOTOR_FORWARD);

// Controllers for left motor
PwmOut LMotorForward(L_MOTOR_FORWARD);
PwmOut LMotorReverse(L_MOTOR_REVERSE);


int main()
{
    //Change the timings to get this to work (and/or the speeds)
    //Change these numbers to affect speed
    //The numbers range from 0 to .5
    RMotorForward = .5;
    LMotorForward = .5;

    // delay is in MS
    delay(1000);

    LMotorForward = 0;

    delay(800); 
    LMotorForward = .5;

    delay(500);

    RMotorForward = 0;

    delay(800);

    RMotorForward = .5;

    delay(500);

    RMotorForward = .0;

    delay(1600);
}