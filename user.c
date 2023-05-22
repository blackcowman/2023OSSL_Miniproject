#include "library.h"

void readBook(Book b){
  printf("%d %s %2s %s %2s %2d %2d\n", b.number, b.title, b.author, b.code, b.publisher, b.borrow,
         b.reservation);
}

void listBook(Book *b[], int count, int n) {
  int i = 0;
  int countNumber = 0;
  
  if (n == -1) {
    printf("\nNo  책 제목  작가명   출판사   청구번호   대출여부  예약여부\n");
    printf("===========================================================\n");
    for (; i < count; i++) {
      if (b[i]->del == 1)
        continue;
      printf("%2d ", i + 1);
      readBook(*b[i]);
      countNumber++;
    }
  } else {
    if(b[n]->del == 1) printf("해당 도서는 삭제되었습니다.\n");
    else {
      printf("\nNo  책 제목  작가명   출판사   청구번호   대출여부  예약여부\n");
      printf("===========================================================\n");
      readBook(*b[n]);
    }
  }

  printf("\n");
  printf("=>총 %d권 \n\n", countNumber);
}

int selectBook(Book *b[], int count){
  int no;
  int re = 1;
  listBook(b, count, -1);
  printf("몇 번 도서인가요(취소: 0)? ");
  scanf("%d", &no);
  if(b[no+1]->del == 1) {
    printf("이 책은 삭제되었습니다..\n");
    no = 0;
  } else listBook(b, count, no+1);
  
  return no;
}

int borrowBook(Book *b){
    int no = selectBook(b, count);
    if(b[no->borrow == 0) {
        b[no]->borrow = 1;
        printf("대출되었습니다.\n");
    } else {
        printf("이미 대출된 책입니다.\n");
    }
    return 0;
}

int reservationBook(Book *b[], int count){
    int no = selectBook(b, count);
    if(b[no->reservation == 0) {
        b[no]->reservation = 1;
        printf("예약되었습니다.\n");
    } else {
        printf("이미 예약된 책입니다.\n");
    }
    return 0;
}

int returnBook(Book *b){
    int no = selectBook(b, count);
    if(b[no->borrow == 1) {
        b[no]->borrow = 0;
        printf("반납되었습니다.\n");
    } else {
        printf("이미 반납된 책입니다.\n");
    }
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
