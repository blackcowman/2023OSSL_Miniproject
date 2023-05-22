#include "library.h"

int addBook(Book *b, int count, int n) {
  printf("제목을 입력해주세요: ");
  scanf("%s", b->title);

  printf("저자를 입력해주세요: ");
  scanf("%s", b->author);

  printf("출판사를 입력해주세요 ");
  scanf("%s", b->publisher);

  printf("를 입력해주세요 ");
  scanf("%s", b->code);

  b->borrow = 0;
  b->reservation = 0;
  b->del = 0;

  if(n == 2) {
    count++;
    b->number = count;
    printf("=> 추가되었습니다.\n");
  } else {
    printf("=> 수정되었습니다.\n");
  }
  
  return count;
}

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

void listBorrowedBook(Book *b[], int count) {
  int i = 0;
  int countNumber = 0;
  printf("\nNo  책 제목  작가명   출판사   청구번호   대출여부  예약여부\n");
  printf("=================================\n");
  for (; i < count; i++) {
    if (b[i]->del == 1 || b[i]->borrow == 0)
      continue;
    printf("%2d ", i + 1);
    readBook(*b[i]);
    countNumber++;
  }

  printf("\n");
  printf("=>총 %d권 \n\n", countNumber);
}

void deleteBook(Book *b[], int count) {
  int exe;
  int no = selectBook(b, count);
  if(no != 0) {
    printf("이 도서를 삭제하시겠습니까(취소: 0)? ");
    scanf("%d", exe);
    if(exe == 0)
      printf("취소되었습니다.\n");
    else {
      b[no+1]->del = 1;
      printf("삭제되었습니다.\n");
    }
  }
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

void saveBook(Book *b[], int count){
    FILE *fp = fopen("book.txt", "wt");
    for (int i = 0; i < count; i++) {
        if (b[i]->del == 1)
        continue;
        fprintf(fp, "%2d %2s %2d %2d %s %s\n", b[i]->number, b[i]->publisher, b[i]->borrow,
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

    fscanf(fp, "%s", b[i]->publisher);
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
