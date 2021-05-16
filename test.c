#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "timetable.h"

int main(){
  Subject sub[100];
  int index = 0;
  int count = 0, menu;

    count = loadTimetable(sub);
    index = count;
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
      if(menu == 6){
          saveTimetable(sub,index);
      }
      if(menu == 7){
          searchSubject(sub,index);
      }
      if(menu == 8){
          searchCredit(sub,index);
      }
      if(menu == 9){
          searchDay(sub,index);
      }
      if(menu == 10){
          searchHour(sub,index);
      }
  }
  return 0;
}
