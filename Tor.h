#ifndef _TOR
#define _TOR


class Tor {
  public:
    Tor();
    void Beginn();
    void Tick();
	
	bool Tor_Auf();
	bool Tor_Zu();
	
	enum Motor_Richtung {
		hoch = -1;
		keine = 0;
		runter = 1;
	};
	Motor_Richtung Motor_laeuft();
	
  private:
};

#endif // _TOR
