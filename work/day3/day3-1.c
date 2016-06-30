#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "engine2d.h"

//for문을 이용한 움직임구현 


int main(){
  
    int bLoop = 1;
    char cmd;
    int xpos,ypos;
    xpos=1;ypos=1;
    
    int orc_xpos,orc_ypos;
    
    ////몬스터 초기좌표 지정
    orc_xpos = 10;
    orc_ypos = 10;
    ///////////////////////

    while(bLoop){
    scanf("%c",&cmd); //사용자 입력값 
    
    switch(cmd){
        case 'w':
        ypos -=1;
        break;
        case 's':
        ypos +=1;
        break;
        case 'a':
        xpos -=1;
        break;
        case 'd':
        xpos +=1;
        break;
        case 'q':
        bLoop=0;
        break;
    }
  
   

    system("clear");
    //주인공 스프라이트 로드
    drawMyBox(xpos,ypos,0,30,41,3);
    //몬스터 AI
    if(orc_xpos > xpos  ){
      
        orc_xpos -= 1;
    }
    else if(orc_xpos<xpos){
        orc_xpos +=1;
    
       
    }
    else{}
        //몬스터 스프라이트 출력
    drawMyBox(orc_xpos,orc_ypos,0,42,1,5);
   
    //drawMyBox(2,2,0,31,41);  //함수호출해서 좌표지정 및 색설정 값지정
     gotoxy(0,20);
     printf("-------------");
     
     printf("%d,%d \r",xpos,ypos);
    


    }



   //return 0;

}