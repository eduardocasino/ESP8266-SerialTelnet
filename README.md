Fork of https://github.com/arkypita/ESP8266-SerialTelnet modified to work with the KIM-1
`1.`  Download and install Arduino IDE 1.6.x from https://www.arduino.cc/en/Main/Software

`2.`  Install ESP8266 Arduino support https://github.com/esp8266/Arduino#installing-with-boards-manager

Please note: require version >= 2.4.0 
Replace package URL with https://github.com/esp8266/Arduino/releases/download/2.4.0-rc1/package_esp8266com_index.json

`3.`  Install the following libraries:

`3.1:`  WifiManager: https://github.com/tzapu/WiFiManager#install-through-library-manager

`4.` Configure your ESP8266 for sketch upload (GIPOs pulled up and down accordingly, USB to serial connected, reset and ready for upload)

`5.`  Upload the Sketch contained in `telnetserver` folder

`6.`  Connect to the ESP8266 WiFi network and go to "http://192.168.4.1". Configure connection to your AP, set password, then switch back to your local wifi 

`7.` Connect to the ESP8266 using a Telnet client
