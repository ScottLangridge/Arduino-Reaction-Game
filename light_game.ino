#include "pitches.h"

int currentLED = 1;
char dir = 'f';

void setup()
{
  pinMode(10, INPUT);
  for (int i = 1; i <= 5; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  digitalWrite(1, HIGH);
}

void loop()
{
  digitalWrite(currentLED, LOW);
  if (dir == 'f') {
    currentLED ++;
    if (currentLED == 5) {
      dir = 'b';
    }
  }
  else {
    currentLED --;
    if (currentLED == 1) {
      dir = 'f';
    }
  }
  digitalWrite(currentLED, HIGH);


  for (int i = 0; i < 200; i++) {
    if (digitalRead(10) == HIGH) {
      if (currentLED == 3) {
        winTone(11);
      } else {
        loseTone(11);
      }
      delay(500);
      break;
    }
    delay(5);
  }
}

void winTone(int piezo_pin) {
  tone(piezo_pin, NOTE_A4, 200);
  delay(200);
  tone(piezo_pin, NOTE_A4, 200);
  delay(200);
  tone(piezo_pin, NOTE_A4, 200);
  delay(200);
  tone(piezo_pin, NOTE_A4, 800);
  delay(400);
  tone(piezo_pin, NOTE_F4, 400);
  delay(200);
  tone(piezo_pin, NOTE_G4, 200);
  delay(400);
  tone(piezo_pin, NOTE_A4, 200);
  delay(400);
  tone(piezo_pin, NOTE_G4, 400);
  delay(200);
  tone(piezo_pin, NOTE_A4, 800);
  delay(800);
}

void loseTone(int piezo_pin) {
  tone(piezo_pin, NOTE_C3, 200);
  delay(200);
  tone(piezo_pin, NOTE_C2, 200);
  delay(200);
}
