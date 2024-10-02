#include <Arduino.h>
#include <ESP8266WiFi.h> 
#include <Hash.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>
#include <WiFiManager.h>


ESP8266WebServer httpServer(80);
ESP8266HTTPUpdateServer httpUpdater;

WiFiServer server(23);
WiFiClient serverClient;
WiFiManager wifiManager;

#define BAUD_RATE 9600

const char* update_path = "/firmware";
const char* update_username = "admin";
const char* update_password = "admin";
int RESET_PIN = 0; // = GPIO0 on nodeMCU

void setup()
{
  Serial.begin(BAUD_RATE, SERIAL_8N1);
	Serial.setRxBufferSize(1024); // requires ESP8266 >= 2.4.0 https://github.com/esp8266/Arduino/releases/tag/2.4.0-rc1

  delay(5000); // BOOT WAIT
  pinMode(RESET_PIN, INPUT_PULLUP);
  wifiManager.setHostname("KIM1");
  wifiManager.autoConnect("KIM1");

	server.begin();
	server.setNoDelay(true);

  httpUpdater.setup(&httpServer, update_path, update_username, update_password);
  httpServer.begin();

  WiFi.setSleepMode(WIFI_NONE_SLEEP); // disable WiFi sleep for more performance
}

void loop()
{
	if (server.hasClient())
		AcceptConnection();
	else if (serverClient && serverClient.connected())
		ManageConnected();
	
	httpServer.handleClient();
}

void AcceptConnection()
{
	if (serverClient && serverClient.connected()) 
		serverClient.stop();
	serverClient = server.available();
  // IAC WILL SUPPRESS-GO-AHEAD
  serverClient.write(255);
  serverClient.write(253);
  serverClient.write(3);
  // I WILL ECHO
  serverClient.write(255);
  serverClient.write(251);
  serverClient.write(1);
	serverClient.write("Connected\n");
}

void ManageConnected()
{
  size_t rxlen = serverClient.available();
  if (rxlen > 0)
	{
		char sbuf[rxlen];
		serverClient.read(sbuf, rxlen);
    Serial.write(sbuf, rxlen);
	}
  
  size_t txlen = Serial.available();
  if (txlen > 0)
	{
		char sbuf[txlen];
		Serial.read(sbuf, txlen);
    serverClient.write(sbuf, txlen);
	}
}
