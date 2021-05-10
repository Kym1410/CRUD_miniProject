#include <stdio.h>
#include <string.h>

typedef struct{
        char subject[15];
        int credit;
        int day;
        int hour;
} Subject;

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

int selectMenu(){
    int menu;
    printf("\n*** 점수계산기 ***\n");
    printf("1.시간표 조회\n");
    printf("2.과목 추가\n");
    printf("3.과목 수정\n");
    printf("4.과목 삭제\n");
    printf("5.시간표 출력\n");
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
int main(){
  Subject sub[10];
  int index = 0;
  int count = 0, menu;

  while(1){
      menu = selectMenu();

      if(menu == 0) break;
      if(menu == 2){
          count += createSubject(&sub[index++]);
      }
      if(menu == 1){
          if(count > 0 ) listTimetable(sub,index);
      }
      if(menu == 3){
          int no = selectList(sub, index);
          if(no > 0){
              updateSubject(&sub[no-1]);
          }
      }
      if(menu == 4){
          int no = selectList(sub, index);
          if(no>0){
              printf("정말로 삭제하시겠습니까?(1:삭제)");
              int delok;
              scanf("%d", &delok);
              if(delok == 1) deleteSubject(&sub[no-1]);
          }
      }
      if(menu == 5){
      	printTimetable(sub,count);
      }


  }




  return 0;
}
