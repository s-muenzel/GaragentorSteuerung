#include "Tor.h"

/*
#### Pin-Belegung ####
PIN | GPIO | Belegung 
----
D8 | GPIO15 | Tor ist auf
D7 | GPIO13 | Tor ist zu
D6 | GPIO12 | Motor läuft hoch
D5 | GPIO14 | Motor läuft runter
D1 | GPIO5  | Antrieb-Trigger 
*/

#define PIN_TOR_AUF			15
#define PIN_TOR_ZU 			13
#define PIN_MOTOR_HOCH		12
#define PIN_MOTOR_RUNTER	14
#define PIN_ANTRIEB			 5

Tor::Tor() {
	pinMode(PIN_TOR_AUF,		INPUT_PULLUP);
	pinMode(PIN_TOR_ZU,			INPUT_PULLUP);
	pinMode(PIN_MOTOR_HOCH,		INPUT_PULLUP);
	pinMode(PIN_MOTOR_RUNTER,	INPUT_PULLUP);

	pinMode(PIN_ANTRIEB, OUTPUT);
}

void Tor::Beginn() {
}

void Tor::Tick() {
}

bool Tor::Tor_Auf() {
	return !ditigalRead(PIN_TOR_AUF); // Taster ist ein Schliesser, wenn gedrückt (bei Tor Auf) ist PIN auf Masse --> false
}

bool Tor::Tor_Zu() {
	return !ditigalRead(PIN_TOR_ZU); // Taster ist ein Schliesser, wenn gedrückt (bei Tor Zu) ist PIN auf Masse --> false
}

/*enum Motor_Richtung {
	hoch = -1;
	keine = 0;
	runter = 1;
};*/
Motor_Richtung Tor::Motor_laeuft() {
	if(!ditigalRead(PIN_MOTOR_HOCH)) {
		return hoch;
	} else 
	if(!ditigalRead(PIN_MOTOR_RUNTER)) {
		return runter;
	} else 
		return keine;
}