#include "Attendance.h"

int Search_ID(int y)
{
	char* id = '\0', ch;
	int i = 0;

	setcolor(DARKGRAY);
	setfillstyle(SOLID_FILL, DARKGRAY);
	bar(240,y,400,y+30);

	setcolor(LIGHTGRAY);
	settextstyle(0,HORIZ_DIR,0);
	outtextxy(255,y+10,"ENTER ID");

	setcolor(BLACK);
	setfillstyle(SOLID_FILL, BLACK);
	bar(240,y+30,400,y+60);

	setcolor(WHITE);

	while(1)
	{
		ch = getch();

		if(ch == 13 || ch == '*') break;
		else if(i <= 10 && isdigit(ch)) { id[i] = ch; i++; }

		else if(ch == 8)
		{
			i--;
			setcolor(BLACK);
			setfillstyle(SOLID_FILL, BLACK);
			bar(240,y+30,400,y+60);
			setcolor(WHITE);
		}

		id[i] = '\0';
		outtextxy(255,y+45,id);
	 }

	 return Convert(id);
}

void TimeIN(int id)
{
	fstream file("EMPLOYEE.DAT", ios::binary | ios::in | ios::out);
	Employee x;
	struct time t;

	gettime(&t);
	int h = int(t.ti_hour), m = int(t.ti_min);

	while(file.read((char*)&x, sizeof(x)))
		if(id == x.GetID())
		{
			int pos = file.tellg() - sizeof(x);
			file.seekg(pos, ios::beg);
			break;
		}

	if(x.TimeINH() == 0 && x.TimeOUT() == 0)
	{
		x.TimeINH(h);
		x.TimeINM(m);
		file.write((char*)&x, sizeof(x));

		setcolor(BLACK);
		settextstyle(0,HORIZ_DIR,0);
		outtextxy(170,330,Convert(h));
		outtextxy(190,330,":");
		outtextxy(205,330,Convert(m));
	}

	file.close();
}

void TimeOUT(int id)
{
	fstream file("EMPLOYEE.DAT", ios::binary | ios::in | ios::out);
	Employee x;

	while(file.read((char*)&x, sizeof(x)))
		if(id == x.GetID()) break;

	if(x.TimeINH() != 0 && x.TimeOUT() == 0)
	{
		struct time t;

		gettime(&t);
		int ho, mo, hi, mi;

		hi = x.TimeINH();
		mi = x.TimeINM();
		ho = int(t.ti_hour);
		mo = int(t.ti_min);

		x.TimeOUT(ho);
		int pos = file.tellg() - sizeof(x);
		file.seekg(pos, ios::beg);
		file.write((char*)&x, sizeof(x));

		setcolor(BLACK);

		settextstyle(0,HORIZ_DIR,0);
		outtextxy(170,330,Convert(hi));
		outtextxy(190,330,":");
		outtextxy(205,330,Convert(mi));

		settextstyle(0,HORIZ_DIR,0);
		outtextxy(410,330,Convert(ho));
		outtextxy(430,330,":");
		outtextxy(445,330,Convert(mo));
	}

	file.close();
}

char Statistics(int id, int animate)
{
	ifstream file("EMPLOYEE.DAT", ios::binary);
	Employee x;

	char found = 'n';

	while(file.read((char*)&x, sizeof(x)))
	{
		if(id == x.GetID())
		{
			found = 'y';
			break;
		}
	}
	file.close();

	if(animate == 1)
	{
		for(int i=210,j=220,k=240; i>=10,j>=20,k>=40; i-=10,j-=10,k-=10)
		{
			BG();
			CloseButton();
			BackButton();
			setcolor(DARKGRAY);
			setfillstyle(SOLID_FILL, DARKGRAY);
			bar(240,i,400,i+60);

			setcolor(LIGHTGRAY);
			settextstyle(0,HORIZ_DIR,0);
			outtextxy(255,j,"ENTER ID");

			setcolor(BLACK);
			setfillstyle(SOLID_FILL, BLACK);
			bar(240,k,400,k+30);
			setcolor(WHITE);
			outtextxy(255,k+15,Convert(id));

			delay(10);
		}
	}

	else
	{
		BG();
		CloseButton();
		BackButton();
		setcolor(DARKGRAY);
		setfillstyle(SOLID_FILL, DARKGRAY);
		bar(240,10,400,70);

		setcolor(LIGHTGRAY);
		settextstyle(0,HORIZ_DIR,0);
		outtextxy(255,20,"ENTER ID");

		setcolor(BLACK);
		setfillstyle(SOLID_FILL, BLACK);
		bar(240,40,400,70);
		setcolor(WHITE);
		outtextxy(255,55,Convert(id));
	}

	if(found == 'y')
	{
		setcolor(BLUE);
		settextstyle(0,HORIZ_DIR,2);
		outtextxy(100,150,"TOTAL ATTENDANCE : ");

		setcolor(BLACK);
		settextstyle(0,HORIZ_DIR,4);
		outtextxy(230,200,Attendance(x));

		setcolor(RED);
		setfillstyle(SOLID_FILL, RED);
		bar(150,270,250,300);
		bar(390,270,490,300);

		setcolor(WHITE);
		settextstyle(0,HORIZ_DIR,0);
		outtextxy(170,282,"TIME IN");
		outtextxy(410,282,"TIME OUT");
	}

	else SORRY();

	return found;
}

void Add_Attendance()
{
	fstream file("EMPLOYEE.DAT", ios::binary | ios::in | ios::out);
	Employee x;

	while(file.read((char*)&x, sizeof(x)))
	{
		int pos = file.tellg() - sizeof(x);
		file.seekg(pos, ios::beg);

		if(x.TimeOUT() != 0 && x.TimeINH() != 0 && x.Gave_Attendance() == 'n')
		{
			x.Present();
			x.Gave_Attendance('y');
		}

		file.write((char*)&x, sizeof(x));
	}

	file.close();
}

void MakeSearch(int y, int animate, int &ID, char &f)
{
	int id = Search_ID(y);

	cleardevice();
	BG();

	char found = Statistics(id,animate);

	ID = id;
	f = found;
}

void ATTENDANCE()
{
	cleardevice();
	BG();

	char f; int id;
	MakeSearch(210,1,id,f);

	Begin :
	{
		int x,y,b;

		ShowCursor();

		while(1)
		{
			GetCursorPos(x,y,b);
			if(b == 1)
			{
				HideCursor();

				if(x > 610 && x < 640 && y > 0 && y < 30) QUIT();

				else if(f == 'y' && x > 150 && x < 250 && y > 270 && y < 300)
					TimeIN(id);
				else if(f == 'y' && x > 390 && x < 490 && y > 270 && y < 300)
					TimeOUT(id);

				else if(x > 240 && x < 400 && y > 40 && y < 70)
					{ MakeSearch(10,0,id,f); goto Begin; }

				else if(x > 0 && x < 30 && y > 0 && y < 30) break;

				ShowCursor();
			}
		}
	}
}
