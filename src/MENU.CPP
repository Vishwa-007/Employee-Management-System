#include "Menu.h"

void BUTTONS()
{
	setcolor(RED);
	setfillstyle(SOLID_FILL, RED);
	pieslice(340, 195, 0, 360, 15);
	pieslice(365, 240, 0, 360, 15);
	pieslice(340, 285, 0, 360, 15);

	setcolor(WHITE);
	settextstyle(0, HORIZ_DIR, 2);
	outtextxy(385, 185, "DATABASE");
	outtextxy(400, 230, "ADMIN");
	outtextxy(385, 280, "ATTENDANCE");
}

void MENU_OPEN()
{
	BG();
	for(int i = 320; i >= 220; i -= 10) LOGO(i, 240);
	BUTTONS();
	CloseButton();
}

void MENU_CLOSE()
{
	for(int i = 220; i <= 320; i += 10)
	{
		LOGO(i, 240);
		setcolor(CYAN);
		setfillstyle(SOLID_FILL,CYAN);
		pieslice(i-10,240,0,360,75);
	}
	BG();
	LOGO(320,240);
	CloseButton();
}

char MenuButtonStatus(int x, int y)
{
	if(x > 325 && y > 180 && x < 355 && y < 210) return 'a';
	else if(x > 350 && y > 225 && x < 380 && y < 255) return 'b';
	else if(x > 325 && y > 270 && x < 355 && y < 300) return 'c';
	return 'n';
}

char MenuStatus(char &m)
{
	if(m == 'y') { m = 'n'; return 'n'; }
	m = 'y';
	return 'y';
}

void MENU()
{
	int x,y,b;
	char m = 'n', mb = 'n', MBS;

	struct time t;
	int init_time = 0, final_time = 1;

	BG(); LOGO(320,240);
	CloseButton();
	ShowCursor();

	while(1)
	{
		gettime(&t);
		final_time = int(t.ti_min);

		GetCursorPos(x,y,b);
		if(b == 1)
		{
			HideCursor();

			if(x > 610 && x < 640 && y > 0 && y < 30) QUIT();

			MBS = MenuButtonStatus(x,y);
			if(mb == 'n' && MenuStatus(m) == 'y')
			{
				HideCursor();
				MENU_OPEN(); mb = 'y';
				DateAndTime('m');
				ShowCursor();
			}
			else if(mb == 'y' && MBS != 'n')
			{
				if(MBS == 'a')
				{
					DATABASE();
					m = mb = 'n';
					HideCursor();
					MENU_CLOSE();
					DateAndTime('m');
					ShowCursor();
				}

				else if(MBS == 'b')
				{
					int pass = Password();

					if(pass == 1) ADMIN();
					else
					{
						m = mb = 'n';
						HideCursor();
						MENU_CLOSE();
						DateAndTime('m');
						ShowCursor();
					}
				}

				else if(MBS == 'c')
				{
					ATTENDANCE();
					Add_Attendance();
					m = mb = 'n';
					HideCursor();
					MENU_CLOSE();
					DateAndTime('m');
					ShowCursor();
				}
			}
			else
			{
				m = mb = 'n';
				HideCursor();
				MENU_CLOSE();
				DateAndTime('m');
				ShowCursor();
			}
		}

		ShowCursor();

		if(init_time != final_time)
		{
			DateAndTime('m');
			init_time = final_time;
		}
	}
}
