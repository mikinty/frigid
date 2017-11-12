// vars
int groups[4][3] = {
  {2, 3, 4},
  {5, 6, 7},
  {8, 9, 10},
  {11, 12, 13}
};

int iter1 = 0;
int iter2 = 0;

int wait = 2000;

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
  // put your main code here, to run repeatedly:
  if (iter1 > 2) {
    iter1 = 0;
  }

  if (iter2 > 3) {
    iter2 = 0;
  }

  // turn on group
  for (int y = 0; y < 4; y ++) {
    digitalWrite(groups[y][iter1], HIGH);
  }
  Serial.print(iter1);
  Serial.println();
  delay(wait); 
  
  reset();
  iter1++;
  iter2++;
}

void reset() {
  for (int x=2; x<14; x++){
    digitalWrite(x, LOW);
  }
}


