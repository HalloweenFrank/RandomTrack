#include <Arduino.h>
#include <SoftwareSerial.h>
#include "DYPlayerArduino.h"

int inputPin = 12;
int busyPin = 8;
int val = 0;
int busy = 0;
int song = 0;
int songTotal = 0;
SoftwareSerial SoftSerial(10, 11);
DY::Player player(&SoftSerial);
 
void setup() {
  pinMode(inputPin, INPUT);
  player.begin();
  player.setVolume(20);
  player.setPlayingDevice(DY::Device::Sd);
  songTotal = player.getSoundCount();
}
 
void loop(){
  val = digitalRead(inputPin);
  busy = digitalRead(busyPin);
  if ((val == HIGH) && (busy == HIGH)) {
    songTotal = player.getSoundCount();
    song = random(1, (songTotal + 1));  
    player.playSpecified(song);  
    delay(15000); 
  }
}
