
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>


#include "engine2d.h"
#include "map.h"
#include "plane.h"


#define kbUP 0x48 
#define kbDOWN 0x50
#define kbLEFT 0x4B 
#define kbRIGHT 0x4D


void Plane_init(_S_Plane *pObj,_S_MAPS_OBJ *pBody,int x,int y)
{
	pObj->m_pBody = pBody;
	pObj->m_nYpos = y;
	pObj->m_nXpos = x;

}
void Plane_Apply(_S_Plane *pObj,double deltaTick,char key_input)
{



	switch(key_input)
	{
		case 'a':
       case kbLEFT:
		pObj->m_nXpos -= 1;
		 
		   break;
	
        
		case 'd':
       case kbRIGHT:
		pObj->m_nXpos += 1;

		break;
		

	//	case VK_UP:
		case 'w':
        case kbUP:
		pObj->m_nYpos -= 1;
	
		break;
		case 's':
        case kbDOWN:
		pObj->m_nYpos += 1;
	
		break;
             
			 
		


}

	

//ADDED 임의로 한계 지정 클리핑(2)맵 크기 설정 해서 맵안에 가두어 범위초과 안함<클리핑>

if(pObj->m_nXpos <-1){
    pObj->m_nXpos++;
}


if(pObj->m_nXpos >31){
    pObj->m_nXpos--;
}


if(pObj->m_nYpos <-1){
    pObj->m_nYpos++;
}
if(pObj->m_nYpos >12){
    pObj->m_nYpos--;
}


//맵에서 이벤트발생시 이벤트 출력
if(pObj->m_nXpos == 15 && pObj->m_nYpos == 12){
	//이벤트 발생.
	gotoxy(50,12);
	 setColor(31,1);
	printf("GET OIL(#)\n");
}

if(pObj->m_nXpos == 14 && pObj->m_nYpos == 11){
	//이벤트 발생.
	gotoxy(50,12);
	 setColor(31,1);
	printf("GET BOOM(@)\n");
}

if(pObj->m_nXpos == 12 && pObj->m_nYpos == 11){
	//이벤트 발생.
	gotoxy(50,20);
	 setColor(31,1);
	printf("GET MONEY($)\n");
}




}
void Plane_Draw(_S_Plane *pObj, _S_MAPS_OBJ *pBuff)
{	
	map_drawTile_trn(pObj->m_pBody,pObj->m_nXpos,pObj->m_nYpos,pBuff);
	
	    
		

}

