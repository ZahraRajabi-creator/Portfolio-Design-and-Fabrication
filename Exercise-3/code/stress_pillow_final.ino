const int pumpInflate = 5;
const int pumpDeflate = 8;
const int valvePin = 10;

const int fsrPin = A0;
const int buttonPin = 2;

const int threshold = 200;

void setup() {

  pinMode(pumpInflate, OUTPUT);
  pinMode(pumpDeflate, OUTPUT);
  pinMode(valvePin, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);

  digitalWrite(pumpInflate, LOW);
  digitalWrite(pumpDeflate, LOW);
  digitalWrite(valvePin, LOW);

  Serial.begin(9600);
}

void loop() {

  int fsrValue = analogRead(fsrPin);
  int buttonValue = digitalRead(buttonPin);

  //Serial.println(fsrValue);
  Serial.println(buttonValue);
  

  // Button pressed -> deflate
  if (digitalRead(buttonPin) == LOW) {

    digitalWrite(pumpInflate, LOW);

    digitalWrite(valvePin, LOW);

    digitalWrite(pumpDeflate, HIGH);
  }

  // FSR pressed -> inflate
  else if (fsrValue > threshold) {

    digitalWrite(pumpDeflate, LOW);

    digitalWrite(valvePin, HIGH);

    digitalWrite(pumpInflate, HIGH);
  }

  // Nothing pressed
  else {

    digitalWrite(pumpInflate, LOW);
    digitalWrite(pumpDeflate, LOW);
  }

  delay(100);
}
