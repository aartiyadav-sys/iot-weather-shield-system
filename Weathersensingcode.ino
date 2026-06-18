#include <Servo.h>

Servo myservo;

// Pin definitions
const int servoPin = 9;   // Servo signal
const int rainPin  = 7;   // Rain sensor digital output

void setup() {
  myservo.attach(servoPin);
  pinMode(rainPin, INPUT);

  myservo.write(0);       // Initial position (no rain)
  Serial.begin(9600);
}

void loop() {
  int rainValue = digitalRead(rainPin);

  if (rainValue == LOW) {
    // Rain detected
    Serial.println("Rain Detected - Servo at 90 degree");
    myservo.write(90);    // Collect clothes
    delay(1000);
  } 
  else {
    // No rain
    Serial.println("No Rain - Servo at 0 degree");
    myservo.write(0);     // Normal position
    delay(1000);
  }
}
 