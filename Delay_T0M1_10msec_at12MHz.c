#include<reg51.h>
void T0M1Delay();
void main(void)
{
	while(1)
	{
	P1 = 0x00;
	T0M1Delay();
	P1 = 0xFF;
	T0M1Delay();
}
	}
void T0M1Delay()
{
	unsigned int a;
	TMOD = 0x01;
	TH0 = 0xD8; 			//0XD8F0 FOR 10msec delay @12MHz Oscillator frquency
	TL0 = 0xF0;
	TR0 = 1;
	while(TF0 == 0);
	TR0 = 0;
	TF0 = 0;
	}