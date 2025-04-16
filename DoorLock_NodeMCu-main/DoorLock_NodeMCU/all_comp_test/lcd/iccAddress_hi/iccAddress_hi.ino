#include <Wire.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Wire.begin();

  Serial.println("I2C Address Scanner. Type 'hi' to start scanning...");
}

void loop() {
  if (Serial.available() > 0) {
    String msg = Serial.readStringUntil('\n');
    if (msg == "hi") {
      scanI2C();
    }
  }
}

void scanI2C() {
  byte error, address;
  int deviceCount = 0;

  Serial.println("Scanning...");

  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
      deviceCount++;
    }
    delay(10);
  }

  if (deviceCount == 0) {
    Serial.println("No I2C devices found");
  }
}
