#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "timetable.h"
int createSubject(Subject *s){
    printf("수강할 과목명(세글자): ");
    scanf("%s", s->subject);
    printf("과목 학점: ");
    scanf("%d", &s->credit);
    printf("요일(월:1 화:2 수:3 목:4 금:5): ");
    scanf("%d", &s->day);
    printf("교시: ");
    scanf("%d", &s->hour);

    return 1;
}
void readSubject(Subject s){
    char weekDay[15];
        switch(s.day){
            case 1 :
                strcpy(weekDay,"월");
               break;
            case 2 :
                strcpy(weekDay,"화");
               break;
            case 3 :
                strcpy(weekDay,"수");
               break;
            case 4 :
                strcpy(weekDay,"목");
               break;
            case 5 :
                strcpy(weekDay,"금");
               break;
            defaul:
               break;
    }
    printf("\t%s\t%d\t%s\t%d\n", s.subject, s.credit, weekDay, s.hour);

}
int updateSubject(Subject *s){
    printf("수강할 과목명: ");
    scanf("%s", s->subject);
    printf("과목 학점: ");
    scanf("%d", &s->credit);
    printf("요일: ");
    scanf("%d", &s->day);
    printf("시간: ");
    scanf("%d", &s->hour);

    return 1;

}
int deleteSubject(Subject *s){
    s->hour = 0;
    printf("=> 삭제됨!\n");
    return 1;
}
void listTimetable(Subject *s, int count){
    printf("\t과목명\t학점\t요일\t시간\n");
    printf("-----------------------------------\n");
    for(int i=0; i<count; i++){
        if(s[i].hour == 0) continue;
        printf("%d ", i+1);
        readSubject(s[i]);
    }
}
int selectList(Subject *s, int count){
    int no;
    listTimetable(s, count);
    printf("번호는(취소:0)? ");
    scanf("%d",&no);
    return no;
}
void saveTimetable(Subject *s, int count){
    FILE *fp;
    fp = fopen("Timetable.txt","wt");

    for(int i=0; i<count; i++){
        if(s[i].hour == 0) continue;
        fprintf(fp, "%s %d %d %d\n",s[i].subject,s[i].credit,s[i].day, s[i].hour);
    }
    fclose(fp);
    printf("=>저장됨! ");
}
int loadTimetable(Subject *s){
    FILE *fc;
    int i;
    fc = fopen("Timetable.txt","rt");

    if(fc!=NULL){
        for(i=0; i<100; i++){
            fscanf(fc,"%s", s[i].subject);
            fscanf(fc,"%d", &s[i].credit);
            fscanf(fc,"%d", &s[i].day);
            fscanf(fc,"%d", &s[i].hour);
            if(feof(fc)){
                break;
            }
        }
        printf("=>로딩 성공\n");
    }
    else printf("데이터 없음\n");

    fclose(fc);
    return i;
}
void searchSubject(Subject *s, int count){
    int scnt = 0;
    char search[30];

    printf("검색할 과목: ");
    scanf("%s", search);

    printf("\t과목명\t학점\t요일\t시간\n");
    printf("-----------------------------------\n");

    for(int i=0; i<count; i++){
        if(s[i].hour == 0) continue;
        if(strstr(s[i].subject,search)){
            printf("%2d",i+1);
            readSubject(s[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=>검색된 과목 없음!\n");

}

void searchCredit(Subject *s, int count){
    int scnt = 0;
    int search;

    printf("검색할 학점(1/2/3): ");
    scanf("%d", &search);

    printf("\t과목명\t학점\t요일\t시간\n");
    printf("-----------------------------------\n");

    for(int i = 0; i<count; i++){
        if(s[i].hour == 0) continue;
        if(s[i].credit == search){
            printf("%2d",i+1);
            readSubject(s[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("검색된 과목 없음!\n");

}
void searchDay(Subject *s, int count){
    int scnt = 0;
    int search;
    printf("검색할 요일(월:1 화:2 수:3 목:4 금:5): ");
    scanf("%d",&search);
    printf("\t과목명\t학점\t요일\t시간\n");
    printf("-----------------------------------\n");
    for(int i = 0; i<count; i++){
        if(s[i].hour == 0) continue;
        if(s[i].day == search){
            printf("%2d",i+1);
            readSubject(s[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("검색된 과목 없음!\n");

}
void searchHour(Subject *s, int count){
    int scnt = 0;
    int search;
    printf("검색할 시간(1 ~ 7교시): ");
    scanf("%d",&search);
    printf("\t과목명\t학점\t요일\t시간\n");
    printf("-----------------------------------\n");

    for(int i = 0; i<count; i++){
        if(s[i].hour == 0) continue;
        if(s[i].hour == search){
            printf("%2d",i+1);
            readSubject(s[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("검색된 과목 없음!\n");
}
int selectMenu(){
    int menu;
    printf("\n*** 점수계산기 ***\n");
    printf("1.시간표 조회\n");
    printf("2.과목 추가\n");
    printf("3.과목 수정\n");
    printf("4.과목 삭제\n");
    printf("5.시간표 출력\n");
    printf("6.시간표 저장\n");
    printf("7.과목 검색\n");
    printf("8.학점 검색\n");
    printf("9.요일 검색\n");
    printf("10.시간 검색\n");
    printf("0.종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}
char* searchDayHour(Subject s[], int count, int day, int hour){
        for(int i=0; i<count; i++){
                        if(s[i].day == day && s[i].hour == hour)
                                return s[i].subject;
        }
        return 0;
}
void printTimetable(Subject s[],int count){
        int doubleArray[10][5] = {0};
        for(int i=0; i<count; i++){
                doubleArray[(s[i].hour)-1][(s[i].day)-1] = 1;
        }
        char temp[10];
        printf("\t월\t화\t수\t목\t금\n");
        printf("----------------------------------------\n");
        for(int j=0; j<10;j++){
                printf("%d교시\t",j+1);
                for(int k=0; k<5; k++){
                        if(doubleArray[j][k] == 1){
                                strcpy(temp,searchDayHour(s, count, k+1, j+1));
                                printf("%s\t", temp);
                        }
                        else printf("\t");
                }
                printf("\n");
        }

}

