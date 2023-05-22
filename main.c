#include <stdio.h>
#include "library.h"

int main(){
    int usertype;
    Book *sp[100];
    int index = 0; //데이터 번호
    int count = 0, menu;
    int no;
    count = loadBook(sp);
    if (count == -1) {
        printf("로딩 실패!!!\n");
        count = 0;
    } else {
        index = count;
    }

    while (1)
    {
        while (1)
        {
            printf("어느 계정으로 접속하시겠습니까? (1. 유저 2. 사서 0. 프로그램 종료)\n");
            scanf("%d", &usertype);
            if(usertype ==1 || usertype == 2|| usertype == 0) break;
            else printf("잘못 입력하셨습니다.");

        }
        if(usertype == 1){
            //여기에 유저 메뉴를 출력하는 함수를 넣을 것
            menu = usermenu();

            if(menu == 0){
                // printf("0. 로그아웃\n");
            }else if(menu == 1){
                // printf("1. 도서 목록\n");
            }else if(menu == 2){
                // printf("2. 도서 대출\n");
            }else if(menu == 3){
                // printf("3. 도서 반납\n");
            }else if(menu == 4){
                // printf("4. 도서 검색\n");
            }else if(menu == 5){
                // printf("5. 도서 예약\n");
            }
        }
        if (usertype ==2)
        {
            //여기에 사서 메뉴를 출력하는 함수를 넣을 것
            menu = librarianmenu();
            if(menu == 0){
                // printf("0. 로그아웃\n");
            }else if(menu == 1){
                // printf("1. 신규 도서 등록\n");
            }else if(menu == 2){
                // printf("2. 도서 삭제\n");
            }else if(menu == 3){
                // printf("3. 도서 업데이트\n");
            }else if(menu == 4){
                // printf("4. 도서 목록\n");
            }else if(menu == 5){
                // printf("5. 도서 검색\n");
            }


        }
        if(usertype==0){
        break;
    }
    }
    
    for (int i = 0; i < index; i++) {
    free(sp[i]);
  }
  
  printf("종료됨!\n");
  return 0;

}