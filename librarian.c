#include "library.h"

int addBook(Book *b,  int n) {
  printf("������ �Է����ּ���: ");
  scanf("%s", b->title);

  printf("���ڸ� �Է����ּ���: ");
  scanf("%s", b->author);

  printf("���ǻ縦 �Է����ּ��� ");
  scanf("%s", b->publisher);

  printf("û����ȣ�� �Է����ּ��� ");
  scanf("%d", &b->number);

  b->borrow = 0;
  b->reservation = 0;
  b->del = 0;

  if(n == 2) {
    printf("=> �߰��Ǿ����ϴ�.\n");
    return 1;
  } else {
    printf("=> �����Ǿ����ϴ�.\n");
  }
  
  return 1;
}

void readBook(Book b){
  printf("%d %s %2s %2d  %2s %2d %2d\n", b.number, b.title, b.author, b.number, b.publisher, b.borrow,
         b.reservation);
}
void listBook(Book *b[], int count) {
  int i = 0;
  int countNumber = 0;
  printf("\nNo û����ȣ   å ����  �۰���   û����ȣ   ���⿩��  ���࿩��\n");
  printf("=================================\n");
  for (; i < count; i++) {
    if (b[i]->del == 1)
      continue;
    printf("%2d ", i + 1);
    readBook(*b[i]);
    countNumber++;
  }

  printf("\n");
  printf("=>���� �� %d�� \n\n", countNumber);
}

void listBorrowedBook(Book *b[], int count) {
  int i = 0;
  int countNumber = 0;
  printf("\nNo  û����ȣ   å ����  �۰���   û����ȣ   ���⿩��  ���࿩��\n");
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
  printf("=>���� �� %d�� \n\n", countNumber);
}

int deleteBook(Book *b){
  b->del = 1;
};



int selectDataNo(Book *b[], int count){
  int no;
  listBook(b, count);
  printf("�� �� �����ΰ���(���: 0)? ");
  scanf("%d", &no);
  return no;
}
int selectBorrowedDataNo(Book *b[], int count){
  int no;
  listBorrowedBook(b, count);
  printf("�� �� �����ΰ���(���: 0)? ");
  scanf("%d", &no);
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
  printf("=>�����!!\n");
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
    // fgets(m[i]->name, sizeof(m[i]->name), fp); // fgets�� ���ؼ� �о����
    fscanf(fp, "%s", b[i]->author);
    fscanf(fp, "%[^\n]%*c", b[i]->title);
  }
  fclose(fp);
  printf("=>�ε� ����!!\n");
  return i;

}
void searchBook(Book *s[], int count) {
  int scnt = 0;
  char search[20];

  printf("�̸���?");
  scanf("%s", search);

  printf("\nNo  û����ȣ   å ����  �۰���   û����ȣ   ���⿩��  ���࿩��\n");
  printf("=================================\n");
  for (int i = 0; i < count; i++) {
    if (s[i] == NULL)
      continue;
    if (strstr(s[i]->title, search) || strstr(s[i]->author, search)|| strstr(s[i]->publisher, search)) {
      printf("%2d ", i + 1);
      readBook(*s[i]);
      scnt++;
    }
  }

  if (scnt == 0)
    printf("=> �˻��� ������ ����!\n");
  else
    printf("���� �� %d��\n", scnt);
}

int librarianmenu(){
    int menu;
    printf("\n***������ �̿� �ý���(libraian)***\n");
    printf("1. �ű� ���� ���\n");
    printf("2. ���� ����\n");
    printf("3. ���� ������Ʈ\n");
    printf("4. ���� ���\n");
    printf("5. ���� �˻�\n");
    printf("6. ���� ����\n");
    printf("0. �α׾ƿ�\n");
    printf(">> ");
    scanf("%d", &menu);
    return menu;
}