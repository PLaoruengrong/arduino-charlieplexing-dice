const int buttonPin = A0; 
byte pins[] = {2,3,4};  
const int NUMBER_OF_PINS = sizeof(pins)/ sizeof(pins[0]);  
const int NUMBER_OF_LEDS = NUMBER_OF_PINS * (NUMBER_OF_PINS-1);  
byte pairs[NUMBER_OF_LEDS/2][2] = { {0,1}, {1,2}, {0,2}};  
void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  }  
void loop() { 
  if (digitalRead(buttonPin) == HIGH) {  
    int i =random(0,NUMBER_OF_LEDS+1); 
    lightLed(i); // calls the lightLed function to light the selected LED
    }
  }  
void lightLed(int led){ // this function lights the given LED  
  int indexA = pairs[led/2][0];  
  int indexB = pairs[led/2][1];  
  int pinA = pins[indexA];  
  int pinB = pins[indexB];  
  for(int i=0; i < NUMBER_OF_PINS; i++) {  
    if(pins[i] != pinA && pins[i] != pinB){  // if this pin is not one of our pins 
      pinMode(pins[i], INPUT); // set the mode to input  
      digitalWrite(pins[i],LOW); // make sure pull-up is off 
      }    
    pinMode(pinA, OUTPUT);  
    pinMode(pinB, OUTPUT);  
    if(led%2 == 0){  
      digitalWrite(pinA,LOW);  
      digitalWrite(pinB,HIGH);  
    }else{  
    digitalWrite(pinB,LOW);  
    digitalWrite(pinA,HIGH);
    }
  }
} 
