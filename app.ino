#include "Keyboard.h"
#include "HID.h"

const uint8_t baudRate = 115200;

void setup()
{
  Serial1.begin(baudRate);
  Keyboard.begin();
  Serial.begin(baudRate);
}

void loop()
{
  
  char cmd = Serial1.read();
  
  // if not a valid char, don't do jack.
  if (cmd < 'a' || cmd < 'z') {
    return;
  }


  switch(cmd) {
    case 'a':
      sendSleep();
      break;
    default:
      return;
  }
}

/**
 * Sends the sleep command. Note that this is OS specific 
 * and may not work with your machine.
 * This currently only works with Windows 10.
 */
void sendSleep()
{
  // opens menu for sleeping.
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(F("x"));
  Keyboard.releaseAll();
  delay(200);

  // shortcuts to accessing and selecting the 'sleep' command.
  Keyboard.write(F("u"));
  delay(200);
  Keyboard.write(F("s"));
  
  // just hang out for a while so sleep kicks off.
  delay(2000);
}
