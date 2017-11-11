/*
 * README!
 * 
 * LED Ordering (use 0-index in code):
 * 12
 * 13
 * 14
 * 21
 * 23
 * 24
 * 31
 * 32
 * 34
 * 41
 * 42
 * 43
 * 
 */

int pins = {2, 3, 4, 5};
int numPins = 4;

// the LED ordering
int LED = {
  {2, 3}, {2, 4}, {2, 5},
  {3, 2}, {3, 4}, {3, 5},
  {4, 2}, {4, 3}, {4, 5},
  {5, 2}, {5, 3}, {5, 4}
};

void setup() {
  // put your setup code here, to run once:
  for (int x = 0; x < numPins; x++) {
    pinMode(pins[x], INPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  delay(500);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  delay(500);
}

/* reset turns all inputs into INPUT mode, called before 
 *  lighting up any other LEDs
 */
void reset() {
  for (int x = 0; x < numPins; x++) {
    digitalWrite(pins[x], INPUT); // set to input
  }
}

/* turnOn turns on the LED specified by the xy ordering
 *  given in the description above.
 */
void turnOn(x, y) {
  digitalWrite(pins[x], HIGH);
  digitalWrite(pins[y], LOW);
}

