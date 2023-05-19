
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char title[40]; //도서 이름
    char author[40];//작가
    int borrow; //대출 여부 1 = 이미 대출중, 0 = 대출 가능
    int number; //청구기호
    char ganre[20]; //장르 구분
    int reservation; //예약 여부 1 = 이미 예약 있음, 0 = 아직 없음
    int del;
} Book;

int addBook(Book *b);
void readBook(Book b);
void listBook(Book *b[], int count);
int deleteBook(Book *b);
int borrowBook(Book *b);
int reservationBook(Book *b);
int selectDataNo(Book *b[], int count);
int selectBook();
void saveBook(Book *b[], int count);
int loadBook(Book *b[]);
void searchBook(Book *s[], int count);
void usermenu();
void librarianmenu();
