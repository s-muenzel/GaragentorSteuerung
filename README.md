# GaragentorSteuerung

Remote-Steuerung für unser motorisiertes Garagentor.

## Hardware ##

### Garagenantrieb ###

Das Tor kann per 5V-Leitung getriggert werden.
Dabei lässt sich die Richtung (auf/zu) nicht auswählen (siehe Abschnitt Software)

Die Spannungsversorgung des eigentlichen Antriebs(Motor) läuft auf 24V, diese führe ich aus dem Gehäuse raus.
Falls Spannung anliegt hängt die Drehrichtung von der Polung ab (-+ / +-).

### Elektronisches und Micro-Controler ###

Mit 2 simplen Kontaktschaltern (Tastern) wird der Zustand "Tor (komplett) offen" bzw. "Tor (komplett) zu" gemeldet. 
Die Motorspannung geht per Vorwiderstand auf 2 Optokopler, die je nach Polung je einen Pin am Micro-Controler schalten.
Ein Optokopler schaltet dann den Antrieb.

![Schema (Eagle)](https://github.com/s-muenzel/GaragentorSteuerung/blob/master/Eagle/Schema.PNG "Schema")



## Software ##
