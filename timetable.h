#include <stdio.h>

typedef struct{
	char subject[15];
	int credit;
	int day;
	int hour;
} Subject;

int createSubject(Subject *s); // 과목 생성 함수
void readSubject(Subject s); // 과목 출력 함수
int updateSubject(Subject *s); // 과목 수정 함수
int deleteSubject(Subject *s); // 과목 삭제 함수
void listTimetable(Subject *s, int count); //과목 출력 helper 함수
void printTimetable(Subject s[],int count); // 시간표 출력 함수
char* searchDayHour(Subject s[], int count, int day, int hour); //시간표 출력 helper 함수

int selectMenu(); // 기능 선택
void searchCredit(Subject *s, int count); //학점 검색 함수
void searchSubject(Subject *s, int count); //과목명 검색 함수
void searchDay(Subject *s, int count); //요일별 과목 검색 함수
void searchHour(Subject *s, int count); //시간별 과목 검색 함수
void saveTimetable(Subject *s, int count); //과목 저장 함수
int loadTimetable(Subject *s); //파일 로딩 함수
int selectList(Subject *s, int count); // 선택한 번호 찾기 함수
