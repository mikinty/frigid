// vars
int groups[4][3] = {
  {2, 3, 4},
  {5, 6, 7},
  {8, 9, 10},
  {11, 12, 13}
};

int iter = 2;

int wait = 500;

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
  if (iter > 13) {
    iter = 2;
  }
  
  digitalWrite(iter, HIGH);
  delay(wait); 
  
  Serial.print(iter);
  Serial.println();
  
  reset();
  iter++;
}

void reset() {
  for (int x=2; x<14; x++){
    digitalWrite(x, LOW);
  }
}


