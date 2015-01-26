// set pin numbers:
const int buzzPin =  3;
int mode = 2;
int pin2State = 0;
int pin4State = 0;
int pin18State = 0;
int pin19State = 0;
int pin7State = 0;
int pin8State = 0;
int pin15State = 0;
int pin10State = 0;
int pin14State = 0;
int pin16State = 0;
int redPin = 4;
int greenPin = 6;
int bluePin = 9;
int i = 1;
int joystickX = 0;
int joystickY = 0;
int j = 1;


#include "pitches.h"

//mélodies
int melody[] = {
  NOTE_CS4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_GS4, NOTE_C5, NOTE_GS4, NOTE_G4, NOTE_DS5, NOTE_CS5, NOTE_C5, NOTE_CS5, NOTE_F4, NOTE_GS4, NOTE_AS4
};

int melodymode1[] = {
  NOTE_C4, NOTE_E4, NOTE_G4, NOTE_C5
};

int melodymode2[] = {
  NOTE_C5, NOTE_G4, NOTE_E4, NOTE_C4
};

int melodyA[] = {
  NOTE_C4
};
int melodyZ[] = {
  NOTE_E4
};
int melodyE[] = {
  NOTE_G4
};
int melodyR[] = {
  NOTE_C5
};








// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  9, 24, 2, 6, 6, 3, 6, 6, 3, 9, 24, 2, 12, 12, 3
};

int noteDurationsmode1[] = {
  6, 6, 6, 3
};

int noteDurationsmode2[] = {
  6, 6, 6, 3
};
// variables will change:

void setup() {
  //Initialiser les pin des boutons pavec leur pullup resistance
  pinMode(2, INPUT_PULLUP);           // set pin to input with pullup resistance
  pinMode(5, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);



  //Initialiser le buzzer
  pinMode(buzzPin, OUTPUT);

  //intialiser le keyboard
  Keyboard.begin();
  Mouse.begin();
  analogWrite(redPin, 130);
  //


  //définir la mélodie au branchement
  /*for (int thisNote = 0; thisNote < 15; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 2000 / noteDurations[thisNote];
    tone(buzzPin, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(buzzPin);
  }*/
}

void loop() {
  //Intialiser les pin
  pin2State = digitalRead(2);
  pin4State = digitalRead(5);
  pin18State = digitalRead(18);
  pin19State = digitalRead(19);
  pin7State = digitalRead(7);
  pin8State = digitalRead(8);
  pin15State = digitalRead(15);
  pin10State = digitalRead(10);
  pin14State = digitalRead(14);
  pin16State = digitalRead(16);

  //Joystick
  joystickX = analogRead(A2);
  joystickY = analogRead(A3);

  /* if (j > 1000)
   {
     joystickX = analogRead(A2);
     joystickY = analogRead(A3);
     //Example Joystick
     if (joystickX < 300)  //BAS
     {
       Serial.print("BAS");
       Serial.print(" - ");
     }
     if (joystickY < 300)  // GAUCHE
     {
     Serial.print("GAUCHE");
     Serial.print(" - ");
     }

     if (joystickX > 700) //HAUT
     {
       Serial.print("HAUT");
       Serial.print(" - ");
     }
     if (joystickY > 700) //DROIT
     {
     Serial.print("DROITE");
     Serial.print(" - ");
     }
       j = 0;
   }
   j += 1;

  */

  //Changement de mode
  if (pin10State == LOW && pin19State == LOW && pin16State == LOW && pin7State == LOW )
  {
    if (mode == 1)
    {
      mode = 2;

      //Mélodie mode 2
      for (int thisNote = 0; thisNote < 4; thisNote++) {
        int noteDuration = 2000 / noteDurationsmode2[thisNote];
        tone(buzzPin, melodymode2[thisNote], noteDuration);
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(buzzPin);
      }
      analogWrite(redPin, 0);

    }
    else if (mode == 2) {
      mode = 1;

      //Mélodie mode 1
      for (int thisNote = 0; thisNote < 4; thisNote++) {
        int noteDuration = 2000 / noteDurationsmode1[thisNote];
        tone(buzzPin, melodymode1[thisNote], noteDuration);
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(buzzPin);
      }
      analogWrite(redPin, 150);

    }
  }

  //Mode 1 (en sélection des champions)

  if (pin15State == LOW && mode == 1 && i == 1) {
    i = 0;
    Keyboard.write(81);
    Keyboard.write(119);
    Keyboard.write(117);
    Keyboard.write(114);
    Keyboard.write(33);
    Keyboard.write(42);
    Keyboard.write(113);
    Keyboard.write(119);
    Keyboard.write(117);
    Keyboard.write(114);
    Keyboard.write(40);
    Keyboard.write(64);
    Keyboard.write(13);  //retour
    Keyboard.write(10);
    i = 1;
  }
  if (pin15State == HIGH && mode == 1 && i == 0)
  {
    i = 1;
  }






  if (pin14State == LOW && mode == 1) { //Bouton 1 : TOP
    Mouse.click(MOUSE_LEFT);
    Keyboard.write(116); //t
    Keyboard.write(111); //o
    Keyboard.write(112); //p
    Keyboard.write(13);  //retour
    Keyboard.write(10);  //chariot
    delay(40);
  }

  if (pin18State == LOW && mode == 1) { //Bouton 2 : JUNGLE
    Mouse.click(MOUSE_LEFT);
    Keyboard.write(106); //j
    Keyboard.write(117); //u
    Keyboard.write(110); //n
    Keyboard.write(103); //g
    Keyboard.write(108); //l
    Keyboard.write(101); //e
    Keyboard.write(13);  //retour
    Keyboard.write(10);  //chariot
    delay(40);
  }

  if (pin4State == LOW && mode == 1) { //Bouton 3 : MID
    Mouse.click(MOUSE_LEFT);
    Keyboard.write(59); //m
    Keyboard.write(105); //i
    Keyboard.write(100); //d
    Keyboard.write(13);  //retour
    Keyboard.write(10);  //chariot
    delay(40);
  }

  if (pin2State == LOW && mode == 1) { //Bouton 4 : ADC
    Mouse.click(MOUSE_LEFT);
    Keyboard.write(113); //a
    Keyboard.write(100); //d
    Keyboard.write(99); //c
    Keyboard.write(13);  //retour
    Keyboard.write(10);  //chariot
    delay(40);
  }

  //Mode 2 (en jeu)


  if (pin8State == LOW && mode == 2) { //Bouton 10
    Keyboard.press(102);
    // delay(40);
    Keyboard.release(102);

  }

  if (pin15State == LOW && mode == 2) { //Bouton 9
    Keyboard.press(100);
    // delay(40);
    Keyboard.release(100);

  }

  if (pin7State == LOW && mode == 2) { //Bouton 8
    Keyboard.press(114);
    //analogWrite(redPin, 155);
    analogWrite(greenPin, 177);
    analogWrite(bluePin, 155);
    delay(20);
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    Keyboard.release(114);
  }
  if (pin16State == LOW && mode == 2) { //Bouton 7
    Keyboard.press(101);
    analogWrite(bluePin, 155);
    delay(20);
    analogWrite(bluePin, 0);
    Keyboard.release(101);

  }

  if (pin19State == LOW && mode == 2) { //Bouton 6
    Keyboard.press(119);
    analogWrite(redPin, 155);
    delay(20);
    analogWrite(redPin, 0);
    Keyboard.release(119);

  }

  if (pin10State == LOW && mode == 2) { //Bouton 5
    Keyboard.press(113);
    analogWrite(greenPin, 77);
    delay(20);
    analogWrite(greenPin, 0);
    Keyboard.release(113);
  }

  if (pin2State == LOW && mode == 2) { //Bouton 4
    Keyboard.press(52);
    //delay(40);
    Keyboard.release(52);

  }
  if (pin4State == LOW && mode == 2) { //Bouton 3
    Keyboard.press(103);
    //delay(40);
    Keyboard.release(103);
  }
  if (pin18State == LOW && mode == 2) { //Bouton 2
    Keyboard.press(50);
    delay(20);
    Keyboard.release(50);
  }

  if (pin14State == LOW && mode == 2) { //Bouton 1
    Keyboard.press(49);
    delay(20);
    Keyboard.release(49);
  }

  if (joystickX < 300 && mode == 2)  //BAS
  {
    Keyboard.press (98);
    //delay(40);
    Keyboard.release (98);
  }
  if (joystickY < 300 && mode == 2)  // GAUCHE
  {
    Keyboard.press (51);
    // delay(40);
    Keyboard.release (51);
  }

  if (joystickX > 700 && mode == 2) //HAUT
  {
    Keyboard.press (112);
    delay(500);
    Keyboard.release (112);
  }
  if (joystickY > 700 && mode == 2) //DROIT
  {
    Keyboard.press (9);
  }
  else {
    Keyboard.release(9);
  }

}
