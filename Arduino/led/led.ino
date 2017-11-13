// vars
int groups[4][3] = {
  {2, 3, 4},
  {5, 6, 7},
  {8, 9, 10},
  {11, 12, 13}
};

int left = 0;

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

  // turn on specific lights
  digitalWrite(groups[0][0], HIGH);
  digitalWrite(groups[1][1], HIGH);
  digitalWrite(groups[2][0], HIGH);
  digitalWrite(groups[3][2], HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:asdf
  if (Serial.available()) {
    char val = Serial.read();

    digitalWrite(groups[1][1], LOW);
    left = 4; 
  }

  if (left>0) {
    digitalWrite(groups[1][2], HIGH);
    delay(500);
    digitalWrite(groups[1][2], LOW);
    delay(500);
    digitalWrite(groups[1][2], HIGH);
    left--;
  }
}
