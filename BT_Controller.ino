#include <BleCombo.h>

//BleComboKeyboard Keyboard("BT-Controller");
//BleComboMouse Mouse;

const int Wpin = 27;
const int Apin = 14;
const int Spin = 12;
const int Dpin = 13;
const int ANALOG_X_PIN = 34;
const int ANALOG_Y_PIN = 35;
const int ANALOG_BUTTON_PIN = 32;

//Default values when axis not actioned 
#define ANALOG_X_CORRECTION 128
#define ANALOG_Y_CORRECTION 128
	 
struct button { 
	 byte pressed = 0; 
}; 
	 
struct analog { 
	 short x, y; 
	 
	 button btn; 
}; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  // buttin pin config
  pinMode(Wpin, INPUT_PULLUP);
  pinMode(Apin, INPUT_PULLUP);
  pinMode(Spin, INPUT_PULLUP);
  pinMode(Dpin, INPUT_PULLUP);

 

  // joystick config
  pinMode(ANALOG_BUTTON_PIN, INPUT_PULLUP); 

  Keyboard.begin();
  Mouse.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

  bool anyButtonPressed = false;

  if ( (digitalRead(Wpin) == LOW) || (digitalRead(Apin) == LOW) || (digitalRead(Spin) == LOW) || (digitalRead(Dpin) == LOW) ) {
    anyButtonPressed = true;
  } else {
    anyButtonPressed = false;
  }
   analog analog; 
	 
    analog.x = readAnalogAxisLevel(ANALOG_X_PIN); 
    analog.y = readAnalogAxisLevel(ANALOG_Y_PIN); 
    
    analog.btn.pressed = isAnalogButtonPressed(ANALOG_BUTTON_PIN); 
    
    

    int deadzone_max = 250; // Change to the maximum value seen when joystick is at rest
    int deadzone_min = 5;  // Change to the minimum value seen when joystick is at rest

    int deadzoneX_max = 200; // Change to the maximum X-value seen when joystick is at rest
    int deadzoneX_min = 50;  // Change to the minimum X-value seen when joystick is at rest

    int deadzoneY_max = 200; // Change to the maximum Y-value seen when joystick is at rest
    int deadzoneY_min = 50;  // Change to the minimum Y-value seen when joystick is at rest

  if(Keyboard.isConnected()) {

    Serial.print("X:"); 
    Serial.print(analog.x); 
    Serial.print("   ");
    
    Serial.print("Y:"); 
    Serial.println(analog.y);

    // BUTTONS
    if (digitalRead(Wpin) == LOW) {
      Keyboard.press(119); // w
      Serial.println("W");
      // while(digitalRead(Wpin) == LOW); 
      // Keyboard.release(119);
      delay(150);

    } else if (digitalRead(Apin) == LOW) {
      Keyboard.press(97); // a
      Serial.println("A");
      // while(digitalRead(Apin) == LOW); // STOPS here until you release the button
      // Keyboard.release(97);
      delay(150);

    } else if (digitalRead(Spin) == LOW) {
      Keyboard.press(115); // s
      Serial.println("S");
      // while(digitalRead(Spin) == LOW); // STOPS here until you release the button
      // Keyboard.release(115);
      delay(150);

    } else if (digitalRead(Dpin) == LOW) {
      Keyboard.press(100); // d
      Serial.println("D");
      // while(digitalRead(Dpin) == LOW); // STOPS here until you release the button
      // Keyboard.release(100);
      delay(150);

    } else {
      if ( (!anyButtonPressed) && (analog.x > deadzone_max) ){
        
        Keyboard.press(218); // up arrow -> look up

      } else if ( (!anyButtonPressed) && (analog.x < deadzone_min)) {
        
        Keyboard.press(217); // down arrow -> look down

      } 
      else if ( (!anyButtonPressed) && (analog.y > deadzone_max) ){
       
        Keyboard.press(215); // right arrow -> look right

      } else if ( (!anyButtonPressed) && (analog.y < deadzone_min)) {
        
        Keyboard.press(216); // left arrow -> look left

      } 
      else {
        
        Keyboard.releaseAll();
      }
    }
    delay(100);
  }
}

byte readAnalogAxisLevel(int pin) 
{ 
	 return map(analogRead(pin), 0, 1023, 0, 1023); 
} 
	 
bool isAnalogButtonPressed(int pin) 
{ 
	 return digitalRead(pin) == 0; 
} 


