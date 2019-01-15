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
Die Motorspannung geht per Vorwiderstand auf 2 Optokopler, die je nach Polung je einen Pin am Micro-Controler schalten.
Ein Optokopler schaltet dann den Antrieb.

![Schema (Eagle)](https://github.com/s-muenzel/GaragentorSteuerung/blob/master/Eagle/Schema.PNG "Schema")

** TODO: ein Vorwiderstand für OK1 brauchts noch, wegen 3.3V MC out versus 1.2V PC817 in. **
** TODO: ein Vorwiderstand für OK3/4 ist ~1200Ohm, nicht 220 wie im Bild. **

#### Micro-Controler ####

Da gibt's natürlich viele Optionen. Ein ESP (8266 oder 32) mit genug GPIO Pins (*5*).

Ich nehme ein EPS8266 NodeMCU Board.

Für eine Arduinobeschaltung (5V versus 3.3V) muss dann zumindest der Vorwiderstand vor OK1 angepasst werden.
Dann brauchts natürlichnoch ein Wifi-Shield.


## Software ##

