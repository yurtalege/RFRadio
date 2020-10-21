/*
/// \author Matthias Hertel, http://www.mathertel.de
/// \copyright Copyright (c) 2014 by Matthias Hertel.\n
/// This work is licensed under a BSD style license. See http://www.mathertel.de/License.aspx
/// More documentation and source code is available at http://www.mathertel.de
ArduinoExample code for RDA5807M Arduino FM receiver.
Compiled&Tested by Riyaz
*/

#include <Arduino.h>
#include <Wire.h>
#include <radio.h>
#include <RDA5807M.h>
#define FIX_BAND     RADIO_BAND_FM    //Radio Band -FM
#define FIX_STATION  9170  //Station Tuned = 100.50 MHz.
#define FIX_VOLUME   2              //Audio Volume Level 5.

RDA5807M radio;    

void setup() {
 
  Serial.begin(57600);
  Serial.println("FM Radio");
  delay(200);

  
  radio.init();

  
  radio.debugEnable();

  
  radio.setBandFrequency(FIX_BAND, FIX_STATION);
  radio.setVolume(FIX_VOLUME);
  radio.setMono(false);
  radio.setMute(false);
} 



void loop() {
  char s[12];
  radio.formatFrequency(s, sizeof(s));
  Serial.print("Station:"); 
  Serial.println(s);
  
  Serial.print("Radio:"); 
  radio.debugRadioInfo();
  
  Serial.print("Audio:"); 
  radio.debugAudioInfo();

  delay(3000);
} 
