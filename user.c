#include "library.h"




int borrowBook(Book *b){
        b->borrow = 1;
        printf("����Ǿ����ϴ�.\n");
    
    return 0;
}

int reservationBook(Book *b){
        b->reservation = 1;
        printf("����Ǿ����ϴ�.\n");
    return 0;
}

int returnBook(Book *b){
        b->borrow = 0;
        printf("�ݳ��Ǿ����ϴ�.\n");

    return 0;
}

int usermenu(){
    int menu;
    printf("\n***������ �̿� �ý���(user)***\n");
    printf("1. ���� ���\n");
    printf("2. ���� ����\n");
    printf("3. ���� �ݳ�\n");
    printf("4. ���� �˻�\n");
    printf("5. ���� ����\n");
    printf("6. ���� ����\n");
    printf("0. �α׾ƿ�\n");
    printf(">> ");
    scanf("%d", &menu);
    return menu;
}
