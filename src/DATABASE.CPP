#include "Database.h"

void Table(int permission = 0)
{
	ifstream file("EMPLOYEE.DAT", ios::binary);
	Employee x;
	char* id, salary;
	char post[15];
	int y = 140;

	BG();
	CloseButton();
	BackButton();

	setcolor(BLUE);
	settextstyle(3, HORIZ_DIR, 4);
	outtextxy(160,10,"EMPLOYEE DATABASE");

	for(int i = 317,j = 317; i <= 480,j >= 150; i += 5,j -= 5)
	{
		setcolor(RED);
		setfillstyle(SOLID_FILL, RED);
		pieslice(317,51,0,360,3);
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, BLACK);
		bar(i,50,i+5,52);
		bar(j,50,j-5,52);
		delay(10);
	}
	setcolor(RED);
	setfillstyle(SOLID_FILL, RED);
	pieslice(317,51,0,360,1);

	SearchBar('y');
	if(permission == 1)
	{
		setcolor(RED);
		setfillstyle(SOLID_FILL, RED);
		bar(60, 72, 160, 92);

		setcolor(WHITE);
		settextstyle(0, HORIZ_DIR, 0);
		outtextxy(70,78,"ADD RECORD");
	}

	setcolor(BLACK);
	setfillstyle(SOLID_FILL, DARKGRAY);
	bar(20, 110, 620, 130);
	rectangle(20, 110, 620, 450);

	setcolor(LIGHTGRAY);
	settextstyle(0, HORIZ_DIR, 1);
	outtextxy(45, 117, "ID");
	outtextxy(100, 117, "Employee Name");
	outtextxy(230, 117, "D.O.B");
	outtextxy(310, 117, "Designation");
	outtextxy(430, 117, "Salary");
	outtextxy(520, 117, "Attendance");

	setcolor(BLACK);

	while(file.read((char*)&x, sizeof(x)))
	{
		outtextxy(45, y, Convert(x.GetID()));
		outtextxy(100, y, x.GetName());
		outtextxy(220, y, DateOfBirth(x));
		strcpy(post,x.GetPost());
		if(!strcmpi(post,Desg[8])) strcpy(post,"Software Engg");
		else if(!strcmpi(post, Desg[9])) strcpy(post,"Trainee Engg");
		outtextxy(310, y, post);
		outtextxy(430, y, Convert(x.GetSalary()));
		outtextxy(520, y, Attendance(x));

		y += 10;
	}

	file.close();
}

int Search(int permission = 0)
{
	char *c, ch;
	int i = 0;

	SearchBar();
	setcolor(BLACK);
	settextstyle(0,HORIZ_DIR,0);

	while(1)
	{
		ch = getch();

		if(ch == 13 || ch == '*') break;
		else if(isdigit(ch)) { c[i] = ch; i++; }

		else if(ch == 8)
		{
			i--;
			SearchBar();
		}

		c[i] = '\0';
		outtextxy(455,80,c);
	 }

	 if(ch == '*') { Table(permission); return 0; }
	 else
	 {
		long ID = Convert(c);
		SearchTable(ID, permission);
		return ID;
	 }
}

void DATABASE()
{
	Table();
	DateAndTime();
	ShowCursor();
	int x,y,b;

	struct time t;
	int init_time = 0, final_time = 1;

	while(1)
	{
		gettime(&t);
		final_time = int(t.ti_min);

		GetCursorPos(x,y,b);
		if(b == 1)
		{
			if(x > 450 && x < 550 && y > 72 && y < 92) Search();
			else if(x > 610 && x < 640 && y > 0 && y < 30) QUIT();
			else if(x > 0 && x < 30 && y > 0 && y < 30) break;
		}

		if(init_time != final_time)
		{
			DateAndTime();
			init_time = final_time;
		}
	}
}