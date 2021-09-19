#include <Servo.h> 

// constants won't change. They're used here to set pin numbers:
const int buttonPinGreenOne = 2;     // the number of the pushbutton pin
const int buttonPinOrange = 3;
const int buttonPinBlue = 4;
const int buttonPinYellow = 5;
const int buttonPinGreenTwo = 6;
int lockCode = 0;
int numOfButtonPressed = 0;

const int ledPinOne =  13;      // the number of the LED pin
const int ledPinTwo =  12;
const int ledPinThree =  11;
const int ledPinFour =  10;
const int ledPinFive =  9;

// variables will change:
int buttonStateGreenOne = 0;
int buttonStateOrange = 0;
int buttonStateBlue = 0;
int buttonStateYellow = 0;
int buttonStateGreenTwo = 0;

int firstPressed = 0;
int secondPressed = 0;
int thirdPressed = 0;
int correctCode = 0;
int pos = 0;

Servo myservo;


void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPinOne, OUTPUT);
  pinMode(ledPinTwo, OUTPUT);
  pinMode(ledPinThree, OUTPUT);
  pinMode(ledPinFour, OUTPUT);
  pinMode(ledPinFive, OUTPUT);
  
  // initialize the pushbutton pin as an input:
  
  pinMode(buttonPinGreenOne, INPUT);
  pinMode(buttonPinOrange, INPUT);
  pinMode(buttonPinBlue, INPUT);
  pinMode(buttonPinYellow, INPUT);
  pinMode(buttonPinGreenTwo, INPUT);

  myservo.attach(A0);
  
  Serial.begin(9600);
}


void loop() {
  // read the state of the pushbutton value:
  buttonStateGreenOne = digitalRead(buttonPinGreenOne);
  buttonStateOrange = digitalRead(buttonPinOrange);
  buttonStateBlue = digitalRead(buttonPinBlue);
  buttonStateYellow = digitalRead(buttonPinYellow);
  buttonStateGreenTwo = digitalRead(buttonPinGreenTwo);
  
  if (buttonStateGreenOne == HIGH & buttonStateOrange == HIGH & buttonStateBlue == HIGH & buttonStateYellow == HIGH & buttonStateGreenTwo == HIGH  ) {
    // turn LED on:
    digitalWrite(ledPinOne, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPinOne, LOW);
  }

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonStateGreenOne == HIGH){
    numOfButtonPressed++;
    delay(1000);
    lockCode++;
    if (numOfButtonPressed == 1){
    firstPressed = 1;
    }
    if (numOfButtonPressed == 2){
    secondPressed = 1;
    }
    if (numOfButtonPressed == 3){
      thirdPressed = 1;
    }
  }
  if (buttonStateOrange == HIGH){
    numOfButtonPressed++;
    delay(1000);
    lockCode = lockCode + 2;
    if (numOfButtonPressed == 1){
    firstPressed = 2;
    }
    if (numOfButtonPressed == 2){
    secondPressed = 2;
    }
    if (numOfButtonPressed == 3){
      thirdPressed = 2;
    }
  }
  if (buttonStateBlue == HIGH){
    numOfButtonPressed++;
    delay(1000);
    lockCode = lockCode + 3;
    if (numOfButtonPressed == 1){
    firstPressed = 3;
    }
    if (numOfButtonPressed == 2){
    secondPressed = 3;
    }
    if (numOfButtonPressed == 3){
      thirdPressed = 3;
    }
  }
  if (buttonStateYellow == HIGH){
    numOfButtonPressed++;
    delay(1000);
    lockCode = lockCode + 4;
    if (numOfButtonPressed == 1){
    firstPressed = 4;
    }
    if (numOfButtonPressed == 2){
    secondPressed = 4;
    }
    if (numOfButtonPressed == 3){
      thirdPressed = 4;
    }
  }
  if (buttonStateGreenTwo == HIGH){
    numOfButtonPressed++;
    delay(1000);
    lockCode = lockCode + 5;
    if (numOfButtonPressed == 1){
    firstPressed = 5;
    }
    if (numOfButtonPressed == 2){
    secondPressed = 5;
    }
    if (numOfButtonPressed == 3){
      thirdPressed = 5;
    }
  }

  if (firstPressed == 1 && secondPressed == 2 && thirdPressed == 3){
    correctCode++;
  }

  if (correctCode == 1 && lockCode == 6 && numOfButtonPressed == 3){
    //pos++;
    digitalWrite(ledPinOne, HIGH);
    delay(1000);
    digitalWrite(ledPinTwo, HIGH);
    delay(1000);
    digitalWrite(ledPinThree, HIGH);
    delay(1000);
    digitalWrite(ledPinFour, HIGH);
    delay(1000);
    digitalWrite(ledPinFive, HIGH);
    delay(3000);
    correctCode++;
    while(correctCode == 2){
      myservo.write(pos);
      pos = 90;
      delay(3000);
      
      myservo.write(pos);
      correctCode = 1;
      }
    
    digitalWrite(ledPinOne, LOW);
    digitalWrite(ledPinTwo, LOW);
    digitalWrite(ledPinThree, LOW);
    digitalWrite(ledPinFour, LOW);
    digitalWrite(ledPinFive, LOW);
    numOfButtonPressed = 0;
    lockCode = 0;
    firstPressed = 0;
    secondPressed = 0;
    thirdPressed = 0;
    correctCode = 0;
    pos = 0;
  }
  
  if (numOfButtonPressed >= 3){
    numOfButtonPressed = 0;
    lockCode = 0;
    firstPressed = 0;
    secondPressed = 0;
    thirdPressed = 0;
    correctCode = 0;
    pos = 0;
  }
  
  Serial.println(numOfButtonPressed);
  Serial.println(lockCode);
  Serial.println(firstPressed);
  Serial.println(secondPressed);
  Serial.println(thirdPressed);
  Serial.println(correctCode);
}
