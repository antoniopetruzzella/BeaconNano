// GGBeaconNano - Version: Latest 

#include <ArduinoBLE.h>
#include <BeaconNano.h>


void setup() {
  BeaconNano bn;
  bn.setUuid("c336aa38054bb0483b0ae75027061982");
  bn.setMajor(1);
  bn.setMinor(1);
  bn.setTx(197);
  bn.startBeacon();


}

void loop(){
  
}
