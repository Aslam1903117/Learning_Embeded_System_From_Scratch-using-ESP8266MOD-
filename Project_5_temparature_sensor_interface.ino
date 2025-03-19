#include <DHT.h>

#define LED_PIN 0        
#define DHT_PIN 2        
#define DHT_TYPE DHT22   
#define TEMP_THRESHOLD 10 

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);  
  Serial.begin(115200);        
  dht.begin();                
  delay(2000);                
  Serial.println("Project 5: DHT22 Sensor Ready");
}

void loop() {
  static unsigned long lastReadTime = 0;
  if (millis() - lastReadTime > 5000) {  
    float temp = dht.readTemperature();  
    float humid = dht.readHumidity();    
    
    if (isnan(temp) || isnan(humid)) {   
      Serial.println("Failed to read DHT22");
    } else {
      
      Serial.print("Temperature: ");
      Serial.print(temp, 1);
      Serial.print(" °C, Humidity: ");
      Serial.print(humid, 1);
      Serial.println(" %");

    
      if (temp > TEMP_THRESHOLD) {
        digitalWrite(LED_PIN, HIGH);
        Serial.println("LED ON (High Temp)");
      } else {
        digitalWrite(LED_PIN, LOW);
        Serial.println("LED OFF (Normal Temp)");
      }
    }
    lastReadTime = millis(); 
  }
}