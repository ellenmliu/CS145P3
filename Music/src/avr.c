#include "avr.h"



void
ini_avr(void)
{
  WDTCR = 15;
  
  SET_BIT(DDRA, 0);

}

void wait_avr2(unsigned short msec)
{
	
}
void
wait_avr(unsigned short msec)
{
  TCCR0 = 3;
  while (msec--) {
    TCNT0 = (unsigned char)(256 - (XTAL_FRQ / 64) * .000001);
    SET_BIT(TIFR, TOV0);
    WDR();
    while (!GET_BIT(TIFR, TOV0));
  }
  TCCR0 = 0;
}
