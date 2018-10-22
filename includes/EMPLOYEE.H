#ifndef EMPLOYEE
#define EMPLOYEE 

#include "Operations.h"


struct DOB
{
	int day;
	int month;
	int year;
};

class Employee
{
	int ID;
	char NAME[30], POST[20];
	double SALARY;

	int today, yesterday, total, attended, year;
	int TimeINh, TimeINm, TimeOut;

	char gave_attendance;

	DOB dob;

	public:

		Employee();

		void SetDetails(int id, char name[], char post[], double salary, DOB &d);
		void SetName(char name[]);
		void SetPost(char post[]);
		void SetID(int id);
		void SetSalary(double salary);

		char* GetName();
		char* GetPost();
		int GetID();
		double GetSalary();
		DOB GetDOB();

		int Year();
		void Year(int y);

		void Present();
		void AddDay();
		int Total();
		int Attended();
		char Gave_Attendance();
		void Gave_Attendance(char x);

		int Today();
		void Today(int day);

		int Yesterday();
		void Yesterday(int day);

		void TimeINH(int h);
		void TimeINM(int m);
		void TimeOUT(int h);
		int TimeINH();
		int TimeINM();
		int TimeOUT();
		void ResetTime();

		int Retire(int day, int mon, int year);
};

void AddRecord(int id, char name[], char post[], double salary, DOB d);
void DeleteRecord(int id);
void ModifyName(int id, char name[]);
void ModifyPost(int id, char post[]);
void ModifySalary(int id, double salary);
char* Attendance(Employee x);
char* DateOfBirth(Employee x);

#endif