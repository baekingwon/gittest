#ifndef __BULLET_H__
#define __BULLET_H__

typedef struct _S_BULLET_OBJ {

    int m_nStep;
    int m_nFSM;
	double m_fXpos;
	double m_fYpos;
	double m_fvx; //vector x
	double m_fvy; //vector y
	double m_fSpeed; 
    double m_faccLifeTime; //현재 생존시간 
	double m_fLifeLimit; //수명 몇초동안 보여줄것인가?
	_S_MAPS_OBJ *m_pBody;
//void (*pfDraw)(struct _S_BULLET_OBJ*pObj,_S_MAPS_OBJ *pMapBuf);
//void (*pfAplly)(struct _S_BULLET_OBJ*pObj,double deltaTick);
//void (*pfFire)(struct _S_BULLET_OBJ*pObj,int x, int y, double speed, double vx, double vy, double lifeLimit);
} _S_BULLET_OBJ;




void bullet_init(_S_BULLET_OBJ *pObj,double x,double y,double speed,_S_MAPS_OBJ *pBody);
void bullet_apply(_S_BULLET_OBJ *pObj,double deltaTick);
void bullet_draw(_S_BULLET_OBJ *pObj,_S_MAPS_OBJ *pMapBuf);
void bullet_fire(_S_BULLET_OBJ *pObj,int x,int y,double speed,double vx, double vy,double lifeLimit);


#endif