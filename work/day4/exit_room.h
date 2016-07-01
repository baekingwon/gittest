#ifndef __EXITROOM_H__
#define __EXITROOM_H__



//
int buff_map[256]; // 버퍼 맵,  위의것 똑같이 복사

///pc 초기위치///
int pc_xpos;
int pc_ypos;


//0 게임준비상태
//1 게임 플레이 상태
//2 레벨클리어
//3 게임오버
int nFSM = 0; //초기화
int pc_inv; //pc인벤 부분 0없음, 1키보유

int move_pc(char cmd){
     int old_xpos = pc_xpos;
     int old_ypos = pc_ypos;

    switch(cmd){
        
        default:
        break;

        case 'w':
        map_drawAll(buff_map);
        
        gotoxy(20,10);
        printf("위로 한칸 이동했습니다.\r\n");
        pc_ypos -=1;
        break;

        case 's':
        map_drawAll(buff_map);
        gotoxy(20,10);
        printf("아래로 한칸 이동했습니다.\r\n");
        pc_ypos +=1;
        break;

        case 'a':
        map_drawAll(buff_map);
        gotoxy(20,10);
        printf("좌로 한칸 이동했습니다.\r\n");
        pc_xpos -=1;
        break;

        case 'd':
        map_drawAll(buff_map);
        gotoxy(20,10);
        printf("우로 한칸 이동했습니다.\r\n");
        pc_xpos +=1;
        break;

  
    }

switch(buff_map[pc_xpos+pc_ypos*16]){
    case 0: //free space
    break;
    case 1: //wall
    pc_xpos =old_xpos;
    pc_ypos =old_ypos;
    break;
    case 2: //door
    printf("misson Clear \r\n");
    nFSM =2;
    break;
    case 4:
    if(pc_inv ==1){  //키가 있을경우 미션클리어
        printf("mission Clear \r\n");
        nFSM =2;
    }
    else{
        pc_ypos = old_xpos;
        pc_xpos = old_xpos;

    }
    case 5:
    printf("get key \r\n");
    pc_inv =1;
    break;
    case 7:
     pc_xpos = old_xpos;
     pc_ypos = old_ypos;
break; //obj
}
/*
   
        if(buff_map[ pc_xpos + pc_ypos*16 ] == 0){
    //0일때 이동가능.
} 
        else{
    //이동불가 즉, 장애물 인식부분
    pc_xpos = old_xpos;
    pc_ypos = old_ypos;
  // printf("막다른길입니다.\r\n");
        }

*/
/*
switch(buff_map[pc_xpos+pc_ypos*16]){
    
case 1: //wall
pc_xpos = old_xpos;
pc_ypos = old_ypos;
break;
case 0: //space
break;
case 2:
printf("Misson Complate!\r\n");
nFSM =2;
break; //door
case 7:
pc_xpos = old_xpos;
pc_ypos = old_ypos;
break; //obj
   
}
*/
 buff_map[pc_xpos+pc_ypos*16] = 3;
}


#endif