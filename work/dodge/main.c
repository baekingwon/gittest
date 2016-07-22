
#include "headers.h"

//추가예정 피버모드
//



#define kbESC 0x1B
struct timespec work_timer;
double acc_tick, last_tick; //전역변수선언부
int bLoop = 1;
pthread_t tid;

static int nFSM = 0;
static int nStep = 0;

_S_MAPS_OBJ gScreenBuffer;  //전역변수앞에 가독성을위해 g(global)를 삽입.
_S_MAPS_OBJ gBackBuffer; //잔상제거용
_S_MAPS_OBJ gF22Raptor; // F2s2 랩터 전투기 오브젝트.
_S_MAPS_OBJ gStar; //별
_S_MAPS_OBJ gF22Bullet; //총알 오브젝트
_S_MAPS_OBJ gF22Boom; //폭탄
_S_MAPS_OBJ gF22Boomeff; //폭탄이펙트

_S_Plane gPlayerPlane; //player object



//Game OBJ definition.


_S_BULLET_OBJ g_bullets[100]; //총알갯수

S_STAR_OBJ g_stars[100];
S_BOOM_OBJ g_booms[1]; //폭탄갯수
S_BOOMEFF_OBJ g_boomeffs[1]; //이펙트갯수

void *doSomeThing(void *arg){

	int nCount = 0;
	while(1)
	{     gotoxy(50,24);
		printf("TIME: %d\r\n",nCount);
		//puts("test");
		//sleep(1);
		nCount++;
	}
    return NULL;

}

    void apply_mainTitle()
{
	switch(nStep) {

		case 0:
         setColor(36,1);
        puts("\r\n");
        puts("\r\n");
        puts("\r\n");
        puts("별 피하기 V 0.0.1");
		puts("press anykey start");
        
		nStep = 1;
		break;
		case 1:
		//사용자 입력처리 
		if(kbhit() != 0) {
			
			char ch = getch();
			nFSM = 1;
			nStep = 0;
		}
		break;
	}

}


void PlayGame(double delta_tick)
{

	 int targetx,targety;

	targety = 3;
	targetx = 2;

    


	int fire_x = 24; //bullet_pos_x;
	int fire_y = 12; //bullet_pos_y;

     
  
  

    //user input
			if(kbhit() != 0) {
				char ch = getch(); //
				 if(ch == 'q') { //if press key "q" then,
					bLoop = 0; //exit loop.
                    system("clear");
                   
                    puts("bye~ \r"); // and stream "bYE~".
				}


       else if(ch==',') {
         
                Beep(RE, 100); /* 레 음계 */
				for(int i=0;i<sizeof(g_bullets)/sizeof(_S_BULLET_OBJ);i++) {
					_S_BULLET_OBJ *pObj = &g_bullets[i];
					if(pObj->m_nFSM == 0) { //슬립상태라면....

                /////////////////////////
                  double vx,vy,c;
				vx = targetx - fire_x;
				vy = targety - fire_y;
              

				c = sqrt(vx*vx+vy*vy);
				vx /= c;
				vy /= c;
                ///math.h함수 이용, 단위벡터(1) 을이용하여 정확히 1씩계산.
                ///////////////////////////////
            
					bullet_fire(pObj,
				        	gPlayerPlane.m_nXpos,
							gPlayerPlane.m_nYpos,10.0,1,0,10.0);

                                   
				
                                
                                //오브젝트,비행기x, 비행기 y, 속도, 방향1,방향2 ,라이프타임



              


						break;
					}
				}
       }
		



                   else if(ch=='.') {
                      
				for(int i=0;i<sizeof(g_booms)/sizeof(S_BOOM_OBJ);i++) {
					S_BOOM_OBJ *pObj = &g_booms[i];
					if(pObj->m_nFSM == 0) { //슬립상태라면....
                     setColor(33,1);
                    
                    Boom_Sound();
                /////////////////////////
                  double vx,vy,c;
				vx = targetx - fire_x;
				vy = targety - fire_y;
				c = sqrt(vx*vx+vy*vy);
				vx /= c;
				vy /= c;
                ///math.h함수 이용, 단위벡터(1) 을이용하여 정확히 1씩계산.
                ///////////////////////////////
                    
					boom_fire(pObj,
								gPlayerPlane.m_nXpos,
								gPlayerPlane.m_nYpos,6.0,1,1,0.5);
                                
          
                    
                                
                                //오브젝트,비행기x, 비행기 y, 속도, 방향1,방향2 ,라이프타임
        
  
       break;
      
					
					}
                }


              
                   
               
                            /////////////////////////
                    	for(int i=0;i<sizeof(g_boomeffs)/sizeof(S_BOOMEFF_OBJ);i++) {
					S_BOOMEFF_OBJ *pObj = &g_boomeffs[i];
					if(pObj->m_nFSM == 0) { //슬립상태라면....
                      
                /////////////////////////
                  double vx,vy,c;
				vx = targetx - fire_x;
				vy = targety - fire_y;
				c = sqrt(vx*vx+vy*vy);
				vx /= c;
				vy /= c;
                ///math.h함수 이용, 단위벡터(1) 을이용하여 정확히 1씩계산.
                ///////////////////////////////
                   

					boomeff_fire(pObj,
								gPlayerPlane.m_nXpos,
								gPlayerPlane.m_nYpos,0.2,0,0,2.0);

                                
                                //오브젝트,비행기x, 비행기 y, 속도, 방향1,방향2 ,라이프타임

     

						break;
                    
					}
				}
               
//////////////

       }
       


//////////////////////////////////////////////STAR 생성///////////////////////
	for(int i=0;i<sizeof(g_stars)/sizeof(S_STAR_OBJ);i++) {
					S_STAR_OBJ *pObj = &g_stars[i];
					if(pObj->m_nFSM == 0) { //슬립상태라면....


                /////////////////////////
                  double vx,vy,c;
				vx = targetx - fire_x;
				vy = targety - fire_y;
				c = sqrt(vx*vx+vy*vy);
				vx /= c;
				vy /= c;
                ///math.h함수 이용, 단위벡터(1) 을이용하여 정확히 1씩계산.
                ///////////////////////////////

					star_fire(pObj,
								gPlayerPlane.m_nXpos+fire_x,
								gPlayerPlane.m_nYpos+fire_y,5.0,vx,vy,10.0);

                                
                                //오브젝트,비행기x, 비행기 y, 속도, 방향1,방향2 ,라이프타임

     
			break;
					}
				}

		/////////////////////////////////////////////////////////////////////////////


            //3개를 적용해서 반응속도 개선. 갭을 늘림 대신 아이템 사이즈 커져야함.
			//Plane_Apply(&gPlayerPlane,delta_tick,ch);
           // Plane_Apply(&gPlayerPlane,delta_tick,ch);
            Plane_Apply(&gPlayerPlane,delta_tick,ch);

            }














            for(int i=0;i<sizeof(g_bullets)/sizeof(_S_BULLET_OBJ);i++){
                //pool <저장소역할>
                _S_BULLET_OBJ *pObj = &g_bullets[i];
                bullet_apply(pObj,delta_tick);
            }
              for(int i=0;i<sizeof(g_booms)/sizeof(S_BOOM_OBJ);i++){
                //pool <저장소역할>
               

                S_BOOM_OBJ *pObj = &g_booms[i];
                boom_apply(pObj,delta_tick);
                   
            }


          
                 for(int i=0;i<sizeof(g_boomeffs)/sizeof(S_BOOMEFF_OBJ);i++){
                //pool <저장소역할>
                S_BOOMEFF_OBJ *pObj = &g_boomeffs[i];
                boomeff_apply(pObj,delta_tick);
           
                }
         for(int i=0;i<sizeof(g_stars)/sizeof(S_STAR_OBJ);i++){
                //pool <저장소역할>
                S_STAR_OBJ *pObj = &g_stars[i];
                star_apply(pObj,delta_tick);
            }
         

            //calc timing(tick) 
			acc_tick += delta_tick;
            if(acc_tick > 0.1) {
                
                
                map_drawTile(&gBackBuffer,0,0,&gScreenBuffer);
                //잔상제거용
                //map_drawTile_trn(&gF22Raptor,xpos,ypos,&gScreenBuffer);
                //맵상에 랩터를 배치함;그려줌(오브젝트출력)
               
                Plane_Draw(&gPlayerPlane,&gScreenBuffer);
                
              for(int i=0;i<sizeof(g_bullets)/sizeof(_S_BULLET_OBJ);i++) {
				_S_BULLET_OBJ *pObj = &g_bullets[i];
                	
				bullet_draw(pObj,&gScreenBuffer);
               
 

			}
     

              for(int i=0;i<sizeof(g_booms)/sizeof(S_BOOM_OBJ);i++) {
				S_BOOM_OBJ *pObj = &g_booms[i];
				boom_draw(pObj,&gScreenBuffer);
          
              

			}

          
            	
           
             for(int i=0;i<sizeof(g_boomeffs)/sizeof(S_BOOMEFF_OBJ);i++) {
			   
            	S_BOOMEFF_OBJ *pObj = &g_boomeffs[i];
				
                
                boomeff_draw(pObj,&gScreenBuffer);
                
              
			}
            
              for(int i=0;i<sizeof(g_stars)/sizeof(S_STAR_OBJ);i++) {
			   
            	S_STAR_OBJ *pObj = &g_stars[i];
				
                
                star_draw(pObj,&gScreenBuffer);
     
              
			}
            

                gotoxy(0,0);
                puts("-----------------------------------\r");
                map_dump(&gScreenBuffer,Default_Tilepalete);
                puts("-----------------------------------\r");
                puts("move : w,a,s,d \r");
                puts("quit : q \r");
                
                    ///인터페이스창
                 gotoxy(50,3);
                 puts("--------SCORE------\r");
            
                        //별 갯수 카운팅.. 

			
                 gotoxy(50,9);
                 puts("------------------\r");
                 
                 gotoxy(50,10);
                 puts("--------ITEM------\r");

                 gotoxy(50,16);
                 puts("------------------\r");

                 gotoxy(50,17);
                 puts("--------MONEY-----\r");

                 gotoxy(50,23);
                 puts("------------------\r");

                 //////









                 //맵에 아이템 배치

                    //기존배치좌표에+3 +5
                    setColor(35,1);
                   gotoxy(18,17);
                   puts("#\r");
                   
                   
                   gotoxy(17,16);
                   puts("@\r");
                
                   gotoxy(15,16);
                   puts("$\r");
                   ////////////////

                 
                acc_tick = 0;

                //전체맵 색깔입히기
	             setColor(32,1);
               
                   
			}


       
        

            }


             


int main(){



    
         set_conio_terminal_mode();
        acc_tick=last_tick =0; //초기값 0

      
        system("clear");
         
       // system("field.mp3");
        //Shell("field.mp3");
       
       for(int i=0;i<2;i++){
        map_init(&gScreenBuffer); //맵초기화
        map_new(&gScreenBuffer,35,16); //맵 사이즈지정
       }

        //잔상제거용
        map_init(&gBackBuffer);
        map_new(&gBackBuffer,35,16);

        map_init(&gF22Raptor);//랩터 초기화
        map_load(&gF22Raptor,"plane.dat"); //랩터 템플릿 로드
      
        map_init(&gF22Bullet);
        map_load(&gF22Bullet,"plasma.dat");

        map_init(&gF22Boom);
        map_load(&gF22Boom,"boom.dat");
        
        map_init(&gF22Boomeff);
        map_load(&gF22Boomeff,"boomeff.dat");

        map_init(&gStar);
        map_load(&gStar,"star.dat");


     
      Plane_init(&gPlayerPlane,&gF22Raptor,15,11);
      

       for(int i=0;i< sizeof(g_bullets)/sizeof(_S_BULLET_OBJ) ;i++)
	{
		bullet_init(&g_bullets[i],0,0,0,&gF22Bullet);
       
	}

         for(int i=0;i< sizeof(g_booms)/sizeof(S_BOOM_OBJ) ;i++)
	{
		boom_init(&g_booms[i],0,0,0,&gF22Boom);
	}

             for(int i=0;i< sizeof(g_boomeffs)/sizeof(S_BOOMEFF_OBJ) ;i++)
	{
		boomeff_init(&g_boomeffs[i],0,0,0,&gF22Boomeff);
       
	}
               for(int i=0;i< sizeof(g_stars)/sizeof(S_STAR_OBJ) ;i++)
	{
		star_init(&g_stars[i],0,0,0,&gStar);
       
	}




    while(bLoop){

  
       //timing처리 
		clock_gettime(CLOCK_MONOTONIC,&work_timer);
		double cur_tick = work_timer.tv_sec + 
			(double)(work_timer.tv_nsec * 1e-9);
		double delta_tick = cur_tick - last_tick;
		last_tick = cur_tick;


if(nFSM == 0) { //게임시작전..
			apply_mainTitle(delta_tick);

		}
		else if(nFSM ==1 ) { //게임중..
			PlayGame(delta_tick);
           
            
              
       
            
   
            
        
		}
		else {
		}
       
  
	
	//char ch = getchar();

	

	//printf("u press %c key \r\n",ch);


            
}

	
return 0;
}
