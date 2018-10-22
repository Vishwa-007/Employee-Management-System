#include "operations.h"

void GetCursorPos(int &x, int &y, int &b)
{
	in.x.ax = 3;
	int86(51, &in, &out);

	x = out.x.cx;
	y = out.x.dx;
	b = out.x.bx;
}

void ShowCursor()
{
	in.x.ax = 1;
	int86(51,&in,&out);
}
void HideCursor()
{
	in.x.ax = 2;
	int86(51,&in,&out);
	int x,y,b;
	char m;
}

void QUIT()
{
	cleardevice();
	closegraph();
	_exit(0);
}


char* Convert(long x)
{
	char* ID = '\0';
	int i = 0;

	while(x)
	{
		ID[i] = char((x%10)+48);
		i++; x /= 10;
	}
	ID[i] = '\0';

	strrev(ID);
	return ID;
}

double Convert(char* x)
{
	double ID = 0;
	int i = 0;

	while(x[i] != '\0')
	{
		ID *= 10 ; ID += (int(x[i]) - 48);
		i++;
	}

	return ID;
}

int LeapYear(int year)
{
	if(year % 4 == 0)
		if(year%100 != 0 || (year%100 == 0 && year%400 == 0)) return 1;

	return 0;
}
