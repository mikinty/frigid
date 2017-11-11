// variables
int led = 2;
int reader = 7;
int n ;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(7, INPUT);
  Serial.begin(9600);
  n = 1000;
}

void loop() {
  if (Serial.available()) {
    char val = Serial.read();
    
    if (val == '1') {
      Serial.print('fast\n');
      n = 200;
    } else {
      n = 1000;
    }
  }
  
  if(digitalRead(reader) == HIGH) {
    Serial.print('COOL!\n');
  }
  
  digitalWrite(led, HIGH);
  delay(n);
  digitalWrite(led, LOW);
  delay(n);
}
