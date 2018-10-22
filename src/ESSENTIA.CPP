#include "Essentials.h"

void CountSeats()
{
	ifstream f("EMPLOYEE.DAT", ios::binary);
	Employee x;
	for(int i = 0; i < 10; i++) Seats[i][0] = 0;
	Seats[0][1] = 1; Seats[1][1] = 3; Seats[2][1] = 5; Seats[3][1] = 10;
	Seats[4][1] = 10; Seats[5][1] = 20; Seats[6][1] = 10; Seats[7][1] = 10;
	Seats[8][1] = 15; Seats[9][1] = 20;

	while(f.read((char*)&x, sizeof(x)))
	{
		if(!strcmpi(x.GetPost(),Desg[0])) Seats[0][0]++;
		else if(!strcmpi(x.GetPost(),Desg[1])) Seats[1][0]++;
		else if(!strcmpi(x.GetPost(),Desg[2])) Seats[2][0]++;
		else if(!strcmpi(x.GetPost(),Desg[3])) Seats[3][0]++;
		else if(!strcmpi(x.GetPost(),Desg[4])) Seats[4][0]++;
		else if(!strcmpi(x.GetPost(),Desg[5])) Seats[5][0]++;
		else if(!strcmpi(x.GetPost(),Desg[6])) Seats[6][0]++;
		else if(!strcmpi(x.GetPost(),Desg[7])) Seats[7][0]++;
		else if(!strcmpi(x.GetPost(),Desg[8])) Seats[8][0]++;
		else if(!strcmpi(x.GetPost(),Desg[9])) Seats[9][0]++;
	}
	f.close();

	for(i = 0; i < 10; i++) Seats[i][1] -= Seats[i][0];
}

void SORRY()
{
	setcolor(RED);
	settextstyle(0,HORIZ_DIR,5);
	outtextxy(200,200,"SORRY!");
	setcolor(LIGHTRED);
	settextstyle(0,HORIZ_DIR,2);
	outtextxy(150,250,"RECORD DOES NOT EXIST!");
}


void INIT()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, ".. /BGI");
}

void CloseButton()
{
	setcolor(RED);
	setfillstyle(SOLID_FILL, RED);
	bar(610, 0, 640, 30);
	setcolor(WHITE);
	settextstyle(0,HORIZ_DIR,2);
	outtextxy(618, 8, "X");
}

void BackButton()
{
	setcolor(LIGHTGRAY);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(0,0,30,30);
	setcolor(RED);
	settextstyle(0, HORIZ_DIR, 3);
	outtextxy(6,0,"-");
	outtextxy(6,5,"-");
	outtextxy(6,10,"-");
}


void BG()
{
	setfillstyle(SOLID_FILL, CYAN);
	bar(0,0,640,480);
}

void Patch(int x, int y, int w, int h)
{
	setcolor(CYAN);
	setfillstyle(SOLID_FILL, CYAN);
	bar(x,y,w,h);
}

void LOGO(int x, int y)
{
	setcolor(BLUE);
	setfillstyle(SOLID_FILL, BLUE);
	pieslice(x, y, 0, 360, 75);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL, BLACK);
	pieslice(x, y, 0, 360, 55);
	setcolor(LIGHTBLUE);
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	pieslice(x, y, 0, 360, 45);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL, BLACK);
	pieslice(x, y, 0, 360, 35);
}

void SearchBar(char id = 'n')
{
	setcolor(DARKGRAY);
	setfillstyle(SOLID_FILL, DARKGRAY);
	int handle[] = {420,83, 416,90, 420,92, 422,83, 420,83};
	circle(425, 75, 8);
	fillpoly(4, handle);

	setcolor(LIGHTGRAY);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	pieslice(450, 82, 0, 360, 10);
	pieslice(550, 82, 0, 360, 10);
	bar(450, 72, 550, 92);

	if(id == 'y')
	{
		setcolor(WHITE);
		settextstyle(0, HORIZ_DIR, 0);
		outtextxy(490, 80, "ID");
	}
}

void Desgs(char task, char desg[], double &sal)
{
	int x,y,b,post;

	if(task == 'm')
	{
		int L[] = {390,355, 420,250, 580,250, 580,450, 420,450, 390,380};
		int R[] = {230,355, 200,250, 40,250, 40,450, 200,450, 230,380};
		setfillstyle(SOLID_FILL, LIGHTGRAY);
		fillpoly(6,R);
		fillpoly(6,L);
		rectangle(40,250,200,450);
		rectangle(420,250,580,450);

		setfillstyle(SOLID_FILL, DARKGRAY);
		if(!Seats[0][1]) bar(40,250,200,290);
		if(!Seats[1][1]) bar(40,290,200,330);
		if(!Seats[2][1]) bar(40,330,200,370);
		if(!Seats[3][1]) bar(40,370,200,410);
		if(!Seats[4][1]) bar(40,410,200,450);
		if(!Seats[5][1]) bar(420,250,580,290);
		if(!Seats[6][1]) bar(420,290,580,330);
		if(!Seats[7][1]) bar(420,330,580,370);
		if(!Seats[8][1]) bar(420,330,580,410);
		if(!Seats[9][1]) bar(420,330,580,450);

		settextstyle(0,HORIZ_DIR,0);
		setcolor(BLACK);

		outtextxy(105,270,Desg[0]);
		line(40,290,200,290);
		outtextxy(83,310,Desg[1]);
		line(40,330,200,330);
		outtextxy(85,350,Desg[2]);
		line(40,370,200,370);
		outtextxy(80,390,Desg[3]);
		line(40,410,200,410);
		outtextxy(60,430,Desg[4]);

		outtextxy(442,270,Desg[5]);
		line(420,290,580,290);
		outtextxy(447,310,Desg[6]);
		line(420,330,580,330);
		outtextxy(445,350,Desg[7]);
		line(420,370,580,370);
		outtextxy(435,390,Desg[8]);
		line(420,410,580,410);
		outtextxy(435,430,Desg[9]);

		ShowCursor();
		start :
		{
			while(1)
			{
				GetCursorPos(x,y,b);
				if(b == 1)
				{
					if(x > 40 && x < 200 && y > 250 && y < 290) post = 0;
					else if(x > 40 && x < 200 && y > 290 && y < 330) post = 1;
					else if(x > 40 && x < 200 && y > 330 && y < 370) post = 2;
					else if(x > 40 && x < 200 && y > 370 && y < 410) post = 3;
					else if(x > 40 && x < 200 && y > 410 && y < 450) post = 4;
					else if(x > 420 && x < 580 && y > 250 && y < 290) post = 5;
					else if(x > 420 && x < 580 && y > 290 && y < 330) post = 6;
					else if(x > 420 && x < 580 && y > 330 && y < 370) post = 7;
					else if(x > 420 && x < 580 && y > 370 && y < 410) post = 8;
					else if(x > 420 && x < 580 && y > 410 && y < 450) post = 9;

					break;
				}
			}
		}

		if(!Seats[post][1]) goto start;

		strcpy(desg,Desg[post]);
		if(!strcmpi(Desg[post],Desg[0])) sal = 600000;
		else if(!strcmpi(Desg[post],Desg[1])) sal = 300000;
		else if(!strcmpi(Desg[post],Desg[2])) sal = 150000;
		else if(!strcmpi(Desg[post],Desg[3])) sal = 100000;
		else if(!strcmpi(Desg[post],Desg[4])) sal = 50000;
		else if(!strcmpi(Desg[post],Desg[5])) sal = 25000;
		else if(!strcmpi(Desg[post],Desg[6])) sal = 10000;
		else if(!strcmpi(Desg[post],Desg[7])) sal = 5000;
		else if(!strcmpi(Desg[post],Desg[8])) sal = 2000;
		else if(!strcmpi(Desg[post],Desg[9])) sal = 1000;
	}

	else
	{
		cleardevice();
		BG();
		setcolor(BLUE);
		CountSeats();
		settextstyle(3,HORIZ_DIR,4);
		outtextxy(170,30,"CHOOSE DESIGNATION");

		setfillstyle(SOLID_FILL,LIGHTGRAY);
		setcolor(BLACK);
		bar(50,100,590,450);
		line(320,100,320,450);

		setcolor(BLACK);
		settextstyle(1,HORIZ_DIR,3);

		outtextxy(160,110,Desg[0]);  outtextxy(400,110,Desg[1]);
		line(50,170,590,170);
		outtextxy(140,180,Desg[2]);  outtextxy(400,180,Desg[3]);
		line(50,240,590,240);
		outtextxy(90,250,Desg[4]);  outtextxy(365,250,Desg[5]);
		line(50,310,590,310);
		outtextxy(110,320,Desg[6]);  outtextxy(370,320,Desg[7]);
		line(50,380,590,380);
		outtextxy(80,390,Desg[8]);  outtextxy(360,390,Desg[9]);

		settextstyle(2,HORIZ_DIR,0);
		setcolor(BLACK);

		outtextxy(60,150,"STATUS : "); outtextxy(210,150,"SALARY : $600000");
		if(Seats[0][1])
		{
			setcolor(GREEN);
			outtextxy(110,150,"AVAILABLE");
			setcolor(BLACK);
		}
		else
		{
			setcolor(RED);
			outtextxy(110,150,"UNAVAILABLE");
			setcolor(BLACK);
		}

		outtextxy(330,150,"STATUS : ");  outtextxy(480,150,"SALARY : $300000");
		if(Seats[1][1])
		{
			setcolor(GREEN);
			outtextxy(380,150,"AVAILABLE");
			setcolor(BLACK);
		}
		else
		{
			setcolor(LIGHTRED);
			outtextxy(380,150,"UNAVAILABLE");
			setcolor(BLACK);
		}

		outtextxy(60,220,"STATUS : ");  outtextxy(210,220,"SALARY : $150000");
		if(Seats[2][1])
		{
			setcolor(GREEN);
			outtextxy(110,220,"AVAILABLE");
			setcolor(BLACK);
		}
		else
		{
			setcolor(RED);
			outtextxy(110,220,"UNAVAILABLE");
			setcolor(BLACK);
		}

		outtextxy(330,220,"STATUS : ");  outtextxy(480,220,"SALARY : $100000");
		if(Seats[3][1])
		{
			setcolor(GREEN);
			outtextxy(380,220,"AVAILABLE");
			setcolor(BLACK);
		}
		else
		{
			setcolor(LIGHTRED);
			outtextxy(380,220,"UNAVAILABLE");
			setcolor(BLACK);
		}

		outtextxy(60,290,"STATUS : ");  outtextxy(210,290,"SALARY : $50000");
		if(Seats[4][1])
		{
			setcolor(GREEN);
			outtextxy(110,290,"AVAILABLE");
			setcolor(BLACK);
		}
		else
		{
			setcolor(RED);
			outtextxy(110,290,"UNAVAILABLE");
			setcolor(BLACK);
		}

		outtextxy(330,290,"STATUS : "); outtextxy(480,290,"SALARY : $25000");
		if(Seats[5][1])
		{
			setcolor(GREEN);
			outtextxy(380,290,"AVAILABLE");
			setcolor(BLACK);
		}
		else
		{
			setcolor(LIGHTRED);
			outtextxy(380,290,"UNAVAILABLE");
			setcolor(BLACK);
		}

		outtextxy(60,360,"STATUS : ");  outtextxy(210,360,"SALARY : $10000");
		if(Seats[6][1])
		{
			setcolor(GREEN);
			outtextxy(110,360,"AVAILABLE");
			setcolor(BLACK);
		}
		else
		{
			setcolor(RED);
			outtextxy(110,360,"UNAVAILABLE");
			setcolor(BLACK);
		}

		outtextxy(330,360,"STATUS : ");  outtextxy(480,360,"SALARY : $5000");
		if(Seats[7][1])
		{
			setcolor(GREEN);
			outtextxy(380,360,"AVAILABLE");
			setcolor(BLACK);
		}
		else
		{
			setcolor(LIGHTRED);
			outtextxy(380,360,"UNAVAILABLE");
			setcolor(BLACK);
		}

		outtextxy(60,430,"STATUS : ");  outtextxy(210,430,"SALARY : $2000");
		if(Seats[8][1])
		{
			setcolor(GREEN);
			outtextxy(110,430,"AVAILABLE");
			setcolor(BLACK);
		}
		else
		{
			setcolor(RED);
			outtextxy(110,430,"UNAVAILABLE");
			setcolor(BLACK);
		}
		outtextxy(330,430,"STATUS : ");  outtextxy(480,430,"SALARY : $1000");
		if(Seats[9][1])
		{
			setcolor(GREEN);
			outtextxy(380,430,"AVAILABLE");
			setcolor(BLACK);
		}
		else
		{
			setcolor(LIGHTRED);
			outtextxy(380,430,"UNAVAILABLE");
			setcolor(BLACK);
		}

		ShowCursor();
		startn :
		{
			while(1)
			{
				GetCursorPos(x,y,b);
				if(b == 1)
				{
					HideCursor();
					if(x > 50 && x < 320 && y > 100 && y < 170) post = 0;
					else if(x > 320 && x < 590 && y > 100 && y < 170) post = 1;
					else if(x > 50 && x < 320 && y > 170 && y < 240) post = 2;
					else if(x > 320 && x < 590 && y > 170 && y < 240) post = 3;
					else if(x > 50 && x < 320 && y > 240 && y < 310) post = 4;
					else if(x > 320 && x < 590 && y > 240 && y < 310) post = 5;
					else if(x > 50 && x < 320 && y > 310 && y < 380) post = 6;
					else if(x > 320 && x < 590 && y > 310 && y < 380) post = 7;
					else if(x > 50 && x < 320 && y > 380 && y < 450) post = 8;
					else if(x > 320 && x < 590 && y > 380 && y < 450) post = 9;

					break;
				}
			}
		}
		ShowCursor();

		if(!Seats[post][1]) goto startn;

		strcpy(desg,Desg[post]);

		if(!strcmpi(Desg[post],Desg[0])) sal = 600000;
		else if(!strcmpi(Desg[post],Desg[1])) sal = 300000;
		else if(!strcmpi(Desg[post],Desg[2])) sal = 150000;
		else if(!strcmpi(Desg[post],Desg[3])) sal = 100000;
		else if(!strcmpi(Desg[post],Desg[4])) sal = 50000;
		else if(!strcmpi(Desg[post],Desg[5])) sal = 25000;
		else if(!strcmpi(Desg[post],Desg[6])) sal = 10000;
		else if(!strcmpi(Desg[post],Desg[7])) sal = 5000;
		else if(!strcmpi(Desg[post],Desg[8])) sal = 2000;
		else if(!strcmpi(Desg[post],Desg[9])) sal = 1000;
	}

	cleardevice();
}


void SearchTable(int id, int permission)
{
	ifstream f("EMPLOYEE.DAT", ios::binary);
	Employee x;

	char got = 'n';

	while(f.read((char*)&x, sizeof(x)))
		if(x.GetID() == id) { got = 'y'; break; }

	f.close();

	cleardevice();
	BG();
	CloseButton();
	BackButton();
	setcolor(BLUE);
	settextstyle(0,HORIZ_DIR,0);
	outtextxy(440,100,"'* ' to go back");

	setcolor(BLUE);
	settextstyle(3, HORIZ_DIR, 4);
	outtextxy(160,10,"EMPLOYEE DATABASE");
	setcolor(BLACK);
	setfillstyle(SOLID_FILL, BLACK);
	bar(150,50,480,52);
	setcolor(RED);
	setfillstyle(SOLID_FILL, RED);
	pieslice(317,51,0,360,1);

	SearchBar('y');


	if(got == 'y')
	{
		char post[15];
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, DARKGRAY);
		bar(20, 110, 620, 130);
		rectangle(20, 110, 620, 160);

		setcolor(LIGHTGRAY);
		settextstyle(0, HORIZ_DIR, 1);
		outtextxy(45, 117, "ID");
		outtextxy(100, 117, "Employee Name");
		outtextxy(230, 117, "D.O.B");
		outtextxy(310, 117, "Designation");
		outtextxy(430, 117, "Salary");
		outtextxy(520, 117, "Attendance");

		setcolor(BLACK);

		outtextxy(45, 140, Convert(x.GetID()));
		outtextxy(100, 140, x.GetName());
		outtextxy(220, 140, DateOfBirth(x));
		strcpy(post,x.GetPost());
		if(!strcmpi(post,Desg[8])) strcpy(post,"Software Engg");
		else if(!strcmpi(post, Desg[9])) strcpy(post,"Trainee Engg");
		outtextxy(310, 140, post);
		outtextxy(430, 140, Convert(x.GetSalary()));
		outtextxy(520, 140, Attendance(x));

		if(permission == 1)
		{
			setcolor(RED);
			setfillstyle(SOLID_FILL, RED);
			bar(220, 180, 280, 210);
			bar(335, 180, 395, 210);

			setcolor(WHITE);
			settextstyle(0, HORIZ_DIR, 0);

			outtextxy(225, 190, "DELETE");
			outtextxy(340, 190, "MODIFY");
		}
	}

	else SORRY();
}

void DateAndTime(char p = 'x')
{
	time_t t;
	time(&t);

	char *gettime;
	strcpy(gettime, ctime(&t));
	int l = strlen(gettime);
	gettime[l - 6] = '\0';

	if(p == 'm')
	{
		Patch(240,90,600,150);
		setcolor(BLACK);
		settextstyle(0, HORIZ_DIR, 2);
		outtextxy(240, 90, gettime);
		Patch(400,90,600,150);
		setcolor(BLACK);
		gettime += 10;
		gettime[strlen(gettime)-3] = '\0';
		outtextxy(260,125,gettime);
	}

	else
	{
		Patch(50,25,130,55);
		setcolor(BLACK);
		settextstyle(2, HORIZ_DIR, 5);
		gettime[strlen(gettime)-3] = '\0';
		outtextxy(160, 55, gettime);
	}
}

char DeleteButton()
{
	setcolor(LIGHTGRAY);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(230,250,390,320);

	setcolor(DARKGRAY);
	setfillstyle(SOLID_FILL, DARKGRAY);
	bar(230,300,390,320);

	setcolor(BLACK);
	setfillstyle(SOLID_FILL, BLACK);
	bar(308,300,312,320);

	setcolor(LIGHTGRAY);
	settextstyle(0, HORIZ_DIR, 0);
	outtextxy(260,307,"YES");
	outtextxy(342,307,"NO");

	setcolor(BLACK);
	outtextxy(245,265,"ARE YOU SURE?");

	return 'y';
}

char ModifyButton()
{
	setcolor(DARKGRAY);
	setfillstyle(SOLID_FILL, DARKGRAY);
	bar(230,250,390,300);
	setcolor(LIGHTGRAY);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(230,300,390,450);

	setcolor(WHITE);
	settextstyle(0, HORIZ_DIR, 0);
	outtextxy(235,270,"CHOOSE MODIFICATION");

	setcolor(BLACK);

	line(230,300,390,300);
	line(230,350,390,350);
	line(230,400,390,400);
	line(230,450,390,450);
	line(390,300,390,450);

	outtextxy(295,325,"NAME");
	outtextxy(268,375,"DESIGNATION");
	outtextxy(285,425,"SALARY");

	return 'y';
}

void Modify_Name(int id)
{
	setcolor(BLACK);
	setfillstyle(SOLID_FILL, BLACK);
	bar(400,310,560,340);

	setcolor(WHITE);

	char* name = '\0', ch;
	int i = 0;

	while(1)
	{
		if(kbhit())
		{
			ch = getch();

			if(ch == 13) break;

			else if(ch == 8)
			{
				if(i > 0)
				{
					setcolor(BLACK);
					setfillstyle(SOLID_FILL, BLACK);
					bar(400,310,560,340);

					setcolor(WHITE);

					i--;
					name[i] = '\0';
					outtextxy(410,320,name);
				}
			}

			else if(i <= 20)
			{
				name[i] = ch;
				name[i+1] = '\0';
				i++;
				outtextxy(410,320,name);
			}
		}
	}

	if(i == 0) return;

	ModifyName(id, name);

	cleardevice();
	BG();
	SearchTable(id,1);
	ModifyButton();
}

void Modify_Designation(int id)
{
	char post[30];
	double sal;
	Desgs('m',post,sal);

	ModifyPost(id, post);
	ModifySalary(id, sal);

	cleardevice();
	BG();
	SearchTable(id,1);
	ModifyButton();
}

void Modify_Salary(int id)
{
	setcolor(BLACK);
	setfillstyle(SOLID_FILL, BLACK);
	bar(400,410,560,440);

	setcolor(WHITE);

	char salary[9], ch;
	int i = 0;

	while(1)
	{
		if(kbhit())
		{
			ch = getch();

			if(ch == 13) break;

			else if(ch == 8)
			{
				if(i > 0)
				{
					setcolor(BLACK);
					setfillstyle(SOLID_FILL, BLACK);
					bar(400,410,560,440);

					setcolor(WHITE);

					i--;
					salary[i] = '\0';
					outtextxy(410,420,salary);
				}
			}

			else if(i <= 9 && isdigit(ch))
			{
				salary[i] = ch;
				salary[i+1] = '\0';
				i++;
				outtextxy(410,420,salary);
			}
		}
	}

	if(i == 0) return;

	double sal = Convert(salary);

	ModifySalary(id, sal);

	cleardevice();
	BG();
	SearchTable(id,1);
	ModifyButton();
}

int New_ID()
{
	setcolor(LIGHTGRAY);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(160, 180, 320, 220);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL, BLACK);
	bar(320, 180, 480, 220);
	outtextxy(230,198,"ID");
	setcolor(DARKGRAY);
	rectangle(160,180,320,220);
	rectangle(320,180,480,220);

	char* ID = '\0', ch;
	int i = 0, Id;
	setcolor(WHITE);
	settextstyle(0,HORIZ_DIR,0);

	getID :
	{
		while(1)
		{
			if(kbhit())
			{
				ch = getch();

				if(ch == 13) break;

				else if(ch == 8)
				{
					if(i > 0)
					{
						setcolor(BLACK);
						setfillstyle(SOLID_FILL, BLACK);
						bar(320,180,480,220);
						setcolor(DARKGRAY);
						rectangle(320,180,480,220);

						setcolor(WHITE);

						i--;
						ID[i] = '\0';
						outtextxy(330,195,ID);
					}
				}

				else if(i <= 10 && isdigit(ch))
				{
					ID[i] = ch;
					ID[i+1] = '\0';
					i++;
					outtextxy(330,195,ID);
				}
			}
		}
	}

	if(i == 0)
	{
		setcolor(LIGHTRED);
		settextstyle(0,HORIZ_DIR,1);
		outtextxy(290,240,"THIS IS A REQUIRED FIELD");
		setcolor(WHITE);
		settextstyle(0,HORIZ_DIR,0);
		goto getID;
	}

	else
	{
		Id = Convert(ID);
		ifstream file("EMPLOYEE.DAT", ios::binary);
		Employee x;

		char got = 'n';

		while(file.read((char*)&x, sizeof(x)))
			if(Id == x.GetID()) { got = 'y'; break; }
		file.close();

		if(got == 'y')
		{
			setcolor(LIGHTRED);
			settextstyle(0,HORIZ_DIR,1);
			outtextxy(290,240,"THIS ID EXISTS");
			setcolor(WHITE);
			settextstyle(0,HORIZ_DIR,0);
			goto getID;
		}
	}

	return Id;
}

char* New_Name()
{
	setcolor(LIGHTGRAY);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(160, 220, 320, 260);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL, BLACK);
	bar(320, 220, 480, 260);
	outtextxy(225,238,"NAME");
	setcolor(DARKGRAY);
	rectangle(160,220,320,260);
	rectangle(320,220,480,260);

	char name[30], ch;
	int i = 0;
	setcolor(WHITE);

	getname :
	{
		while(1)
		{
			if(kbhit())
			{
				ch = getch();

				if(ch == 13) break;

				else if(ch == 8)
				{
					if(i > 0)
					{
						setcolor(BLACK);
						setfillstyle(SOLID_FILL, BLACK);
						bar(320,220,480,260);
						setcolor(DARKGRAY);
						rectangle(320,220,480,260);

						setcolor(WHITE);

						i--;
						name[i] = '\0';
						outtextxy(330,235,name);
					}
				}

				else if(i <= 20)
				{
					name[i] = ch;
					name[i+1] = '\0';
					i++;
					outtextxy(330,235,name);
				}
			}
		}
	}

	if(i == 0)
	{
		setcolor(LIGHTRED);
		settextstyle(0,HORIZ_DIR,1);
		outtextxy(290,280,"THIS IS A REQUIRED FIELD");
		setcolor(WHITE);
		settextstyle(0,HORIZ_DIR,0);
		goto getname;
	}

	return name;
}

DOB New_DOB()
{
	setcolor(LIGHTGRAY);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(160, 260, 320, 300);
	setcolor(BLACK);
	outtextxy(220,278,"D.O.B");
	setcolor(DARKGRAY);
	rectangle(160,260,320,300);
	rectangle(320,260,480,300);

	char d[3], m[3], y[5], ch;
	int i,j,k;
	DOB dob;

	getday :
	{
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, BLACK);
		bar(320, 260, 360, 300);
		setcolor(LIGHTGRAY);
		outtextxy(330, 275, "DD");

		i = 0;

		while(i < 2)
		{
			if(kbhit())
			{
				ch = getch();

				setcolor(BLACK);
				setfillstyle(SOLID_FILL, BLACK);
				bar(320,260,360,300);
				setcolor(DARKGRAY);
				rectangle(320,260,360,300);

				setcolor(WHITE);

				if(ch == 8)
				{
					if(i > 0)
					{
						setcolor(BLACK);
						setfillstyle(SOLID_FILL, BLACK);
						bar(320,260,360,300);
						setcolor(DARKGRAY);
						rectangle(320,260,360,300);

						setcolor(WHITE);

						i--;
						d[i] = '\0';
						outtextxy(330,275,d);
					}
				}

				else if(isdigit(ch))
				{
					d[i] = ch;
					d[i+1] = '\0';
					i++;
					outtextxy(330,275,d);
				}
			}
		}

		i = Convert(d);
		if(i > 31)
		{
			setcolor(LIGHTRED);
			settextstyle(0,HORIZ_DIR,1);
			outtextxy(290,320,"ENTER CORRECTLY -_-");
			setcolor(WHITE);
			settextstyle(0,HORIZ_DIR,0);
			goto getday;
		}
	}
	Patch(290, 310, 500, 330);

	getmon:
	{
		i = 0;
		setfillstyle(SOLID_FILL, BLACK);
		bar(370, 260, 410, 300);
		setcolor(LIGHTGRAY);
		outtextxy(380, 275, "MM");

		while(i < 2)
		{
			if(kbhit())
			{
				ch = getch();

				setcolor(BLACK);
				setfillstyle(SOLID_FILL, BLACK);
				bar(370,260,410,300);
				setcolor(DARKGRAY);
				rectangle(370,260,410,300);

				setcolor(WHITE);

				if(ch == 8)
				{
					if(i > 0)
					{
						setcolor(BLACK);
						setfillstyle(SOLID_FILL, BLACK);
						bar(370,260,410,300);
						setcolor(DARKGRAY);
						rectangle(370,260,410,300);

						setcolor(WHITE);
						i--;
						m[i] = '\0';
						outtextxy(380,275,m);
					}
				}

				else if(isdigit(ch))
				{
					m[i] = ch;
					m[i+1] = '\0';
					i++;
					outtextxy(380,275,m);
				}
			}
		}

		i = Convert(d);
		j = Convert(m);

		if(j > 12 ||
		  (i == 31 && (j == 2 || j == 4 || j == 6 || j == 9 || j == 11)) ||
		  (j == 2 && i > 29))
		{
			setcolor(LIGHTRED);
			settextstyle(0,HORIZ_DIR,1);
			outtextxy(290,320,"ENTER CORRECTLY -_-");
			setcolor(WHITE);
			settextstyle(0,HORIZ_DIR,0);
			goto getmon;
		}
	}
	Patch(290, 310, 500, 330);

	getyear:
	{
		i = 0;
		setfillstyle(SOLID_FILL, BLACK);
		bar(420, 260, 480, 300);
		setcolor(LIGHTGRAY);
		outtextxy(430, 275, "YYYY");

		while(i < 4)
		{
			if(kbhit())
			{
				ch = getch();

				setcolor(BLACK);
				setfillstyle(SOLID_FILL, BLACK);
				bar(420,260,480,300);
				setcolor(DARKGRAY);
				rectangle(420,260,480,300);

				setcolor(WHITE);

				if(ch == 8)
				{
					if(i > 0)
					{
						setcolor(BLACK);
						setfillstyle(SOLID_FILL, BLACK);
						bar(420,260,480,300);
						setcolor(DARKGRAY);
						rectangle(420,260,480,300);

						setcolor(WHITE);

						i--;
						y[i] = '\0';
						outtextxy(430,275,y);
					}
				}

				else if(isdigit(ch))
				{
					y[i] = ch;
					y[i+1] = '\0';
					i++;
					outtextxy(430,275,y);
				}
			}
		}

		i = Convert(d);
		j = Convert(m);
		k = Convert(y);
		if(i == 29 && j == 2 && LeapYear(k) == 0)
		{
			setcolor(LIGHTRED);
			settextstyle(0,HORIZ_DIR,1);
			outtextxy(290,320,"ENTER CORRECTLY -_-");
			setcolor(WHITE);
			settextstyle(0,HORIZ_DIR,0);
			goto getyear;
		}
	}

	dob.day = Convert(d);
	dob.month = Convert(m);
	dob.year = Convert(y);

	return dob;
}

void NewRecord()
{
	cleardevice();
	BG();

	CountSeats();
	char seats = 'n';
	for(int i = 0; i < 10; i++)
		if(Seats[i][1] > 0) { seats = 'y'; break; }


	if(seats == 'y')
	{
		int id;
		char name[20], post[20];
		double salary;
		DOB dob;

		settextstyle(0,HORIZ_DIR,0);

		id = New_ID();
		strcpy(name, New_Name());
		dob = New_DOB();
		Desgs('n',post,salary);

		AddRecord(id, name, post, salary, dob);
	}

	else
	{
		setcolor(RED);
		settextstyle(0,HORIZ_DIR,5);
		outtextxy(200,200,"SORRY!");
		setcolor(LIGHTRED);
		settextstyle(0,HORIZ_DIR,2);
		outtextxy(150,250,"NO MORE SEATS AVAILABLE!");
		getch();
	}
}

