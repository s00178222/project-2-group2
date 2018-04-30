int LDR = 0;      //analog pin to which LDR is connected, here we set it to 0 so it means A0
int LDRValue = 0;      //that’s a variable to store LDR values
int light_sensitivity = 100;    //This is the approx value of light surrounding your LDR
 
void setup()
  {
    Serial.begin(9600);          //start the serial monitor with 9600 buad
    pinMode(3, OUTPUT);     
  }
 
void loop()
  {
    LDRValue = analogRead(LDR);      //reads the ldr’s value through LDR 
    Serial.println(LDRValue);       //prints the LDR values to serial monitor
    delay(10);        //This is the speed by which LDR sends value to arduino
 
    if (LDRValue < light_sensitivity) 
      {
        digitalWrite(3, LOW);
        // turn off tone function for pin 8:


      }
    else
      {
        digitalWrite(3, HIGH);  noTone(8);
  
  tone(6, 440, 200);
  delay(200);

  
  noTone(6);
  
  tone(7, 494, 500);
  delay(500);

  
  noTone(7);
  
  tone(8, 523, 300);
  delay(300);

    tone(6, 440, 200);
  delay(200);

  
  noTone(6);
  
  tone(7, 494, 500);
  delay(500);

  
  noTone(7);
  
  tone(8, 523, 300);
  delay(300);
      }
  }
