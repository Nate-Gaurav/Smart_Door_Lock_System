 #include "ESP8266WiFi.h"

// WiFi parameters to be configured
const char* ssid = "Redmi A2";            // Write here your router's username
const char* password = "1q2w3e4r";  // Write here your router's password

void connectToWiFi() {
  Serial.print("\nConnecting to WiFi");
  WiFi.begin(ssid, password);

  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    attempts++;
    if (attempts > 20) {  // if 10 seconds passed and no connection, print error
      Serial.println("\nConnection error. Check your WiFi settings.");
      return;
    }
  }

  Serial.println("\nWiFi connected");
  Serial.println("IP address: " + WiFi.localIP().toString());
}

void setup() {
  Serial.begin(9600);
  
  connectToWiFi();//calling wifi connection function
}

void loop() {
  // Nothing
}
