
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
#include "star.h"


void star_init(S_STAR_OBJ *pObj,
double x,double y,double speed,
_S_MAPS_OBJ *pBody)
{

    pObj->m_nFSM = 0; //0: sleep 1: active
    pObj->m_nStep = 0;
 	pObj->m_fSpeed = speed;
	pObj->m_fXpos = x;
	pObj->m_fYpos = y;
	pObj->m_pBody = pBody;
  


}

////////////////////////////////////////////
void star_apply(S_STAR_OBJ *pObj,double deltaTick)
{
switch(pObj->m_nFSM) {
		case 0:
		break;
		case 1:
		if(pObj->m_nStep == 0) {

			pObj->m_nStep++;
			pObj->m_faccLifeTime = 0;
		}
		else {
			pObj->m_faccLifeTime += deltaTick; //수명처리 
			if(pObj->m_faccLifeTime > pObj->m_fLifeLimit) {
				pObj->m_nStep = 0;
				pObj->m_nFSM = 0;
			}
			//pObj->m_fYpos += deltaTick * pObj->m_fSpeed;
			pObj->m_fYpos += deltaTick * (pObj->m_fSpeed* pObj->m_fvy);
			pObj->m_fXpos += deltaTick * (pObj->m_fSpeed* pObj->m_fvx);
		}

		break;
	}
}
//////////////////////////////////////
void star_draw(S_STAR_OBJ *pObj,_S_MAPS_OBJ *pMapBuf)
{
	switch(pObj->m_nFSM) {
	case 0:
	break;
	case 1:
	map_drawTile_trn(pObj->m_pBody,
		(int)pObj->m_fXpos,
		(int)pObj->m_fYpos,
		pMapBuf);

	break;
	}
}


void star_fire(S_STAR_OBJ *pObj,int x,int y,double speed,
double vx, double vy,double lifeLimit){

	
	pObj->m_nFSM = 1;
	pObj->m_nStep = 0;

	pObj->m_fXpos = (double)x;
	pObj->m_fYpos = (double)y;

	pObj->m_fvx=vx;
	pObj->m_fvy=vy;
	pObj->m_fSpeed = speed;
	
	pObj->m_fLifeLimit = lifeLimit;
	
}