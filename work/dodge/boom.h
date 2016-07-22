#ifndef __BOOM_H__
#define __BOOM_H__

typedef struct {

    int m_nStep;
    int m_nFSM;
	double m_fXpos;
	double m_fYpos;
	double m_fvx; //vector x
	double m_fvy; //vector y
	double m_fSpeed;
    double m_faccLifeTime; //현재 생존시간 
	double m_fLifeLimit; //수명
	_S_MAPS_OBJ *m_pBody;

} S_BOOM_OBJ;

void boom_init(S_BOOM_OBJ *pObj,double x,double y,double speed,_S_MAPS_OBJ *pBody);
void boom_apply(S_BOOM_OBJ *pObj,double deltaTick);
void boom_draw(S_BOOM_OBJ *pObj,_S_MAPS_OBJ *pMapBuf);
void boom_fire(S_BOOM_OBJ *pObj,int x,int y,double speed,double vx, double vy,double lifeLimit);


#endif