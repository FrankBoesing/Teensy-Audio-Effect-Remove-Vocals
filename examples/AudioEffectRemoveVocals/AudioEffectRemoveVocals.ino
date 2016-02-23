// Simple Example for Remove Vocals Effect

#include <tower.h>
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioPlaySdWav           playSdWav1;     //xy=191,718
AudioEffectRemoveVocals  removeVocals1;      //xy=356,709
AudioOutputI2S           i2s1;           //xy=521,708
AudioConnection          patchCord1(playSdWav1, 0, removeVocals1, 0);
AudioConnection          patchCord2(playSdWav1, 1, removeVocals1, 1);
AudioConnection          patchCord3(removeVocals1, 0, i2s1, 0);
AudioConnection          patchCord4(removeVocals1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=359,803
// GUItool: end automatically generated code

// Use these with the audio adaptor board
#define SDCARD_CS_PIN    10
#define SDCARD_MOSI_PIN  7
#define SDCARD_SCK_PIN   14

// Use these for the SD+Wiz820 or other adaptors
//#define SDCARD_CS_PIN    4
//#define SDCARD_MOSI_PIN  11
//#define SDCARD_SCK_PIN   13

void setup() {
  initTower();
  AudioMemory(8);

  // Comment these out if not using the audio adaptor board.
  // This may wait forever if the SDA & SCL pins lack
  // pullup resistors
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.5);

  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);
  if (!(SD.begin(SDCARD_CS_PIN))) {
    while (1) {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }
}

void playFile(const char *filename)
{
  playSdWav1.play(filename);
  delay(5);
  while (playSdWav1.isPlaying()) {  }
}


void loop() {
  playFile("SDTEST1.WAV");  // filenames are always uppercase 8.3 format
}

