#include <stdio.h>

typedef struct{
        char subject[10];
        int credit;
        int day;
        int hour;
        int yg;
} Subject;

int createSubject(Subject *s){
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
void readSubject(Subject s){
    printf("%s     %d      %d         %d\n", s.subject, s.credit, s.day, s.hour);
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
    printf("   과목명    학점     요일    시간\n");
    printf("--------------------------------\n");
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
    printf("0.종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int main(){
  Subject sub[4];
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


  }




  return 0;
}
