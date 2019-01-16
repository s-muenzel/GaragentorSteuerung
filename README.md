# GaragentorSteuerung

Remote-Steuerung für unser motorisiertes Garagentor.

## Hardware ##

### Garagenantrieb ###

Das Tor kann per 5V-Leitung getriggert werden.
Dabei lässt sich die Richtung (auf/zu) nicht auswählen (siehe Abschnitt Software)

Die Spannungsversorgung des eigentlichen Antriebs(Motor) läuft auf 24V, diese führe ich aus dem Gehäuse raus.
Falls Spannung anliegt hängt die Drehrichtung von der Polung ab (-+ / +-).

### Elektronisches und Micro-Controler ###

#### PCB ####

Mit 2 simplen Kontaktschaltern (Tastern) wird der Zustand "Tor (komplett) offen" bzw. "Tor (komplett) zu" gemeldet. 
Die Motorspannung (24V) geht per Vorwiderstand auf 2 Optokopler, die je nach Polung je einen Pin am Micro-Controler schalten.
Ein Optokopler schaltet dann den Antrieb.

![Schema (Eagle)](https://github.com/s-muenzel/GaragentorSteuerung/blob/master/Eagle/Schema.PNG "Schema")


#### Micro-Controler ####

Da gibt's natürlich viele Optionen, z.B. ein ESP-Board (8266 oder 32) mit genug GPIO Pins (mindestens *5*).

Ich nehme ein ESP8266 NodeMCU Board.

Für eine Schaltung mit einem Arduino (5V versus 3.3V) muss dann der Vorwiderstand vor OK1 angepasst werden.
Dann brauchts natürlich noch ein Wifi-Shield.

#### Pin-Belegung ####
PIN | GPIO | Belegung 
----
D8 | GPIO15 | Tor ist auf
D7 | GPIO13 | Tor ist zu
D6 | GPIO12 | Motor läuft hoch
D5 | GPIO14 | Motor läuft runter
D1 | GPIO5  | Antrieb-Trigger 


## Software ##

Benötigte Funktionalität:
- Wifi		(WLAN Zugriff generell)
- NTP		(Zeitsync)
- WebServer (Steuerung von aussen)
- *MQTT		(Alternative Steuerung)?*
- *OTA		(Für Updates ohne direkten Zugang)?*

Genereller Ablauf:
- Setup: Wifi, NTP, WebServer/MQTT aufsetzen, Ports konfigurieren
- Loop: Status Motor und Tor (Auf-Zu) monitoren, Falls zu den Tor-Zu-Zeiten das Tor länger nicht geschlossen ist, Tor schliessen

- WebServer:
	/: Tor auf,zu,öffnet gerade,schliesst gerade
	/Auf: Wenn möglich und nötig: Tor öffnen
	/Zu: Wenn möglich und nötig: Tor schliessen
