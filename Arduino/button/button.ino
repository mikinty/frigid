int ledPin = 7; // choose the pin for the LED
int inPin = 6;   // choose the input pin (for a pushbutton)
int val = 0;     // variable for reading the pin status
int rereshRate = 50; // so our arduino doesn't spam our input


void setup() {
  pinMode(ledPin, OUTPUT);  // declare LED as output
  pinMode(inPin, INPUT);    // declare pushbutton as input
  Serial.begin(9600);
}

void loop(){
  val = digitalRead(inPin);  // read input value
  if (val == LOW) {         // button not pressed
    digitalWrite(ledPin, LOW);  // turn LED OFF
  } else {
    Serial.print("COOL!");
    Serial.println();
    digitalWrite(ledPin, HIGH);  // turn LED ON
  }
  
  delay(200);
}

