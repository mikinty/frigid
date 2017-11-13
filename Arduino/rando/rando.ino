// vars
int groups[4][3] = {
  {2, 3, 4},
  {5, 6, 7},
  {8, 9, 10},
  {11, 12, 13}
};

int rate = 1000;

void setup() {
  // put your setup code here, to run once:
  for (int x = 2; x < 14; x++) {
    pinMode(x, OUTPUT);
  }

  // turn all the lights off
  for (int x = 2; x < 14; x++) {
    digitalWrite(x, LOW);
  }

  // serial speed
  Serial.begin(9600);
}

void loop() {
  int r;
  
  // turn on group
  for (int y = 0; y < 4; y ++) {
    r = random(0, 3);
    digitalWrite(groups[y][r], HIGH);
  }
  delay(rate);
  reset();  
}

void reset() {
  for (int x=2; x<14; x++){
    digitalWrite(x, LOW);
  }
}

