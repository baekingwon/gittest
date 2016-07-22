#include <stdio.h>
#include <stdlib.h>

#include "map.h"


char Default_Tilepalete[] = {' ','#','@','/',92,'+','=','^','>','<','|','-','*'};//0~12

void map_init(_S_MAPS_OBJ *pObj){
    pObj->m_pBuf = NULL;
}



void map_dump(_S_MAPS_OBJ *pObj, char *pTile_pal){
           /*
           putTile(
            0,pObj->m_header.m_nHeight,
            0,pObj->m_header.m_nWidth,
            pObj->m_header.m_nWidth,
            pObj->m_pBuf,
      pTile_pal);
      */ 
      //이거대신 아래것사용
      for (int iy=0;iy < pObj->m_header.m_nHeight;iy++){
          for(int ix=0;ix<pObj->m_header.m_nWidth;ix++){
              putchar(pTile_pal[pObj->m_pBuf[iy* pObj->m_header.m_nWidth+ix]]);
          }
          printf("\r\n");
      }
}

void map_new(_S_MAPS_OBJ *pObj, int nWidth, int nHeight){



        int nSize = nWidth*nHeight;
            if(pObj->m_pBuf !=NULL){free(pObj->m_pBuf);}
                
          
          
            pObj->m_header.m_nWidth = nWidth;// atoi(strtok(NULL," "));
            pObj->m_header.m_nHeight = nHeight; // atoi(strtok(NULL," "));
            pObj->m_pBuf = malloc(nSize); // malloc(MapObj.m_header.m_nHeight * MapObj.m_header.m_nWidth);

           for(int i =0;i<nSize;i++){
               pObj->m_pBuf[i] = 0;
          }

}


void map_PutTile(_S_MAPS_OBJ *pObj, int x, int y, int nTileIndex){
    //클리핑 처리(1)
	if(x >= 0 && y >=0) {
		if(x < pObj->m_header.m_nWidth && y < pObj->m_header.m_nHeight) {
			pObj->m_pBuf[ pObj->m_header.m_nWidth * y + x  ] = nTileIndex;
		}
	}
}

//0 이면,, 성공 혹은 1이면,, 실패.
int map_save(_S_MAPS_OBJ *pObj,char *filename){

       
           FILE *pf = fopen(filename,"w");
           fwrite(&(pObj->m_header),sizeof(pObj->m_header),1,pf);
           int nSize = pObj->m_header.m_nWidth * pObj->m_header.m_nHeight;
           fwrite(pObj->m_pBuf,nSize,1,pf); //사이즈만큼 버퍼내용을 출력
           fclose(pf);
return 0;


}

//0 이면,, 성공 혹은 1이면,, 실패.
int map_load(_S_MAPS_OBJ *pObj,char *filename){

 

           FILE *pf = fopen(filename,"r");
          
           fread(&(pObj->m_header),sizeof(_S_MAPS_HEADER),1,pf);
              
              if(pObj->m_pBuf){
             free(pObj->m_pBuf);
          }
        
          int nSize = pObj->m_header.m_nWidth* pObj->m_header.m_nHeight;
          pObj->m_pBuf = malloc(nSize);
           
       
        fread(pObj->m_pBuf,nSize,1,pf);

            for (int i=0;i<nSize;i++){
                printf("%d,",pObj->m_pBuf[i]);
            }



return 0;
}


void map_drawTile(_S_MAPS_OBJ *pObj,int posx, int posy,_S_MAPS_OBJ *pTarget){
       
   //     _S_MAPS_OBJ *pObj = &humanObj;
 //       _S_MAPS_OBJ *pTarget = &screenBuf;

  //      int posx =5;
  //      int posy =5;

		for(int iy=0;iy < pObj->m_header.m_nHeight;iy++) {
			for(int ix = 0; ix < pObj->m_header.m_nWidth;ix++) {
				       
                        map_PutTile(pTarget,ix+posx ,iy+posy,
						pObj->m_pBuf[iy*pObj->m_header.m_nWidth + ix]);
                        
                        // 자동차 회전 90도 ex)2
                       // map_PutTile(&pTarget,posx ,posy,
						//pObj->m_pBuf[iy*pObj->m_header.m_nWidth + ix]);
			}
		}

	}



    void map_drawTile_mirror_h(_S_MAPS_OBJ *pObj,int posx, int posy,_S_MAPS_OBJ *pTarget){
	for(int iy=0;iy < pObj->m_header.m_nHeight;iy++) {
			for(int ix = 0; ix < pObj->m_header.m_nWidth;ix++) {
				       
                        map_PutTile(pTarget,posx - ix, iy+posy,
						pObj->m_pBuf[iy*pObj->m_header.m_nWidth + ix]);
                        
                        // 자동차 회전 90도 ex)2
                       // map_PutTile(&pTarget,posx ,posy,
						//pObj->m_pBuf[iy*pObj->m_header.m_nWidth + ix]);
			}
		}

	}

        void map_drawTile_mirror_v(_S_MAPS_OBJ *pObj,int posx, int posy,_S_MAPS_OBJ *pTarget){
	for(int iy=0;iy < pObj->m_header.m_nHeight;iy++) {
			for(int ix = 0; ix < pObj->m_header.m_nWidth;ix++) {
				       
                        map_PutTile(pTarget,ix+posx ,posy- iy,
						pObj->m_pBuf[iy*pObj->m_header.m_nWidth + ix]);
                        
                        // 자동차 회전 90도 ex)2
                       // map_PutTile(&pTarget,posx ,posy,
						//pObj->m_pBuf[iy*pObj->m_header.m_nWidth + ix]);
			}
		}

	}

void map_drawTile_trn(_S_MAPS_OBJ *pObj,int posx, int posy,_S_MAPS_OBJ *pTarget){
	for(int iy=0;iy < pObj->m_header.m_nHeight;iy++) {
			for(int ix = 0; ix < pObj->m_header.m_nWidth;ix++) {
                
                if(pObj->m_pBuf[iy*pObj->m_header.m_nWidth + ix] != 0){ //스킵,필터,
				       
                        map_PutTile(pTarget,ix + posx, iy+posy,
						pObj->m_pBuf[iy*pObj->m_header.m_nWidth + ix]);
                }
                   
			}
		}

	}


