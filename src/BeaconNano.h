/*
  An Arduino library for the Arduino Nano 33 Ble.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  Written by Antonio Petruzzella for GGallery srl.

  Tested only for Arduino Nano 33 Ble board.
  
*/

#include <ArduinoBLE.h>

#ifndef BEACONNANO_H
#define BEACONNANO_H


class BeaconNano{
  
  private:
    std::string _uuid;
    int _major;
    int _minor;
    int _tx;
    void convertStringToByte(std::string uuid, byte bytes[]);
   
     
   
    
  public:
    
    
    BeaconNano();
    void setBeacon(std::string uuid, int major, int minor, int tx);
    void setUuid(std::string uuid);
    void setMajor(int major);
    void setMinor(int minor);
    void setTx(int tx);
    void startBeacon();
    void stopBeacon();
    


  
};


#endif