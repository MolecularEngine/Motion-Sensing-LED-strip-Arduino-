#include <PololuLedStrip.h>

PololuLedStrip<6> ledStrip;

#define LED_COUNT 30
rgb_color colors[LED_COUNT]; // this array variable represents all the LEDs on the strip and what color theyll be using 3 values for red, blue , and green
 
  int pirPin = 7; // Input for HC-S501




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // set baud rate (rate at which bits are communiccated to the computer from the microcontroller
  pinMode(pirPin,INPUT); // this pin will recieve a signal when the

}

void loop() {
// put your main code here, to run repeatedly:

// detect motion
int Motion_detect = digitalRead(pirPin);


// if motion detected then turn on the LEDs and set them to white
 if(Motion_detect == 1)
  {
    for(byte i = 0; i < LED_COUNT; i++)
    {
     colors[i] = {212, 255, 250};
    }
    ledStrip.write(colors,LED_COUNT);
    delay(300000);

    for(byte i = 0; i < LED_COUNT; i++)
    {
      colors[i] = {0, 0, 0};
    }
    ledStrip.write(colors,LED_COUNT);
  }
  else 
    if(Motion_detect == 0)
   {
    for(byte i = 0; i < LED_COUNT; i++)
        {
          colors[i] = {0, 0, 0};
        }
        ledStrip.write(colors,LED_COUNT);
    }
   Serial.println(Motion_detect); // print "1" if any motion is detected from the detector, and print "0" if none is detected
}
