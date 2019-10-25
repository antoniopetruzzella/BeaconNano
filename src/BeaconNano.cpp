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

  Written by Antonio Petruzzella.

  Tested only for Arduino Nano 33 Ble board.
  
*/
#include <ArduinoBLE.h>
#include <BeaconNano.h>

BeaconNano::BeaconNano(){
  

}

void BeaconNano::setUuid(std::string uuid){
  _uuid=uuid;
}

void BeaconNano::setMajor(int major){
    _major=major;
}

void BeaconNano::setMinor(int minor){
    _minor=minor;
}

void BeaconNano::setTx(int tx){
    _tx=tx;
}

void BeaconNano::setBeacon(std::string uuid, int major, int minor, int tx){
  _uuid=uuid;
  _major=major;
  _minor=minor;
  _tx=tx;
  
}

void BeaconNano::startBeacon(){
   if (!BLE.begin()) {
      while (1);
  }


  
  byte uuidByte[16],majByte[2],minByte[2];
  convertStringToByte(_uuid,uuidByte);
  byte data[25]={
    0x4C,0x00,0x02,0x15,
    uuidByte[0],
    uuidByte[1],
    uuidByte[2],
    uuidByte[3],
    uuidByte[4],
    uuidByte[5],
    uuidByte[6],
    uuidByte[7],
    uuidByte[8],
    uuidByte[9],
    uuidByte[10],
    uuidByte[11],
    uuidByte[12],
    uuidByte[13],
    uuidByte[14],
    uuidByte[15],
    0,
    _major,
    0,
    _minor,
    _tx
  };
  BLE.setManufacturerData(data, 25);// AGGIUNGE IL MANUFACT
  BLE.advertise();
}

void BeaconNano::stopBeacon(){
  BLE.stopAdvertise();
}

void BeaconNano::convertStringToByte(std::string uuid, byte bytes[]){
  char uuidChar[uuid.length()+1];
  strcpy(uuidChar,uuid.c_str());
  int pos=0;
  for (unsigned int i = 0; i<sizeof(uuidChar);i += 2){
    
    char hexValue[2]; 
    hexValue[0]=uuidChar[i];
    hexValue[1]=uuidChar[i+1];
    int intValue=strtol(hexValue,0, 16);
    bytes[pos]=(char)intValue;
    pos++;
  }
  
}