//including libraries required
#include "heltec.h"
#include "NewPing.h"

// Plugging HC-SR04 with Trig to Heltec Pin 2, Echo to Heltec pin 15
#define TRIGGER_PIN 2
#define ECHO_PIN 15

// Plugging LASER signal pin to Heltec Pin 23
#define LASER_PIN 23

// Maximum distance we want to ping for (in centimeters).
#define MAX_DISTANCE 150

// NewPing setup of pins and maximum distance.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
	Serial.begin(115200);
  pinMode(LED,OUTPUT);
	digitalWrite(LED,HIGH);
  pinMode(LASER_PIN,OUTPUT);
  Heltec.begin(false /*DisplayEnable Enable*/, false /*LoRa Enable*/, true /*Serial Enable*/);
}

void loop() {
	int distance = sonar.ping_cm();
  if(distance >= 5 && distance<=100){
    //Serial.println("Short Range");
    digitalWrite(LASER_PIN,HIGH);
  }
   else {
    digitalWrite(LASER_PIN,LOW); 
  }
  Serial.print("Distance:");
	Serial.print(sonar.ping_cm());
	Serial.println(" cm");
	//delay(500);
}
