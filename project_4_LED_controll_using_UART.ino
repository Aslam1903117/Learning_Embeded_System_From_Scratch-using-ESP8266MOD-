  
const int ledPin = 0;  // GPIO 0 (D3 on NodeMCU)
String command = "";

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);  
  Serial.begin(115200);       // UART at 115200 baud
  Serial.println("UART LED Control Ready");
  Serial.println("Type 'ON' or 'OFF' to control LED");
}

void loop() {
  if (Serial.available() > 0) {
    char incomingChar = Serial.read();
    if (incomingChar == '\n') {  
      processCommand(command);
      command = "";
    } else {
      command += incomingChar;  
    }
  }
}

void processCommand(String cmd) {
  cmd.trim();
  if (cmd.equalsIgnoreCase("ON")) {
    digitalWrite(ledPin, HIGH);
    Serial.println("LED is ON");
  } else if (cmd.equalsIgnoreCase("OFF")) {
    digitalWrite(ledPin, LOW);
    Serial.println("LED is OFF");
  } else {
    Serial.println("Unknown command. Use 'ON' or 'OFF'");
  }
}