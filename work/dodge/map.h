#ifndef __MAP_H_
#define __MAP_H_

typedef struct{
    int m_nSkima;
    int m_nWidth;
    int m_nHeight;
} _S_MAPS_HEADER; //별칭

typedef struct{
    _S_MAPS_HEADER m_header; //별칭
    char *m_pBuf;
} _S_MAPS_OBJ;





//proto type 프로토타입 선언

extern char Default_Tilepalete[];
void map_PutTile(_S_MAPS_OBJ *pObj, int x, int y, int nTileIndex);
void map_dump(_S_MAPS_OBJ *pObj, char *pTile_pal);
void map_new(_S_MAPS_OBJ *pObj, int nWidth, int nHeight);
int map_save(_S_MAPS_OBJ *pObj,char *filename);
int map_load(_S_MAPS_OBJ *pObj,char *filename);
void map_init(_S_MAPS_OBJ *pObj);


void map_drawTile(_S_MAPS_OBJ *pObj,int posx, int posy,_S_MAPS_OBJ *pTarget);
void map_drawTile_mirror_h(_S_MAPS_OBJ *pObj,int posx, int posy,_S_MAPS_OBJ *pTarget);
void map_drawTile_mirror_v(_S_MAPS_OBJ *pObj,int posx, int posy,_S_MAPS_OBJ *pTarget);
void map_drawTile_trn(_S_MAPS_OBJ *pObj,int posx, int posy,_S_MAPS_OBJ *pTarget);

#endif