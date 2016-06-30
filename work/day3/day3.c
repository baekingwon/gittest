#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "engine2d.h"

void drawMyBox(int xpos, int ypos){
setColor(30,44); //와꾸 색상 입히기.

gotoxy(0,0);
printf("┌──────────────────┐");

int i=2, j=20, k=2; //offset 조절
while(i<20){
    
    //gotoxy(i,i); //대각선 1*1 2*2 3*3 ... 
    gotoxy(0,k); //왼쪽으로 20칸 컬럼 생성
    printf("│",k++);
    gotoxy(j,i); // 왼쪽으로 20칸 밀려 생성
    printf("│",i++);

  //  i++;

}
gotoxy(0,20);
printf("└──────────────────┘");

int ix=2,iy=1;

setColor(30,42);
while(ix <=5 ){ 
    iy =1;
    while(iy <=16 ){  //세로길이
        gotoxy(ix+xpos,iy+ypos); //위치지정
        printf(" ");
        iy++;
    }
    setColor(30,42+ix);//색채우기
    ix++;
}
}



int main(){
   // char cmd;
   // scanf("%c",&cmd);


//if문과 케이스문 비교
//if문에서 elseif 256개정도로 한정되서 case문 사용.

///////////////////////////

/*
    if(cmd == 'z'){
        printf("질럿을 생산합니다.\r\n");
    }
        else if(cmd == 'd'){
        printf("드라군을 생산합니다.\r\n");
        }
        else{
        printf("잘못된 입력입니다.\r\n");
        }
*/

///////////////////////////////////


/*
    switch(cmd){
        default:
        printf("잘못된 입력입니다.\r\n");
        break;
        case 'z':
        printf("질럿을 생산합니다.\r\n");
        break;
        case'd':
        printf("드라군을 생산합니다.\r\n");
        break;
    }
*/
////////////////////////////////////////////////////
/*
//간단한 반복문을 이용한 구구단 프로그래밍


int a=2, b=1;

while(b <= 9){  // 와일문으로 루프걸기, 9가될때까지 9번반복
printf(" %d * %d = %d \r\n",a,b,a*b);

///
b++; //b에 1씩 카운터 하나씩 증가
//b += 2; // 2씩증가
///
}
*/
////////////////////////////////////////////////////////////

/*
//1~100 까지 출력
int i=0;
while(i <= 100){
printf("count = %d \r\n",i++);  //안에다가 해도됨~

///
//i+=1;  //속도 더 빠름 기계적으로
//i++;
////

}
//10~1까지 출력
int ii=10;
while(ii >= 0){
printf("count = %d \r\n",ii--);  //안에다가 해도됨~


///
//i+=1;  //속도 더 빠름
//i++;
////

}

return 0;
*/

//////////////////////////////////////////////////////////

system("clear");

drawMyBox(1,2); //함수호출
drawMyBox(5,2); //함수호출
drawMyBox(9,2); //함수호출
drawMyBox(13,2); //함수호출
setColor(0,0); //색상초기화
return 0;

}



