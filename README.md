#BeaconNano

this library turns your Arduino 33 Nano Ble into a Beacon emulating it in all aspects.
You can define the basic characteristics of your Beacon (uuid, major and minor) with two methods:
1) Using classic begin(string uuid, int major, int minor, int tx);
2) Using setUuid(string), setMajor (int), setMinor (int), setTx(int) methods.

Library provides a external variable Beacon to access directly to class without instantiating a new, following Arduino Library Specs.

Then you use startBeacon() for start broadcasting advertising data. 

stopBeacon() stops broadcasting.

Look at example for a simple implementation.

Tested only for Arduino Nano 33 Ble.

Based on ArduinoBLE.h library.

*** WARNING ***

Library sets your Nano as a iBeacon, setting Manufacturer Company Data for this scope (line 61). You can change it, complete list of company ids    :
https://www.bluetooth.com/specifications/assigned-numbers/company-identifiers/

## License

```
Copyright (c) 2019 GGallery srl. All rights reserved.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA