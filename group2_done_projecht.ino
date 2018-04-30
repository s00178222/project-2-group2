int LDR = 0;      //analog pin to which LDR is connected, here we set it to 0 so it means A0
int LDRValue = 0;      //that’s a variable to store LDR values
int light_sensitivity = 100;    //This is the approx value of light surrounding your LDR

 #include <Bridge.h>
#include <HttpClient.h>
void setup()
  {
    Serial.begin(9600);          //start the serial monitor with 9600 buad
    pinMode(3, OUTPUT);   
      Bridge.begin();  
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
     HttpClient client;
       client.get("http://api.pushingbox.com/pushingbox?devid=v531EBCC3B8BC3EA");
       while (client.available()) {
    char c = client.read();
    SerialUSB.print(c); 
        digitalWrite(3, HIGH);  noTone(8);
  // play a note on pin 6 for 200 ms:
  tone(6, 440, 200);
  delay(200);

  // turn off tone function for pin 6:
  noTone(6);
  // play a note on pin 7 for 500 ms:
  tone(7, 494, 500);
  delay(500);

  // turn off tone function for pin 7:
  noTone(7);
  // play a note on pin 8 for 300 ms:
  tone(8, 523, 300);
  delay(300);
  }
    }
  }
  

  


  

 





