#include "Employee.h"

Employee :: Employee()
{
	struct date d;
	getdate(&d);
	yesterday = int(d.da_day);
	today = int(d.da_day);
	year = int(d.da_year);
	attended = 0;
	total = 1;
	TimeINh = 0;
	TimeOut = 0;
	gave_attendance = 'n';
}

void Employee :: SetDetails(int id, char name[], char post[], double salary, DOB &d)
{
	ID = id;
	strcpy(NAME,name);
	strcpy(POST,post);
	SALARY = salary;
	dob = d;
}
void Employee :: SetName(char name[]) {	strcpy(NAME, name); }
void Employee :: SetPost(char post[]) {	strcpy(POST, post); }
void Employee :: SetID(int id) 		  { ID = id; }
void Employee :: SetSalary(double salary) { SALARY = salary; }

char* Employee :: GetName() { return NAME; }
char* Employee :: GetPost() { return POST; }
int Employee :: GetID() { return ID; }
double Employee :: GetSalary() { return SALARY; }
DOB Employee :: GetDOB() { return dob; }

int Employee :: Year() { return year; }
void Employee :: Year(int y) { year = y; }

void Employee :: Present() { attended ++; }
void Employee :: AddDay() { total ++; }
int Employee :: Total() { return total; }
int Employee :: Attended() { return attended; }
char Employee :: Gave_Attendance() { return gave_attendance; }
void Employee :: Gave_Attendance(char x) { gave_attendance = x; }

int Employee :: Today() { return today; }
void Employee :: Today(int day) { today = day; }

int Employee :: Yesterday() { return yesterday; }
void Employee :: Yesterday(int day) { yesterday = day; }

void Employee :: TimeINH(int h) { TimeINh = h; }
void Employee :: TimeINM(int m) { TimeINm = m; }
void Employee :: TimeOUT(int h) { TimeOut = h; }
int Employee :: TimeINH() { return TimeINh; }
int Employee :: TimeINM() { return TimeINm; }
int Employee :: TimeOUT() { return TimeOut; }
void Employee :: ResetTime() { TimeINh = 0; }

int Employee :: Retire(int day, int mon, int year)
{
	if(dob.day == day && dob.month == mon && year - dob.year == 60) return 1;
	return 0;
}


void AddRecord(int id, char name[], char post[], double salary, DOB d)
{
	ofstream file("EMPLOYEE.DAT", ios::binary | ios::app);
	Employee x;

	x.SetDetails(id, name, post, salary, d);
	file.write((char*)&x, sizeof(x));

	file.close();
}

void DeleteRecord(int id)
{
	ifstream file("EMPLOYEE.DAT", ios::binary);
	ofstream temp("TEMP.DAT", ios::binary | ios::trunc);
	Employee x;

	while(file.read((char*)&x, sizeof(x)))
		if(x.GetID() != id) temp.write((char*)&x, sizeof(x));

	temp.close(); file.close();
	remove("EMPLOYEE.DAT");
	rename("TEMP.DAT", "EMPLOYEE.DAT");
}

void ModifyName(int id, char name[])
{
	fstream file("EMPLOYEE.DAT", ios::in | ios::out | ios::binary);
	Employee x;

	while(file.read((char*)&x, sizeof(x)))
	{
		if(id == x.GetID())
		{
			int pos = file.tellg() - sizeof(x);
			file.seekp(pos, ios::beg);
			x.SetName(name);
			file.write((char*)&x, sizeof(x));
		}
	}
}
void ModifyPost(int id, char post[])
{
	fstream file("EMPLOYEE.DAT", ios::in | ios::out | ios::binary);
	Employee x;

	while(file.read((char*)&x, sizeof(x)))
	{
		if(id == x.GetID())
		{
			int pos = file.tellg() - sizeof(x);
			file.seekp(pos, ios::beg);
			x.SetPost(post);
			file.write((char*)&x, sizeof(x));
		}
	}
}
void ModifySalary(int id, double salary)
{
	fstream file("EMPLOYEE.DAT", ios::in | ios::out | ios::binary);
	Employee x;

	while(file.read((char*)&x, sizeof(x)))
	{
		if(id == x.GetID())
		{
			int pos = file.tellg() - sizeof(x);
			file.seekp(pos, ios::beg);
			x.SetSalary(salary);
			file.write((char*)&x, sizeof(x));
		}
	}
}

char* Attendance(Employee x)
{
	char a[15];
	int Attended = x.Attended(), Total = x.Total();
	strcpy(a, Attended == 0 ? "0" : Convert(Attended));
	strcat(a," / ");
	strcat(a,Convert(Total));
	return a;
}

char* DateOfBirth(Employee x)
{
	char dob[15];
	DOB d = x.GetDOB();
	d.year %= 100;

	if(d.day < 10) { strcpy(dob, "0"); strcat(dob, Convert(d.day)); }
	else strcpy(dob, Convert(d.day));

	strcat(dob, "|");

	if(d.month < 10) strcat(dob, "0");
	strcat(dob, Convert(d.month));

	strcat(dob, "|");

	if(d.year < 10) strcat(dob, "0");
	strcat(dob,Convert(d.year));

	return dob;
}
