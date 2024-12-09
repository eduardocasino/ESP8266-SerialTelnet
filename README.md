### Fork of https://github.com/arkypita/ESP8266-SerialTelnet modified to work with the KIM-1

1. Download and install the latest **Arduino IDE 2.X or 1.6.X** from [https://www.arduino.cc/en/Main/Software](https://www.arduino.cc/en/Main/Software)

2. Install **ESP8266** Arduino support using Boards Manager: [https://github.com/esp8266/Arduino#installing-with-boards-manager](https://github.com/esp8266/Arduino#installing-with-boards-manager)

    ***Only*** for IDE 1.6.X, force install version >= 2.4.0. Replace package URL with: [https://github.com/esp8266/Arduino/releases/download/2.4.0-rc1/package_esp8266com_index.json](https://github.com/esp8266/Arduino/releases/download/2.4.0-rc1/package_esp8266com_index.json)

3. Install Install the following libraries:
    * WifiManager: [https://github.com/tzapu/WiFiManager#install-through-library-manager](https://github.com/tzapu/WiFiManager#install-through-library-manager)

4. Select board `Generic ESP8266Module`

5. Configure your ESP8266 for sketch upload (GIPOs pulled up and down accordingly, USB to serial connected, reset and ready for upload)

6. Upload the Sketch contained in `telnetserver` folder

7. Connect to the ESP8266 WiFi network and go to "http://192.168.4.1". Configure connection to your AP, set password, then switch back to your local wifi

8. Connect to the ESP8266 using a Telnet client. Set local echo to off.
