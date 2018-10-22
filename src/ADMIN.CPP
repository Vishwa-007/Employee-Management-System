#include "Admin.h"

int Password()
{
	setcolor(LIGHTGRAY);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(240, 210, 400, 270);

	setcolor(RED);
	settextstyle(0, HORIZ_DIR, 1);
	outtextxy(263, 220, "ENTER PASSWORD");

	setcolor(BLACK);
	setfillstyle(SOLID_FILL, BLACK);
	bar(250, 235, 390, 260);

	char pswd[13], ch;
	int i = 0, x = 255, count = 0;
	setcolor(WHITE);

	get_password :
	{
		while(1)
		{
			ch = getch();

			if(ch == 13) break;
			else if(ch == 8)
			{
				if(strlen(pswd) != 0)
				{
					setcolor(BLACK);
					setfillstyle(SOLID_FILL, BLACK);
					bar(250, 235, 390, 260);

					setcolor(WHITE);

					int Bx = 255;

					for(int j = 0; j < i-1; j++)
					{
						outtextxy(Bx, 245, "*");
						Bx += 10;
					}

					i--;
					pswd[i] = '\0';
					x -= 10;
				}
			}

			else if(i < 13)
			{
				pswd[i] = ch;
				i++;
				pswd[i] = '\0';
				outtextxy(x, 245, "*");
				x += 10;
			}
		}
	}

	if(strcmpi(pswd, "Admin@007") != 0)
	{
		if(count == 5) return 0;

		setcolor(LIGHTRED);
		setfillstyle(SOLID_FILL, LIGHTRED);

		for(int x1 = 315, x2 = 325; x1 >= 250, x2 <= 390; x1 -= 5, x2 += 5)
		{
			bar(x1, 235, x2, 260);
			sound(5*(x2-x1));
			delay(10);
		}
		nosound();

		setcolor(LIGHTGRAY);
		setfillstyle(SOLID_FILL, LIGHTGRAY);
		bar(240, 190, 400, 290);

		setcolor(RED);
		settextstyle(0, HORIZ_DIR, 1);
		outtextxy(250, 200, "! WRONG PASSWORD !");
		outtextxy(275, 220, "ENTER AGAIN");
		outtextxy(255, 270, "TRAILS LEFT : ");
		outtextxy(365, 270, Convert(5-count));

		setcolor(BLACK);
		setfillstyle(SOLID_FILL, BLACK);
		bar(250, 235, 390, 260);

		pswd[0] = '\0';
		i = 0; x = 255;

		setcolor(WHITE);

		count++;

		goto get_password;
	}

	setcolor(LIGHTGREEN);
	setfillstyle(SOLID_FILL, LIGHTGREEN);

	for(int x1 = 315, x2 = 325; x1 >= 250, x2 <= 390; x1 -= 5, x2 += 5)
	{
		bar(x1, 235, x2, 260);
		sound(10*(x2-x1));
		delay(10);
	}
	nosound();

	return 1;
}

void ADMIN()
{
	BG();

	setcolor(RED);
	setfillstyle(SOLID_FILL, RED);

	Table(1);
	DateAndTime();
	ShowCursor();

	int x,y,b, id = 0;
	char del = 'n', mod = 'n';

	struct time t;
	int init_time = 0, final_time = 1;

	while(1)
	{
		gettime(&t);
		final_time = int(t.ti_min);

		GetCursorPos(x,y,b);
		if(b == 1)
		{
			HideCursor();

			if(x > 610 && x < 640 && y > 0 && y < 30) QUIT();

			else if(x > 60 && x < 160 && y > 72 && y < 92)
			{
				NewRecord();
				cleardevice();
				BG();
				Table(1);
			}

			else if(x > 450 && x < 550 && y > 72 && y < 92)
				id = Search(1);

			else if(id != 0 && x > 220 && x < 280 && y > 180 && y < 210)
				del = DeleteButton();
			else if(del == 'y' && x > 230 && x < 308 && y > 300 && y < 320)
			{
				DeleteRecord(id);
				cleardevice();
				BG();
				Table(1);
				del = 'n'; id = 0;
			}
			else if(del == 'y' && x > 312 && x < 390 && y > 300 && y < 320)
			{
				SearchTable(id, 1);
				del = 'n';
			}

			else if(id != 0 && x > 335 && x < 395 && y > 180 && y < 210)
				mod = ModifyButton();
			else if(mod == 'y' && x > 230 && x < 390 && y > 300 && y < 350)
				Modify_Name(id);
			else if(mod == 'y' && x > 230 && x < 390 && y > 350 && y < 400)
				Modify_Designation(id);
			else if(mod == 'y' && x > 230 && x < 390 && y > 400 && y < 450)
				Modify_Salary(id);
			else if(mod == 'y')
			{
				mod = 'n';
				cleardevice();
				SearchTable(id, 1);
			}

			else if(x > 0 && x < 30 && y > 0 && y < 30)
			{
				ShowCursor();
				break;
			}

			ShowCursor();
		}

		if(init_time != final_time)
		{
			DateAndTime();
			init_time = final_time;
		}
	}
}