#include "library.h"

int borrowBook(Book *b){
    b->borrow = 1;
    return 0;
}

int reservationBook(Book *b){
    b->reservation = 1;
    return 0;
}

int returnBook(Book *b){
    b->borrow = 0;
    return 0;
}

int usermenu(){
    int menu;
    printf("\n***도서관 이용 시스템(user)***\n");
    printf("1. 도서 목록\n");
    printf("2. 도서 대출\n");
    printf("3. 도서 반납\n");
    printf("4. 도서 검색\n");
    printf("5. 도서 예약\n");
    printf("6. 이주의 책 보기\n");
    printf("0. 로그아웃\n");
    printf(">> ");
    scanf("%d", &menu);
    return menu;
}
