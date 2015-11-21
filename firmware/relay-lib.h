#ifndef _RELAY_LIB
#define _RELAY_LIB
 
#include "application.h"
 
// Based on http://awtfy.com/2011/07/14/a-too-simple-arduino-library-for-handling-the-seeeduino-relay-shield-and-generic-relays/
 
// Class Definition. 
class RelayLib
{
public: 
  RelayLib(int RelayPin, int state);    // Constructor   
  RelayLib(int RelayPin);    // Constructor, Defaults to off
  void on();    // Turns relay on 
  void off();   // Turns relay off
  void toggle();  // Toggles state of relay between on and off
  void pulse();  // Toggles state of relay between on and off
  int state();    // returns state of relay (LOW/0/off or HIGH/1/on) 
  int isRelayOn();   // Returns TRUE if the relay is on , false otherwise 
  int isRelayOff();  // Returns TRUE if the relay is off, false otherwise 
 
private: 
  int relayState;     // Variables holds on/off state of the relay
  int relayPin;       // Variable holds which Arduino pin connected to relay. 
};
 
#endif  
