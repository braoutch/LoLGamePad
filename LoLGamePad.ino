int vladipin=0;
int vladmode = 0;

// set pin numbers:
const int buzzPin =  3;
int pin0State = 0;
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
int pin3State = 0;
int redPin = 4;
int greenPin = 6;
int bluePin = 9;
int i = 1;
int joystickX = 0;
int joystickY = 0;
int j = 1;
int tabulation = 0;
int joystickButton = 0;
int back = 0;
int self = 0;
int oldMillis = 0;

void setup() {
  //Initialiser les pin des boutons pavec leur pullup resistance
  pinMode(2, INPUT_PULLUP);           // set pin to input with pullup resistance
  pinMode(5, INPUT_PULLUP);
  pinMode(0, INPUT_PULLUP);
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
  Serial.begin(115200);
  //Serial.baud();
   
  //Initialiser le buzzer
  pinMode(buzzPin, OUTPUT);

  //intialiser le keyboard
  Keyboard.begin();
  Mouse.begin();
  analogWrite(redPin, 130);
}

void Laugh(){
  Keyboard.write(76);
}

void loop() {

  Serial.println("206IM THE CLAW");
  if(Serial.available() > 0)
  {
  Serial.print("#Je t'entend");
  }
  //Intialiser les pin
  pin0State = digitalRead(0);
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
  pin3State = digitalRead(3);

  //Joystick
 joystickX = analogRead(A2);
 joystickY = analogRead(A3);
 
  if (pin0State == HIGH && i == 0)
  {
    i = 1;
  }

  //Mode 2 (en jeu)
  if (pin8State == LOW) { //Bouton 10
    Keyboard.write(102);
    delay(20);
  }

  if (pin15State == LOW) { //Bouton 9
    Keyboard.write(100);
    delay(20);
  }

  if (pin7State == LOW) { //Bouton 8
    Keyboard.write(114);
    //analogWrite(redPin, 155);
    analogWrite(greenPin, 177);
    analogWrite(bluePin, 155);
    delay(20);
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
  }
  if(vladmode == 0)
  {
    if (pin16State == LOW) { //Bouton 7
    vladipin = 1;
    Keyboard.write(101);
    analogWrite(bluePin, 155);
    delay(20);
    analogWrite(bluePin, 0);
    }
  }

  if(vladmode == 1)
  {
    if (pin16State == LOW) { //Bouton 7
      vladipin = 1;
      Keyboard.press(101);
      analogWrite(bluePin, 155);
      delay(20);
    }

   if
   (pin16State == HIGH && vladipin == 1) { //Bouton 7
    vladipin = 0;
    Keyboard.release(101);
    delay(20);
    analogWrite(bluePin, 0);
  }
  }

  if (pin19State == LOW) { //Bouton 6
    Keyboard.write(119);
    analogWrite(redPin, 155);
    //analogWrite(buzzPin,235);
    delay(20);
    analogWrite(redPin, 0);
    //analogWrite(buzzPin,0);

  }

  if (pin10State == LOW) { //Bouton 5
    Keyboard.write(113);
    analogWrite(greenPin, 77);
    //analogWrite(buzzPin,75);
    delay(20);
    analogWrite(greenPin, 0);
    //analogWrite(buzzPin,0);
  }

  if (pin2State == LOW) { //Bouton 4
    Keyboard.write(52);
    delay(20);
  }
  if (pin4State == LOW) { //Bouton 3
    Keyboard.write(103);
    delay(20);
  }
  if (pin18State == LOW) { //Bouton 2
    Keyboard.write(50);
    delay(20);
  }

  if (pin14State == LOW) { //Bouton 1
    Keyboard.write (49);
    delay(20);
    }

  if (joystickX < 300 && back == 0)  //BACK
    { 
      Keyboard.write (98);
      delay(20);
      back = 1;
    }
    
    if (joystickX > 300 && back == 1)  //BACK
    { 
      back = 0;
      delay(20);
    }

    if (joystickY < 300)  // item 3
    { 
    Keyboard.write (51);
    delay(20);
    }
    
    if (joystickX > 800 && self == 0)  // Space
    { 
    Keyboard.press (32);
    self = 1;
    delay(20);
    }

    else if(joystickX < 700 && self == 1)
    { 
    Keyboard.release (32);
    self = 0;
    delay(20);
    }
    
    if (joystickY > 900 && tabulation == 0) //TAB
    { 
    Keyboard.press (9);
    tabulation = 1;
        delay(20);
    }
    else if(joystickY < 700 && tabulation == 1)
    {
    Keyboard.release(9);
    tabulation = 0;
    delay(20);
    }
    
    //Serial.println('joystickX','joystickY');
    //Serial.print("joystickX : ");
    //Serial.print(joystickX);
    //Serial.print(" ; joystickY : ");
    //Serial.println(joystickY);
}

void readserial(){
  // check if serial command begin by # else drop the char
  if (Serial.peek() != '#' && Serial.available() > 0 )
    {
      char a=Serial.read();
    }

  if (Serial.peek() == '#' && Serial.available() > 0) { 
   // x = Serial.parseInt();
   // L = Serial.parseInt();
   // R = Serial.parseInt();
   // T = Serial.parseInt();

    //delay(100); // because it's better with delay ( yes, seem strange) 
    //pending_serial_input= true; 
  }}
