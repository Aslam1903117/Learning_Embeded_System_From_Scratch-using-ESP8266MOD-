//defining pin 
const int ledPin = 5;   
const int buttonPin = 4; 

//volatine for interrupt use
volatile int ledState = LOW;

// Declaration of INterruot service routine
void ICACHE_RAM_ATTR buttonISR();



void setup() {
 //pin mode setup
 pinMode(ledPin, OUTPUT);
 pinMode(buttonPin, INPUT_PULLUP);
 digitalWrite(ledPin, ledState);

 // attach interrupt to button pin
  attachInterrupt (digitalPinToInterrupt(buttonPin),buttonISR, FALLING);
  Serial.begin(115200);
  Serial.println("Set up complete ,Ready for Button press");



}

void loop() {
 //Empty cause interrupt handles everything

}

// Interrupt service routine
void ICACHE_RAM_ATTR buttonISR()
{
  static unsigned long lastInterruptTime =0;
  unsigned long interruptTime=millis();

  //Debounce: Ignore interrupts within 200ms of the last one
  if((interruptTime-lastInterruptTime)>200)
  {
    ledState = !ledState;
    digitalWrite(ledPin , ledState);
    Serial.println(ledState == HIGH ? "LED ON" : "LED OFF");
  }
  lastInterruptTime= interruptTime;
}
