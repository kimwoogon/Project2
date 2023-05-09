#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1();
void filestat2();
void filetime1();
void filetime2();
void sizecmp();
void blockcmp();
void datecmp();
void timecmp();

int main(){
   filestat1();
   filestat2();
   filetime1();
   filetime2();
   sizecmp();
   blockcmp();
   datecmp();
   timecmp();
   return 0;
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1(){
   stat("text1", &stat1);
   return;
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(){
   stat("text2", &stat2);
   return;
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(){
   time1 = localtime(&stat1.st_mtime);
   return;
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(){
   time2 = localtime(&stat2.st_mtime);
   return;
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(){
    printf("size compare\n");
    if ((int)stat1.st_size > (int)stat2.st_size) {
        printf("text1 is bigger\n");
    }
    else if ((int)stat1.st_size == (int)stat2.st_size) {
        printf("sizes are equal\n");
    }
    else {
        printf("text2 is bigger\n");
    }
    return;
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(){
    printf("block compare\n");
    if ((int)stat1.st_blocks > (int)stat2.st_blocks) {
        printf("text1 is bigger\n");
    }
    else if ((int)stat1.st_blocks == (int)stat2.st_blocks) {
        printf("sizes are equal\n");
    }
    else {
        printf("text2 is bigger\n");
    }
    return;
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(){
   printf("date compare\n");
   
   time1 = localtime(&stat1.st_mtime);
   int year1 = time1->tm_year;
   int mon1 = time1->tm_mon;
   int day1 = time1->tm_mday;

   time2 = localtime(&stat2.st_mtime);
   int year2 = time2->tm_year;
   int mon2 = time2->tm_mon;
   int day2 = time2->tm_mday;
   
   if(year1 > year2) printf("text2 is early\n");
   else if(year1 == year2){
      if(mon1 > mon2) printf("text2 is early\n");
      else if(mon1 == mon1){
         if(day1 > day2) printf("text2 is early\n");
         else if(day1 == day2) printf("same date\n");
         else printf("text1 is early\n");
         return;
      }
      else printf("text1 is early\n");
      return;
   }
   else printf("text1 is early\n");
   
   return;
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(){
   printf("time compare\n");

   time1 = localtime(&stat1.st_mtime);
   int hour1 = time1->tm_hour;
   int min1 = time1->tm_min;

   time2 = localtime(&stat2.st_mtime);
   int hour2 = time2->tm_hour;
   int min2 = time2->tm_min;

   if(hour1 > hour2) printf("text2 is early\n");
   else if(hour1 == hour1){
      if(min1 > min2) printf("text2 is early\n");
      else if(min1 == min2) printf("same date\n");
      else printf("text1 is early\n");
      return;
   }
   else printf("text1 is early\n");

   return;
}