#include <stdio.h>
#include "library.h"

int main(){
    int usertype;
    while (1)
    {
        while (1)
        {
            printf("어느 계정으로 접속하시겠습니까? (1. 유저 2. 사서 0. 프로그램 종료)\n");
            scanf("%d", &usertype);
            if(usertype ==1 || usertype == 2) break;
            else if(usertype == 0) return 0;
            else printf("잘못 입력하셨습니다.");

        }
        if(usertype == 1){
            //여기에 유저 메뉴를 출력하는 함수를 넣을 것
        }
        if (usertype ==2)
        {
            //여기에 사서 메뉴를 출력하는 함수를 넣을 것
        }
        
    }
    
    

    
    
    

}