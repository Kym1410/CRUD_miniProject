#include <stdio.h>

typedef struct{
	char[10] subject;
	int credit;
	int day;
	int hour;
	int yg;
} Subject;

int createSubject(Subject *s);
void readSubject(Subject *s);
void updateSubject(Subject *s);
int deleteSubject(Subject *s);
void printTimetable(Subject s[]);
