#include <AccelStepper.h>
#include <MultiStepper.h>

#define HALFSTEP 8

#define motorPin2  2
#define motorPin3  3     
#define motorPin4  4     
#define motorPin5  5    

#define motorPin6  6     
#define motorPin7  7     
#define motorPin8  8     
#define motorPin9  9     

#define motorPin10 10     
#define motorPin11 11    
#define motorPin12 12   
#define motorPin13 13

AccelStepper stepper1(HALFSTEP, motorPin2, motorPin4, motorPin3, motorPin5);
AccelStepper stepper2(HALFSTEP, motorPin6, motorPin8, motorPin7, motorPin9);
AccelStepper stepper3(HALFSTEP, motorPin10, motorPin12, motorPin11, motorPin13);

void setup() {
  stepper1.setMaxSpeed(1000.0);
  stepper1.setAcceleration(100.0);
  stepper1.setSpeed(200);
  stepper1.moveTo(20000);
  stepper2.setMaxSpeed(1000.0);
  stepper2.setAcceleration(100.0);
  stepper2.setSpeed(200);
  stepper2.moveTo(20000);
  stepper3.setMaxSpeed(1000.0);
  stepper3.setAcceleration(100.0);
  stepper3.setSpeed(200);
  stepper3.moveTo(20000);
}

void loop() {
  if (stepper1.distanceToGo() == 0) {
    stepper1.moveTo(-stepper1.currentPosition());
  }

  if (stepper2.distanceToGo() == 0){
    stepper2.moveTo(-stepper2.currentPosition());
  }

  if (stepper3.distanceToGo() == 0){
    stepper3.moveTo(-stepper3.currentPosition());
  }
  stepper1.run();
  stepper2.run();
  stepper3.run();
}
