//define pin numbers
const int  ledpin =5;
const int buttonpin=4;

//VARIABLE TO TRACK BUTTON CHANGES
int buttonstate =HIGH;
int lastbuttonstate=HIGH;
int ledstate=LOW;

//debouncing variables

unsigned long lastdebouncetime= 0;
const unsigned long  debouncedelay=50;



void setup()
{
  // initialize pins 
  pinMode(ledpin, OUTPUT);
  pinMode(buttonpin , INPUT_PULLUP);

  //defining initial led state
  digitalWrite(ledpin, ledstate);

  // start serial debugging 
  Serial.begin(115200);

}

void loop() {
  //Read the current nutton state
  int reading= digitalRead(buttonpin);

  //check if the button state is changed
  if(reading != lastbuttonstate)
  {
    //reset the debounce timer
    lastdebouncetime= millis();

  }

  //checking if time is over then the delay
  if((millis()-lastdebouncetime) > debouncedelay)
  {
    if(reading != buttonstate)
    {
      buttonstate=reading;

      //if the button is pressed low toggle the LED
      if(buttonstate==LOW)
      {
        ledstate=!ledstate;
        digitalWrite(ledpin,ledstate);
        Serial.println(ledstate==HIGH ? "LED ON " : "LED OFF ");
      }
    }
  }

  lastbuttonstate =reading;

}
 