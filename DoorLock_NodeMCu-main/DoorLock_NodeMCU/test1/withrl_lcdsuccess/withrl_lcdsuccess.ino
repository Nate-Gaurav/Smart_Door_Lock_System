//Web Server App Control Home Automation and Fingerprint Security LOCK
#include <ESP8266WiFi.h>
WiFiClient client;
WiFiServer server(80);

/* WIFI settings */
const char* ssid = "NG";   //WIFI SSID
const char* password = "1q2w3e4r";    //WIFI PASSWORD

/* data received from application */
String  data =""; 

/* define L298N or L293D motor control pins */
int Relay = 16;     //D0

void setup()
{
  /* initialize motor control pins as output */
  pinMode(Relay, OUTPUT);

  digitalWrite(Relay,HIGH);
  
  /* start server communication */
  Serial.begin(115200);
  connectWiFi();
  server.begin();
}

void loop()
{
    /* If the server available, run the "checkClient" function */  
    client = server.available();
    if (!client) return; 
    data = checkClient ();
    Serial.print(data);
    
    /************************ Run function according to incoming data from application *************************/
    if (data == "RELAY_SUCCESS")
    {
      digitalWrite(Relay,LOW);
      Serial.println(" ");
      Serial.println("OPEND");
      delay(3000);
      digitalWrite(Relay,HIGH);
      Serial.println("CLOSED");
    }
}

void connectWiFi()
{
  Serial.println("Connecting to WIFI");
  WiFi.begin(ssid, password);
  while ((!(WiFi.status() == WL_CONNECTED)))
  {
    delay(300);
    Serial.print("..");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("NodeMCU Local IP is : ");
  Serial.print((WiFi.localIP()));
}

/********************************** RECEIVE DATA FROM the APP ******************************************/
String checkClient (void)
{
  while(!client.available()) delay(1); 
  String request = client.readStringUntil('\r');
  request.remove(0, 5);
  request.remove(request.length()-9,9);
  return request;
}
