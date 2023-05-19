#include "library.h"

int addBook(Book *b);
void readBook(Book b);
void listBook(Book *b[], int count);
int deleteBook(Book *b);



int selectDataNo(Book *b[], int count){
  int no;
  listBook(b, count);
  printf("번호는 (취소: 0)? ");
  scanf("%d", &no);
  return no;
};

int selectBook(){

};

void saveBook(Book *b[], int count);
int loadBook(Book *b[]);
void searchBook(Book *s[], int count);
void librarianmenu(){
    printf("\n***도서관 이용 시스템(libraian)***\n");
    printf("1. 신규 도서 등록\n");
    printf("2. 도서 삭제\n");
    printf("3. 도서 업데이트\n");
    printf("4. 도서 목록\n");
    printf("5. 도서 검색\n");
    printf("0. 로그아웃\n");
    printf(">> ");
};