#include <stdio.h>
#include <stdlib.h>
#include "engine2d.h"
#include "exit_room.h"

/*
0:공터 공백
1:벽 ■
2:열린문 ♡ //그냥탈출 //포탈개념
3:게이머 X
4:잠긴문 ♥ //키를얻어야만이탈출
5:키아이템 K
*/

int world_map1[] ={  //원본맵

   // 맵배열 16 * 16 = 256
    
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,0,0,4,5,0,2,1,1,1,1,1,1,1,1,1,
        1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,
        1,0,0,0,0,0,6,1,1,1,1,1,1,1,1,1,
        1,0,0,7,0,0,6,1,1,1,1,1,1,1,1,1,
        1,0,0,7,7,0,0,1,1,1,1,1,1,1,1,1,
        1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,
        1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,
        1,0,0,7,7,7,0,1,1,1,1,1,1,1,1,1,
        1,0,0,7,7,7,0,1,1,1,1,1,1,1,1,1,
        1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,
        1,0,0,6,6,0,0,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,

};

int game_version =1;
char *game_name ="ESCAPE ROOM GAME";




int main(){

char cmd;
int bLoop = 1;
 


 
while(bLoop){


   
    switch(nFSM){
        case 0:
        printf("%s, Client Ver.%d\r\n",game_name,game_version);
        printf("select => [p,x]\r\n");
        break;

        case 1:
        setColor(31,1);
        printf("명령을 선택하세요:\r\nw(up),s(down),a(left),d(right),m(show map),q(exit)\r\n");
        break;

    }



    
    map_drawAll(buff_map);
    
    
    
    
         //버퍼초기화
       for(int i=0;i<256;i++){
        buff_map[i] = world_map1[i];  //맵 카피
       }

    
    scanf("%c",&cmd);
   // system("clear");
    //getchar();
    //move_pc(cmd);
    setColor(0,0);
   if(nFSM == 0){
    switch(cmd){
        case 'p'://게임스타트
        nFSM = 1;
        //pc 초기위치지정
        pc_xpos =1;
        pc_ypos =1;
        ///////////////
        pc_inv =0; //인벤 초기화 처음에 아무것도 안들고있음.
        //////
        printf("게임을 시작합니다.");
        break;

        case 'x':
        bLoop =0;
        printf("bye\r\n");
        break;
    }
}



else if(nFSM == 1){  //게임플레이중
    move_pc(cmd);

    //buff_map[pc_xpos+pc_ypos*16] = 3; //케릭터가 맵에 그려짐
    
    switch(cmd){
        
        
        case 'm':
        map_drawAll(buff_map);
        printf("맵\r\n");
        break;

        case 'q':
        bLoop =0; //루프탈출 즉, 종료.
        printf("Bye~ Bye~\r\n");
        break; 
}
}
   else if(nFSM == 2){

    
        nFSM =0;
      
}

}




return 0;
}