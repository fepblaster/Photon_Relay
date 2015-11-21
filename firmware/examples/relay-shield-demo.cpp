// This #include statement was automatically added by the Spark IDE.
#include "relay-lib/relay-lib.h"

#define RELAY1_PIN D10
#define RELAY2_PIN D1
#define RELAY3_PIN D2
#define RELAY4_PIN D3

RelayLib relay[] = {RelayLib(RELAY1_PIN), RelayLib(RELAY2_PIN), RelayLib(RELAY3_PIN), RelayLib(RELAY4_PIN)};


void setup()
{
   Spark.function("relay", relayControl);
}

void loop()
{
}

// command format r1,ON or r1,OFF or r1,SWITCH
int relayControl(String command)
{
  // parse the relay number
  int relayNumber = command.charAt(1) - '0';
  // do a sanity check
  if (relayNumber < 1 || relayNumber > 4) return -1;

  // find out the state of the relay
  if (command.substring(3,5) == "ON") relay[relayNumber - 1].on();
  else if (command.substring(3,6) == "OFF") relay[relayNumber - 1].off();
  else if (command.substring(3,9) == "SWITCH")  relay[relayNumber - 1].toggle();
  else if (command.substring(3,8) == "PULSE")  relay[relayNumber - 1].pulse();
  else return -1;

  return 1;
}
