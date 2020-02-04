#include <ProTrinketKeyboard.h>  // Ensure the library is installed

// Switches are connected from ground to these defined pins
const int PIN_BUTTON_CAPITAL_A = 9;
const int PIN_BUTTON_STRING    = 10;
boolean debug=false;
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  // Declare button pins as inputs
  pinMode(PIN_BUTTON_CAPITAL_A, INPUT_PULLUP);
  pinMode(PIN_BUTTON_STRING,    INPUT_PULLUP);

  // setting input pins to high means turning on internal pull-up resistors
digitalWrite(PIN_BUTTON_CAPITAL_A, HIGH);
 digitalWrite(PIN_BUTTON_STRING,    HIGH);
  // remember, the buttons are active-low, they read LOW when they are not pressed

  // start USB stuff
  TrinketKeyboard.begin();
  
  // send an intro:
  Serial.println("send any byte and I'll tell you everything I can about it");
  Serial.println();
    pinMode(13, OUTPUT);

}

void loop() {
  TrinketKeyboard.poll();
  // the poll function must be called at least once every 10 ms
  // or cause a keystroke
  // if it is not, then the computer may think that the device
  // has stopped working, and give errors
  
  // get any incoming bytes:
  if (Serial.available() > 0) {
      digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(50);              // wait for a second
      digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW

    int thisChar = Serial.read();

if(thisChar==8){
    TrinketKeyboard.pressKey(0,KEYCODE_BACKSPACE);
    TrinketKeyboard.pressKey(0, 0);

    }else if(thisChar==42){
     TrinketKeyboard.typeChar(124);
    }else if(thisChar==164){
     TrinketKeyboard.typeChar(39);
    }else if(thisChar==150){
     TrinketKeyboard.typeChar(58);
    }else if(thisChar==182){
     TrinketKeyboard.typeChar(59);
    }else if(thisChar==133){
     TrinketKeyboard.typeChar(123);
    }else if(thisChar==132){
     TrinketKeyboard.typeChar(34);
    }else if(thisChar==47){
     TrinketKeyboard.typeChar(38);
    }else if(thisChar==41){
     TrinketKeyboard.typeChar(40);
    }else if(thisChar==61){
     TrinketKeyboard.typeChar(41);
    }else if(thisChar==43){
     TrinketKeyboard.typeChar(45);
    }else if(thisChar==13){
     TrinketKeyboard.typeChar(10);//enter
    }else if(thisChar==40){
     TrinketKeyboard.typeChar(42);
    }else if(thisChar==95){
     TrinketKeyboard.typeChar(63);
    }else if(thisChar==63){
     TrinketKeyboard.typeChar(95);
    }else if(thisChar==34){
     TrinketKeyboard.typeChar(64);
    }else if(thisChar==194){
     TrinketKeyboard.typeChar(36);
    }else if(thisChar==45){
      TrinketKeyboard.typeChar(47);
  }else if(thisChar==58){
      TrinketKeyboard.typeChar(62);
    }else if(thisChar==59){
      TrinketKeyboard.typeChar(60);
    }else if(thisChar==38){
      TrinketKeyboard.typeChar(94);
    }else if(thisChar==9){
           TrinketKeyboard.pressKey(0,KEYCODE_TAB);
    TrinketKeyboard.pressKey(0, 0);

    }else if(thisChar==165){
   TrinketKeyboard.typeChar(91);
thisChar =10;

    }else if(thisChar==39)
    {
       Serial.print("special ");
    Serial.println();
        TrinketKeyboard.typeChar(61);
//    TrinketKeyboard.pressKey(0, 0);

    }else if (isControl(thisChar)) {
      Serial.println("it's a control character");
Serial.print("You sent me: \'");
  Serial.write(thisChar);
Serial.print("\'  ASCII Value: ");
    Serial.println(thisChar);    
      if (Serial.available() > 0) {

      Serial.println("2");
        int thisChar1 = Serial.read();
if(thisChar1 ==91){
  if (Serial.available() > 0) {
    int thisChar2 = Serial.read();
if(thisChar2 ==65){
    TrinketKeyboard.pressKey(0,KEYCODE_ARROW_UP);
    TrinketKeyboard.pressKey(0, 0);
}else if(thisChar2 ==66){
    TrinketKeyboard.pressKey(0,KEYCODE_ARROW_DOWN);
    TrinketKeyboard.pressKey(0, 0);
}else if(thisChar2 ==67){
    TrinketKeyboard.pressKey(0,KEYCODE_ARROW_RIGHT);
    TrinketKeyboard.pressKey(0, 0);
}else if(thisChar2 ==68){
    TrinketKeyboard.pressKey(0,KEYCODE_ARROW_LEFT);
    TrinketKeyboard.pressKey(0, 0);
}
}
      }}
  
}else{
   TrinketKeyboard.typeChar(thisChar);

    // say what was sent:
    if(debug==true){
    
 Serial.print("You sent me: \'");
  Serial.write(thisChar);
Serial.print("\'  ASCII Value: ");
    Serial.println(thisChar);    

    // analyze what was sent:
    if (isAlphaNumeric(thisChar)) {
      Serial.println("it's alphanumeric");
    }
    if (isAlpha(thisChar)) {
      Serial.println("it's alphabetic");
    }
    if (isAscii(thisChar)) {
      Serial.println("it's ASCII");
    }
    if (isWhitespace(thisChar)) {
      Serial.println("it's whitespace");
    }
  
    if (isDigit(thisChar)) {
      Serial.println("it's a numeric digit");
    }
    if (isGraph(thisChar)) {
      Serial.println("it's a printable character that's not whitespace");
    }
    if (isLowerCase(thisChar)) {
      Serial.println("it's lower case");
    }
    if (isPrintable(thisChar)) {
      Serial.println("it's printable");
    }
    if (isPunct(thisChar)) {
      Serial.println("it's punctuation");
    }
    if (isSpace(thisChar)) {
      Serial.println("it's a space character");
    }
    if (isUpperCase(thisChar)) {
      Serial.println("it's upper case");
    }
    if (isHexadecimalDigit(thisChar)) {
      Serial.println("it's a valid hexadecimaldigit (i.e. 0 - 9, a - F, or A - F)");
    }

    // add some space and ask for another byte:
    Serial.println();
    Serial.println("Give me another byte:");
    Serial.println();
    }
  }}
  if (digitalRead(PIN_BUTTON_STRING) == LOW)
  {
long rand=random(33,125);
     TrinketKeyboard.typeChar(rand);

    while(digitalRead(PIN_BUTTON_CAPITAL_A) == LOW){}
    delay(20);
  }

  if (digitalRead(PIN_BUTTON_CAPITAL_A) == LOW)
  {
    // type out a string using the Print class
    TrinketKeyboard.print("Hello World! ");
  }
}

/*
client computer: sudo screen /dev/ttyUSB0


line 33   !
line 34   Ä
..   #
   ¤
   %
   /
   ä
   )
   =
   (
   ,
   +
   .
  
   -
   0
   1
   2
   3
   4
   5
   6
   7
   8
   9
   Ö
   ö
   ;
 
   :
   _
   "
   A
   B
   C
   D
   E
   F
   G
   H
   I
   J
   K
   L
   M
   N
   O
   P
   Q
   R
   S
   T
   U
   V
   W
   X
   Y
   Z
   å
   '

   &
   ?
   §
   a
   b
   c
   d
   e
   f
   g
   h
   i+
   j
   k
   l
   m
   n
   o
   p
   q
   r
   s
   t
   u
   v
   w
   x
   y
   z
   Å
   *
   ½
*/
