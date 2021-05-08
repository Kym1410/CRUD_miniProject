#include <stdio.h>

typedef struct{
	char subject[10];
	int credit;
	int day;
	int hour;
	int yg;
} Subject;

int createSubject(Subject *s);
void readSubject(Subject s);
void updateSubject(Subject *s);
int deleteSubject(Subject *s);
void listTimetable(Subject *s[],int count);

void searchSubject(Subject *s, int count); //과목명 검색 함수
void serachDay(Subject *s, int count); //요일별 과목 검색 함수
void searchTime(Subject *s, int count); //시간별 과목 검색 함수
void saveSubject(Subject *s, int count); //과목 저장 함수
int loadSubject(Subject *s); //파일 로딩 함수
