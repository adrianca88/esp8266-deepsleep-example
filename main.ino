#include <DHT.h>
#include <ESP8266WiFi.h>

const int sleepSeconds = 5 * 60; // 5 minutes

#define DHTPIN D4
#define DHTTYPE DHT11 
 
DHT dht(DHTPIN, DHTTYPE);
    
void ReadData()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) 
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.println("Temp = %.1f, Hum = %.1f", t, h);
}

void setup() 
{
  Serial.begin(9600);
   
  // Connect D0 to RST to wake up
  pinMode(D0, WAKEUP_PULLUP);
 
  // Do Work
  dht.begin();

  ReadData();
      
  // Convert to microseconds
  ESP.deepSleep(sleepSeconds * 1000000);
}
 
void loop() 
{
}
