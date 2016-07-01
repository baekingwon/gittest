#ifndef __ENGINE__2D__

#define __ENGINE__2D__

void setColor(int fore_color,int backg_color)
{
	printf("%c[%d;%dm",0x1b,fore_color,backg_color);
}

void gotoxy(int x,int y)
{
	printf("%c[%d;%df",0x1b,y,x);
}


int drawMyBox(int nXpos, int nYpos, int nZpos, int nForeColor,int nBgColor,int nSize){
//z는 아직 사용안함 0
        int ix, iy;
       
        setColor(nForeColor,nBgColor); //fore, bg
        ix=0;
for(iy=0;iy <= nSize;iy++){
    for(ix=0;ix <=nSize;ix++){
    gotoxy(ix+nXpos,iy+nYpos);
    printf(" ");
    }
}
setColor(0,0);
}


//////////////////////////////////////////
///타일맵 엔진2번//////////////////


void map_printCell(int rawdata)
{
    switch(rawdata){
        
        default:
        printf(" "); //기타는 공백처리
        break;
    
        case 0: //공터
        printf(" ");
        break;

        case 1: //벽
        printf("■");
        break;

        case 2: //문
        printf("♡");
        break;

        case 3: //케릭터 초기점
        printf("X");
        break;

        case 4: //잠긴문
        printf("♥");
        break;

        case 5: //키
        printf("K");
        break;

        case 6: //포털
        printf("P");
        break;
        case 7: //오브젝트
        printf("∵");
        break;

        


    }
}




////////////////

 void map_drawAll(int *pMap){
    
/////////////////////////////////////////////////////////////
//타일맵엔진1번///////////////////////////////////////////
/*
for(int i=0;i<64;i++){
    switch(world_map[i]){
       
        default:
        printf(" "); //정의되지 않은것은 공백처리
        break;

        case 0:
        printf(" "); //공백 움직일수 있는 영역
        break;

        case 1: // 벽
        printf("#"); 
        break;

        case 2:
        printf("D"); //문
        break;

        case 3:
        printf("X"); //주인공 초기점
        break;

        case 4:
        printf("P"); //포탈
        break;
    
    }

    
///////////////////////////////////////////////
    printf("%d",world_map[i]);
    if((i+1)%8 ==0){  //배열정렬방법 1
        printf("\r\n");
       ///// ///////////////////
        }
        }
    */
/////////////////////////////////////////////////////////




///////////////////////////////배열 정렬방법2//////////

int ix, iy;
for(iy=0;iy<16;iy++){
    for(ix=0;ix<16;ix++){
       // printf("%d",world_map[ix + iy*8]);  //iy는 8단위로 되기때문에 8단위로 곱해주고
       map_printCell(pMap[ix+iy*16]); // 16단위로
    }
    printf("\r\n");
}
 }


#endif