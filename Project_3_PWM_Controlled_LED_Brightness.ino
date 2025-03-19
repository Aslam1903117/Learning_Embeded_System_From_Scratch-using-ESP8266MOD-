const int ledPin=5;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  Serial.println("PWM fading started");

}

void loop() {
 for(int brightness=0; brightness<=1023; brightness +=5)
 {
  analogWrite(ledPin, brightness);
  delay(20);
 }
for(int brightness=1023; brightness>=0; brightness -=5)
 {
  analogWrite(ledPin, brightness);
  delay(20);
 }
}
