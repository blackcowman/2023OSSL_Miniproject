#include "library.h"

int addBook(Book *b);
void readBook(Book b);
void listBook(Book *b[], int count);
int deleteBook(Book *b);



int selectDataNo(Book *b[], int count){
  int no;
  listBook(b, count);
  printf("몇 번 도서인가요(취소: 0)? ");
  scanf("%d", &no);
  return no;
};

int selectBook(){

};

void saveBook(Book *b[], int count){
    FILE *fp = fopen("book.txt", "wt");
    for (int i = 0; i < count; i++) {
        if (b[i]->del == 1)
        continue;
        fprintf(fp, "%2d %2s %2d %2d %s %s\n", b[i]->number, b[i]->ganre, b[i]->borrow,
            b[i]->reservation, b[i]->author, b[i]->title);
  }
  fclose(fp);
  printf("=>저장됨!!\n");
}
int loadBook(Book *b[]){
    
};
void searchBook(Book *s[], int count);

int librarianmenu(){
    int menu;
    printf("\n***도서관 이용 시스템(libraian)***\n");
    printf("1. 신규 도서 등록\n");
    printf("2. 도서 삭제\n");
    printf("3. 도서 업데이트\n");
    printf("4. 도서 목록\n");
    printf("5. 도서 검색\n");
    printf("0. 로그아웃\n");
    printf(">> ");
    scanf("%d", &menu);
    return menu;
};