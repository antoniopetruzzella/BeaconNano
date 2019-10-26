// GGBeaconNano - Version: Latest 

#include <ArduinoBLE.h>
#include <BeaconNano.h>


void setup() {
  
  Beacon.begin("c336aa38054bb0483b0ae75027061982",1,1,197);
  Beacon.startBeacon();


}

void loop(){
  
}
