const int ledPin = 10; // GPIO2 (pin 17 on ESP-12F)

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {

  digitalWrite(ledPin, HIGH); // Turn LED on
  delay(100);              // Wait 1 second
  digitalWrite(ledPin, LOW);  // Turn LED off
  delay(100);              // Wait 1 second
}