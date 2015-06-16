#include "relay-lib.h"
 
//
// The constructor sets up a single relay, specified by the Pin that relay is attached to

//
// The constructor will also properly set the assigned pin to OUTPUT. 
//
RelayLib::RelayLib(int _relayPin, int _state)
{
  relayPin=_relayPin; 
  pinMode(relayPin, OUTPUT); 
 
  if (_state == LOW) {
    relayState=LOW; 
    off(); 
  } 
  else {
    relayState=HIGH;
    on(); 
  }
}

//Set up with default to LOW

RelayLib::RelayLib(int _relayPin)
{
  relayPin=_relayPin; 
  pinMode(relayPin, OUTPUT); 
 
  relayState=LOW; 
  
}
 
// Turns the relay on. 
void RelayLib::on() 
{
  digitalWrite(relayPin, HIGH); 
  relayState=HIGH; 
}
 
// Turns the relay off. 
void RelayLib::off()
{
  digitalWrite(relayPin, LOW); 
  relayState=LOW; 
}
 
//Toggles the state of the relay
void RelayLib::toggle()
{
  if (relayState==HIGH) {
    off(); 
  } else {
    on(); 
  }
}
 
// Returns the state of the relay (LOW/0 or HIGH/1)
int RelayLib::state()
{
  return(relayState); 
}
 
// If the relay is on, returns true, otherwise returns false
int RelayLib::isRelayOn()
{
  if (relayState==HIGH) 
    return true; 
  else
    return false; 
}
 
// If the relay is off, returns true, otherwise returns false
int RelayLib::isRelayOff()
{
  if (relayState==LOW) 
    return true; 
  else
    return false; 
}
