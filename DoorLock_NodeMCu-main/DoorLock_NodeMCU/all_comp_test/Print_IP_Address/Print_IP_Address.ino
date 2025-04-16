#include "ESP8266WiFi.h"

// WiFi parameters to be configured
const char* ssid = "NG";            // Write here your router's username
const char* password = "1q2w3e4r";  // Write here your router's password

void setup(void) {
  Serial.begin(9600);
  // Connect to WiFi
  WiFi.begin(ssid, password);

  // while wifi not connected yet, print '.'
  // then after it connected, get out of the loop

  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    
    attempts++;
    Serial.print(".");
    if (attempts > 20) {  // if 10 seconds passed and no connection, print error
      Serial.println("Connection error. Check your WiFi settings.");
      break;
    }
  }

  if (WiFi.status() == WL_CONNECTED) {
    //print a new line, then print WiFi connected and the IP address
    Serial.println("");
    Serial.println("WiFi connected");
    // Print the IP address
    Serial.println(WiFi.localIP());
  }
}

void loop() {
  // Nothing
}
