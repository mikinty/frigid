#include <TimeLib.h>
#include <Time.h>

void setup() {
  Serial.begin(9600);
  setTime(12, 0, 0, 1, 1, 11);
}

void loop() {
  Serial.print('sending a message');
  Serial.print(hour());
  printDigits(minute());
  
  Serial.println();
  delay(1000);
}

void printDigits(int digits) {
  Serial.print(':');
  if (digits < 10) {
    Serial.print('0');
  }
  
  Serial.print(digits);
}
