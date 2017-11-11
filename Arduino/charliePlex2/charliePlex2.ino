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

int pins[4] = {2, 3, 4, 5};
int numPins = 4;

// the LED ordering
int LED[12][2] = {
  {2, 3}, {2, 4}, {2, 5},
  {3, 2}, {3, 4}, {3, 5},
  {4, 2}, {4, 3}, {4, 5},
  {5, 2}, {5, 3}, {5, 4}
};
int numLED = 12;

int DELAY = 600;

void setup() {
  // put your setup code here, to run once:
  for (int x = 0; x < numPins; x++) {
    pinMode(pins[x], INPUT);
  }
}

void loop() {
  // safety reasons yo
  reset();
  
  for (int x = 0; x < numLED; x ++) {
    turnOn(LED[x][0], LED[x][1]);      
  }
}

/* reset turns all inputs into INPUT mode, called before 
 *  lighting up any other LEDs
 */
void reset() {
  for (int x = 0; x < numPins; x++) {
    pinMode(pins[x], INPUT); // set to input
  }
}

/* turnOn turns on the LED specified by the xy ordering
 *  given in the description above.
 */
void turnOn(int x, int y) {
  // output mode
  pinMode(pins[x], OUTPUT);
  pinMode(pins[y], OUTPUT);

  // turn LEDs on
  digitalWrite(pins[x], HIGH);
  digitalWrite(pins[y], LOW);

  // wait
  delay(DELAY);

  // turn LEDs off
  pinMode(pins[x], INPUT);
  pinMode(pins[y], INPUT);
}

