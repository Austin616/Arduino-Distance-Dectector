#include <LiquidCrystal.h>

// Define the LCD pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// Define ultrasonic sensor pins
const int trigPin = A0;
const int echoPin = A1;

// Define active buzzer pin
const int buzzerPin = 1;

// Define LED pins
const int ledPin5 = 5;
const int ledPin4 = 4;
const int ledPin3 = 3;
const int ledPin2 = 2;

void setup() {
  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.print("Ultrasonic Sensor");
  lcd.setCursor(0, 1);
  lcd.print("Distance: ");
  delay(2000);
  lcd.clear();

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  // Set up LED pins as OUTPUT
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  // Trigger ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pulse duration and calculate distance in inches
  int duration = pulseIn(echoPin, HIGH);
  float distanceInches = duration * 0.0133 / 2;  // Speed of sound is approximately 0.0133 inches/microsecond

  // Display distance on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distanceInches);
  lcd.print(" inches");

  // Check distance and control buzzer and lights
  if (distanceInches < 6.0) {
    // Something is within 6 inches, activate buzzer and lights
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin2, HIGH);
  } else {
    // Clear buzzer and lights
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin2, LOW);
  }

  delay(500); // Add a small delay for stability
  // Turn off the buzzer to create a lower pitched sound
  digitalWrite(buzzerPin, LOW);
}
