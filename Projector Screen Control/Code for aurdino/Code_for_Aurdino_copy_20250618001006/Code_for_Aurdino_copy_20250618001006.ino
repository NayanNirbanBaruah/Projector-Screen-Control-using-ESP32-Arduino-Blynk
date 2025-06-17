#define BLYNK_TEMPLATE_ID "my credentials"
#define BLYNK_TEMPLATE_NAME "my credentials"
#define BLYNK_AUTH_TOKEN "my credentials"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Your WiFi credentials
char ssid[] = "Wifi Name";
char pass[] = "my credentials";      //My wifi password

// Define relay pins
#define RELAY1 18
#define RELAY2 19

// Relay control variables
bool button1State = false;
bool button2State = false;

// Blynk virtual pin V0 for Button 1
BLYNK_WRITE(V0) {
  int state = param.asInt(); // Get state of button
  button1State = (state == 1); // true if button is pressed
}

// Blynk virtual pin V1 for Button 2
BLYNK_WRITE(V1) {
  int state = param.asInt(); // Get state of button
  button2State = (state == 1); // true if button is pressed
}

void setup() {
  Serial.begin(115200);

  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);

  // Turn off relays initially
  digitalWrite(RELAY1, LOW);
  digitalWrite(RELAY2, LOW);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();

  // Relay 1 fires only if button 1 is continuously pressed
  if (button1State) {
    digitalWrite(RELAY1, HIGH); // Turn on relay
  } else {
    digitalWrite(RELAY1, LOW);  // Turn off relay
  }

  // Relay 2 fires only if button 2 is continuously pressed
  if (button2State) {
    digitalWrite(RELAY2, HIGH);
  } else {
    digitalWrite(RELAY2, LOW);
  }
}