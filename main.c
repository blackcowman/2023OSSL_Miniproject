#include <stdio.h>
#include "library.h"

int main(){
    int usertype;
    Book *sp[100];
    int index = 0; //������ ��ȣ
    int count = 0, menu;
    int no;
    count = loadBook(sp);
    if (count == -1) {
        printf("�ε� ����!!!\n");
        count = 0;
    } else {
        index = count;
    }

    while (1)
    {
        while (1)
        {
            printf("��� �������� �����Ͻðڽ��ϱ�? (1. ���� 2. �缭 0. ���α׷� ����)\n");
            scanf("%d", &usertype);
            if(usertype ==1 || usertype == 2|| usertype == 0) break;
            else printf("�߸� �Է��ϼ̽��ϴ�.");

        }
        while (1)
        {
            if(usertype == 1){
            //���⿡ ���� �޴��� ����ϴ� �Լ��� ���� ��
            menu = usermenu();
            if(menu == 0){
                // printf("0. �α׾ƿ�\n");
                printf("�α׾ƿ��Ǿ����ϴ�\n");
                break;
            }else if(menu == 1){
                // printf("1. ���� ���\n");
                listBook(sp, index);
            }else if(menu == 2){
                // printf("2. ���� ����\n");
                no = selectDataNo(sp, index);
                if (no == 0) {
                    printf("��ҵ�!\n");
                    continue;
                }
                int borrowok;

                printf("���� �Ͻðڽ��ϱ�?(����:1)");
                scanf("%d", &borrowok);
                if (borrowok == 1) {
                    if (sp[no - 1]->borrow == 1) {
                    int reservationok = 0;
                    printf("å�� �̹� �������Դϴ�. �����Ͻðڽ��ϱ�?(����:1)\n >> ");
                    scanf("%d", &reservationok);
                        if(reservationok == 1){
                            reservationBook(sp[no - 1]);
                        }
                    } else {
                    borrowBook(sp[no - 1]);
                    }
                }
                
            }else if(menu == 3){
                // printf("3. ���� �ݳ�\n");
                no = selectBorrowedDataNo(sp, index);
                if (no == 0) {
                    printf("��ҵ�!\n");
                    continue;
                }
                returnBook(sp[no - 1]);
            }else if(menu == 4){
                // printf("4. ���� �˻�\n");
                searchBook(sp, index);
            }else if(menu == 5){
                // printf("5. ���� ����\n");
                no = selectBorrowedDataNo(sp, index);
                if (no == 0) {
                    printf("��ҵ�!\n");
                    continue;
                }
                reservationBook(sp[no - 1]);
            }else if(menu == 6){
                // printf("6. ���� ����\n");
                 saveBook(sp, index);
            }
        }
        if (usertype ==2)
        {
            //���⿡ �缭 �޴��� ����ϴ� �Լ��� ���� ��
            menu = librarianmenu();
            if(menu == 0){
                // printf("0. �α׾ƿ�\n");
                printf("�α׾ƿ��Ǿ����ϴ�\n");
                break;
            }else if(menu == 1){
                // printf("1. �ű� ���� ���\n");
                sp[index] = (Book *)malloc(sizeof(Book));
                count += addBook(sp[index++],2);
            }else if(menu == 2){
                // printf("2. ���� ����\n");
                no = selectDataNo(sp, index);
                if (no == 0) {
                    printf("��ҵ�!\n");
                    continue;
                }
                int deleteok;
                printf("������ �����Ͻðڽ��ϱ�?(����:1)");
                scanf("%d", &deleteok);
                if (deleteok == 1) {
                    deleteBook(sp[no - 1]);
                    count--;
                }
            }else if(menu == 3){
                // printf("3. ���� ������Ʈ\n");
                no = selectDataNo(sp, index);
                if (no == 0) {
                    printf("��ҵ�!\n");
                    continue;
                }
                addBook(sp[no - 1],1);
            }else if(menu == 4){
                // printf("4. ���� ���\n");
                listBook(sp, index);

            }else if(menu == 5){
                // printf("5. ���� �˻�\n");
                searchBook(sp, index);

            }else if(menu == 6){
                // printf("6. ���� ����\n");
                saveBook(sp, index);

            }

        }
            if(usertype==0){
            break;
            }
        }
        
        
        
        if(usertype==0){
            break;
        }
    }
    
   
  for (int i = 0; i < index; i++) {
    free(sp[i]);
  }

  printf("�����!\n");
  return 0;

}