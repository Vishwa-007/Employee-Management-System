/* Employee Management System
	Class 12 project
	written by : Vishwa
	Admin password : Admin@007
*/

#include "headers.h"
#include "Operations.h"
#include "Employee.h"
#include "Essentials.h"
#include "Database.h"
#include "Admin.h"
#include "Attendance.h"
#include "Menu.h"

void OpenScreen()
{
	INIT();
	setcolor(CYAN);
	settextstyle(3,HORIZ_DIR,8);
	outtextxy(100,100,"VISHWA");
	outtextxy(300,180,"TECH");

	setcolor(YELLOW);
	settextstyle(0,HORIZ_DIR,0);
	outtextxy(300,280,"The birthplace of mordern technology....");

	delay(500);

	setcolor(RED);
	outtextxy(100,350,"LOADING...");

	setcolor(LIGHTGREEN);
	setfillstyle(SOLID_FILL, LIGHTGREEN);

	for(int i = 150, j = 20; i < 450, j < 320; i += 5, j += 5)
	{
		sound(j);
		bar(i,370,i+5,382);
		pieslice(i+5,376,0,360,6);
		delay(10);
		nosound();
	}
	delay(100);

	for(i = 0; i < 2; i++)
	{
		sound(500);
		delay(200);
		nosound();
		delay(100);
	}

	delay(500);
}

void CheckUp()
{
	fstream file("EMPLOYEE.DAT", ios::binary | ios::in | ios::out);
	Employee x;

	struct date d;
	getdate(&d);

	int count = 0;
	int day = int(d.da_day), mon = int(d.da_mon), year = int(d.da_year);

	start:
	{
		int i = 0;
		char del = 'n';

		while(file.read((char*)&x, sizeof(x)))
		{
			if(i < count) { i++; continue; }
			else
			{
				count++;

				int pos = file.tellg() - sizeof(x);
				file.seekg(pos, ios::beg);

				if(x.Retire(day, mon, year) == 1) { del = 'y'; break; }

				x.Today(day);

				if(x.Today() != x.Yesterday())
				{
					int difference = x.Today() - x.Yesterday();
					for(int i = 0; i < difference; i++)	x.AddDay();

					x.Yesterday(day);
					x.ResetTime();
					x.Gave_Attendance('n');
				}

				if(x.Year() != year)
				{
					int difference = year - x.Year();
					double sal, inc;

					for(int i = 0; i < difference; i++)
					{
						sal = x.GetSalary();
						inc = sal * 0.1;
						sal += inc;
						x.SetSalary(sal);
					}

					x.Year(year);
				}

				file.write((char*)&x, sizeof(x));
			}
		}
		file.close();

		if(del == 'y')
		{
			DeleteRecord(x.GetID());
			goto start;
		}
	}

}


void main()
{
	CheckUp();
	INIT();
	OpenScreen();
	MENU();
}