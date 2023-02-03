/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP8266 chip.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right ESP8266 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
// #define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
// #define APP_DEBUG
/* Fill-in your Template ID (only if using Blynk.Cloud) */
#define BLYNK_TEMPLATE_ID   "TMPLknYkFSvD"
#define BLYNK_DEVICE_NAME   "NodeMCU"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "6ZISc6rMfLxplrGIi4e2Ryaqz62SV3fm";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "";
char pass[] = "";

BLYNK_WRITE(V0) {
  digitalWrite(D1, param.asInt());  
}

BLYNK_WRITE(V1) {
  digitalWrite(D1, param.asInt());
}

BLYNK_WRITE(V2) {
  int value = 0;
  int count = 0;
  while (param.asInt() == 1) {
    value = param.asInt();
    digitalWrite(D1, HIGH);
    delay(250);
    digitalWrite(D1, LOW);
    delay(250); 
    count++;
    if (count > 20) break;                   
  }
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  delay(100);

  // BlynkEdgent.begin();
  Blynk.begin(auth, ssid, pass);
  pinMode(D1, OUTPUT);
}

void loop()
{
  Blynk.run();
  // BlynkEdgent.run();
}

