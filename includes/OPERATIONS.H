#ifndef OPERATIONS
#define OPERATIONS

#include "Headers.h"

union REGS in, out;

char* Desg[10] = {"CEO", "President", "Director", "Architect", "Program Manager", "Project Manager","Project Lead", "System Analyst", "Software Engineer","Trainee Engineer"};

int Seats[10][2] = {0,1,0,3,0,5,0,10,0,10,0,20,0,10,0,10,0,15,0,20};

void GetCursorPos(int &x, int &y, int &b);
void ShowCursor();
void HideCursor();
void QUIT();
char* Convert(long x);
double Convert(char* x);
int LeapYear(int year);

#endif
