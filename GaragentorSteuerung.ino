/* */

#ifdef ESP32
# include <WiFi.h>
# include <ESPmDNS.h>
#endif
#ifdef ESP8266
# include <ESP8266WiFi.h>
# include <ESP8266WebServer.h>
# include <ESP8266mDNS.h>
#endif

#include <Time.h>
#include <TimeLib.h>

#include "Zugangsinfo.h"
#include "WebS.h"
#include "NTP.h"

#define DEBUG_SERIAL
#ifdef DEBUG_SERIAL
#define D_BEGIN(speed)   Serial.begin(speed)
#define D_PRINT(...)     Serial.print(__VA_ARGS__)
#define D_PRINTLN(...)   Serial.println(__VA_ARGS__)
#define D_PRINTF(...)    Serial.printf(__VA_ARGS__)
#else
#define D_BEGIN(speed)
#define D_PRINT(...)
#define D_PRINTLN(...)
#define D_PRINTF(...)
#endif

WiFiClient __Wifi_Client;
WebS __WebS;
NTP_Helfer __NTP;

/////////////////////////////////////////////////
// Normaler WiFi Part

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  D_PRINTF("Verbinde mit %s",ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    D_PRINT(".");
  }

  D_PRINTF("\n erfolgreich, IP Adresse: ");
  D_PRINTLN(WiFi.localIP());

  MDNS.begin(hostname);
}


//////////////////////////////////////////////////////
// Hauptprogramm

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  D_BEGIN(115200);
  setup_wifi();

  // NTP
  __NTP.Beginn();
  D_PRINT(" NTP Service laeuft");

  // Webserver konfigurieren
  __WebS.Beginn();
  D_PRINT(" Webserver laeuft");

}

void loop() {
  __WebS.Tick();
  delay(50);
}

