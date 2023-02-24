/*
Code Name:Distance Measuring using Ultrasonic sensor
Author: ammarece
Description: This program is used for Measuring using Ultrasonic sensor on Arduino 
License: Remixing or Changing this Thing is allowed. Commercial use is not allowed.
*/
#define trigPin 9     // Ultrasonic sensor trigger pin
#define echoPin 10    // Ultrasonic sensor echo pin

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read ultrasonic echo and calculate distance
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;  // Convert duration to distance in cm

  // Print distance on serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(1000);  // Wait for 1 second before measuring again
}
