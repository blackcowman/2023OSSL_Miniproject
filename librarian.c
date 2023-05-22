#include "library.h"

int addBook(Book *b);
void readBook(Book b){
  printf("%s %2s %2d %2s %2d %2d\n", b.title,b.author, b.number, b.ganre, b.borrow,
         b.reservation);
}
void listBook(Book *b[], int count) {
  int i = 0;
  int countNumber = 0;
  printf("\nNo  책 제목  작가명   청구번호   장르   대출여부  예약여부\n");
  printf("=================================\n");
  for (; i < count; i++) {
    if (b[i]->del == 1)
      continue;
    printf("%2d ", i + 1);
    readBook(*b[i]);
    countNumber++;
  }

  printf("\n");
  printf("=>총 예약 %d건 \n\n", countNumber);
}

void listBorrowedBook(Book *b[], int count) {
  int i = 0;
  int countNumber = 0;
  printf("\nNo  책 제목  작가명   청구번호   장르   대출여부  예약여부\n");
  printf("=================================\n");
  for (; i < count; i++) {
    if (b[i]->del == 1 )
      continue;
    if(b[i]->borrow == 0){
      countNumber++;
      continue;
    }
    printf("%2d ", i + 1);
    readBook(*b[i]);
    countNumber++;
  }

  printf("\n");
  printf("=>총 예약 %d건 \n\n", countNumber);
}

int deleteBook(Book *b);



int selectDataNo(Book *b[], int count){
  int no;
  listBook(b, count);
  printf("몇 번 도서인가요(취소: 0)? ");
  scanf("%d", &no);
  return no;
}

int selectBook(){

}

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
      int i = 0;
  FILE *fp = fopen("book.txt", "rt");
  if (fp == NULL)
    return -1;
  for (; i < 100; i++) {
    b[i] = (Book *)malloc(sizeof(Book));
    if (b[i] == NULL)
      continue;
    fscanf(fp, "%d", &b[i]->number);

    if (feof(fp))
      break;

    fscanf(fp, "%s", b[i]->ganre);
    fscanf(fp, "%d", &b[i]->borrow);
    fscanf(fp, "%d", &b[i]->reservation);
    // fgets(m[i]->name, sizeof(m[i]->name), fp); // fgets를 통해서 읽어들임
    fscanf(fp, "%s", b[i]->author);
    fscanf(fp, "%[^\n]%*c", b[i]->title);
  }
  fclose(fp);
  printf("=>로딩 성공!!\n");
  return i;

}
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
}