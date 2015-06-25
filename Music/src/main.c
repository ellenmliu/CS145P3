/*
 * Include header files for all drivers that have been imported from
 * avr.h
 */
#include <avr.h>
#include <lcd.h>

int period = 0;
int duration = 1;


int main (void)
{
	ini_lcd();
	put_str_lcd("Let it Go");
	//the intro
	int tempo = 70;
	init_music();
		// calculated by getting the duration in msec, then using formula:
		//		(1 / Target Frequency) / (1 / Timer Clock Frequency) - 1
		// note: we needed to convert the msec to sec since clock frequency is given in sec.
		// assuming x/4 time
		int quarterNote =  (8000000/(tempo/60) -1)/1024;
		int halfNote = quarterNote*2;
		int wholeNote = quarterNote*4;
		int eighthNote = quarterNote/2;
		int sixteenNote = quarterNote/4;
		int dottedEight = eighthNote*3;
		int dottedSixteenth = (sixteenNote*3)/2;
		int dottedQuarter = eighthNote * 3;
		int dottedHalf = quarterNote*3;
		
		int Af_h[] = {120, halfNote};
		int Af_s[] = {120, sixteenNote};
		int Af_e[] = {120, eighthNote};
		int A_dh[] = {114, dottedHalf};
		int A_e[] = {114, eighthNote};
		int A_q[] = {114, quarterNote};
		int A_h[] = {114, halfNote};
		int A_w[] = {114, wholeNote};
		int A_dq[] = {114, dottedQuarter};
		int A2f_s[] = {60, sixteenNote};
		int A2f_e[] = {60, eighthNote};
		int A2f_de[] = {60, dottedEight};
		
		int Bf_h[] = {107, halfNote};
		int Bf_s[] = {107, sixteenNote};
		int Bf_e[] = {107, eighthNote};
		int Bf_dq[] = {107, dottedQuarter};
		int Bf_de[] = {107, dottedEight};
		int B_q[] = {101, quarterNote};
		int B_e[] = {101, eighthNote};

		int C_s[] = {96, sixteenNote};
		int C_e[] = {96, eighthNote};
		int C_q[] = {96, quarterNote};
		
		int Df_s[] = {90, sixteenNote};
		int Df_q[] = {90, quarterNote};
		int D_ds[] = {85, dottedSixteenth};
		int D_de[] = {85, dottedEight};
		int D4_e[] = {170, eighthNote};
		int D5_e[] = {85, eighthNote};
		int D5_q[] = {85, quarterNote};
		int D5_h[] = {85, halfNote};
		
		int Ef_q[] = {80, quarterNote};
		int Ef_s[] = {80, sixteenNote};
		int Ef_de[] = {80, dottedEight};
		int E_e[] = {152, eighthNote};
		int E_q[] = {152, quarterNote};
		int E6_q[] = {38, quarterNote};
		int E5_q[] = {76, quarterNote};
		
		int F_e[] = {143, eighthNote};
		int F_q[] = {143, quarterNote};
		int Fs_e[] = {135, eighthNote};
		int Fs_q[] = {135, quarterNote};
		int F2_w[] = {72, wholeNote};
		int F2_h[] = {72, halfNote};
		int F2_s[] = {72, sixteenNote};
		int F2_e[] = {72, eighthNote};
		int F2_de[] = {72, dottedEight};
		
		int G4_e[] = {128, eighthNote};
		int G4_dh[] = {128, dottedHalf};
		int G4_w[] = {128, wholeNote};
		int G4_q[] = {128, quarterNote};
		int G2_s[] = {64, sixteenNote};
		int G2_e[] = {64, eighthNote};
		int G5_q[] = {64, quarterNote};
	
	int blank_s[] = {0, sixteenNote/8};
	
	int song[] = {G2_s, A2f_s, C_s, G2_s, G2_s, A2f_de, G2_s, A2f_s, C_s, A2f_s, A2f_s,
		G2_e, Bf_s, F2_s, G2_s, Bf_s, F2_s, F2_s, G2_s, Bf_s, Ef_q, Df_q, G2_s, A2f_s,
		C_s, G2_s, G2_s, A2f_de, blank_s, A2f_s, G2_s, C_s, A2f_s, A2f_s, G2_e, Bf_s, F2_s, G2_s,
		Bf_s, F2_s, F2_s, G2_e, Bf_s, Ef_q, D_de, A2f_s};
	
	tempo = 135;
	playSong(song, 26);
	
	//the chorus
	tempo = 145;
	
	quarterNote =  (8000000/(tempo/60) -1)/1024;
	halfNote = quarterNote*2;
	wholeNote = quarterNote*4;
	eighthNote = quarterNote/2;
	sixteenNote = quarterNote/4;
	dottedEight = eighthNote*3;
	dottedSixteenth = (sixteenNote*3)/2;
	dottedQuarter = eighthNote * 3;
	dottedHalf = quarterNote*3;
	
	Af_h[1] = halfNote;
	Af_s[1] = sixteenNote;
	Af_e[1] = eighthNote;
	A_dh[1] = dottedHalf;
	A_e[1] = eighthNote;
	A_q[1] = quarterNote;
	A_h[1] =  halfNote;
	A_w[1] = wholeNote;
	A_dq[1] = dottedQuarter;
	A2f_s[1] = sixteenNote;
	A2f_e[1] = eighthNote;
	A2f_de[1] = dottedEight;
	
	Bf_h[1] = halfNote;
	Bf_s[1] = sixteenNote;
	Bf_e[1] = eighthNote;
	Bf_dq[1] = dottedQuarter;
	Bf_de[1] = dottedEight;
	B_q[1] = quarterNote;	
	B_e[1] = eighthNote;

	C_s[1] = sixteenNote;
	C_e[1] = eighthNote;
	C_q[1] = quarterNote;
	
	Df_s[1] = sixteenNote;
	Df_q[1] = quarterNote;
	D_ds[1] = dottedSixteenth;
	D_de[1] = dottedEight;
	D4_e[1] = eighthNote;
	D5_e[1] = eighthNote;
	D5_q[1] = quarterNote;
	D5_h[1] = halfNote;
	
	Ef_q[1] = quarterNote;
	Ef_s[1] = sixteenNote;
	Ef_de[1] = dottedEight;
	E_e[1] = eighthNote;
	E_q[1] = quarterNote;
	E6_q[1] = quarterNote;
	E5_q[1] = quarterNote;
	
	F_e[1] = eighthNote;
	F_q[1] = quarterNote;
	Fs_e[1] = eighthNote;
	Fs_q[1] = quarterNote;
	F2_w[1] = wholeNote;
	F2_h[1] = halfNote;
	F2_s[1] = sixteenNote;
	F2_e[1] = eighthNote;
	F2_de[1] = dottedEight;
	
	G4_e[1] = eighthNote;
	G4_dh[1] = dottedHalf;
	G4_w[1] = wholeNote;
	G4_q[1] = quarterNote;
	G2_s[1] = sixteenNote;
	G2_e[1] = eighthNote;
	G5_q[1] = quarterNote;
		
	int song2[] = {G4_e, F_e, G4_dh, D4_e, D5_e, A_dh, G4_q, E_e, blank_s, E_e, blank_s,
		E_q, blank_s, E_q, Fs_q, G4_dh, E_e, Fs_e, G4_dh, D4_e, D5_e, A_dh, G4_e, A_e, B_q,
		C_q, B_q, A_q, G4_w, E6_q, G5_q, E5_q, G4_q, B_q, blank_s, B_q, blank_s, B_q, blank_s,
		E_e, blank_s, E_e, blank_s,/*starting measure 11*/ E_e, A_e, G4_e, blank_s, G4_e,
		G4_q, blank_s, G4_e, blank_s, G4_e, A_e, A_dq, G4_q, B_e, blank_s, B_e, blank_s,
		B_e, blank_s, B_e, B_q, D5_q, /*start measure 15*/ E5_q, D5_h, A_e, G4_e, A_q, blank_s, A_h,
	blank_s, A_e, G4_e, A_w};
	playSong(song2, 76);
	
	
	// Insert application code here, after the board has been initialized.

}


void playSong(const int* songs, int numNotes)
{
	for(int i = 0; i <numNotes; i++)
	{
		playNote(songs[i]);
	}
}

void init_music(void)
{
	ini_avr();
	// setting timer to FCPU/1024
	SET_BIT(TCCR1B, 0);
	SET_BIT(TCCR1B, 2);
}
void playNote(int note[])
{
	TCNT1 = 0;
	// pos 0 is note, 1 is duration
	for(;;)
	{
		SET_BIT(PORTA, 0);
		wait_avr(note[0]);
		CLR_BIT(PORTA, 0);
		wait_avr(note[0]);
		if(TCNT1 >= note[1])
			break;
	}
}
//typedef struct Note
//{
	//// period is divded by 2, so play note will use this for one wait_avr
	//unsigned int period = 72;
	//// duration is given by msec per beat relative to the tempo
	//unsigned int duration = 1/((tempo/60)/1000);
	//
//}noteF;
