#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
/*
int testArr[5] = {100,101,102,103,104};
char testArr2[5] = {100,101,102,103,104};
int main(){


    printf("%d \r\n",testArr[1]); //1번결과갑


int *pTemp = testArr;  //배열 처음 시작번지를 받아옴.

printf("%d \r\n",pTemp[1]); //카피해서 씀.. 즉 1번결과값시 같다.
printf("%d \r\n",pTemp[2]); //
printf("%d \r\n",pTemp[3]); //
printf("%d , %d , %d\r\n",pTemp,pTemp+1,pTemp+2); //int 4바이트니, 4바이트만큼 건너 뜀
printf("%d , %d , %d\r\n",*pTemp,*(pTemp+1),*(pTemp+2));

char *pTemp2 = testArr2;

printf("%d , %d , %d\r\n",*pTemp2,*(pTemp+1),*(pTemp+2)); 


return 0;
}
*/

/*
int main()
{
    int num1 = 2016;
    int num2 = num1;
    int *ptrTemp = &num1;

    printf("%d, %d \r\n",num1,*ptrTemp);
    *ptrTemp = 2015;
     printf("%d, %d, %d \r\n",num1,*ptrTemp,num2);
}
*/
/*
int main(){
    int test1[] = {1,2,3,4,5};
    int *ptrTemp1;
    char *ptrTemp2;

    ptrTemp1 = test1;
    ptrTemp2 = (char*)test1; //타입캐스트,강제형변환,케릭터형이니..

     printf("%d %d \r\n",ptrTemp1[0],ptrTemp1[1]);
     printf("%d %d \r\n",ptrTemp2[0],ptrTemp2[1]);

     printf("%x %x \r\n",ptrTemp1,ptrTemp1+1);
     printf("%x %x \r\n",ptrTemp2,ptrTemp2+1);

     printf("%x %x \r\n",ptrTemp1,ptrTemp1+1);
     printf("%x %x \r\n",ptrTemp2,ptrTemp2+4);

     printf("%x %x \r\n",*ptrTemp1,ptrTemp1[1]);
     printf("%x %x \r\n",*ptrTemp2,*(ptrTemp2+4));
}
*/

int main(){
    int nCount = 0; //초기화
     int nCount2 = 0;
    struct timespec work_timer;
    double last_tick =0;
    double acc_tick =0;
    double acc_tick2=0;

    while(1)
    {
            clock_gettime(CLOCK_MONOTONIC,&work_timer);
            double cur_tick = work_timer.tv_sec + (double)(work_timer.tv_nsec * 1e-9);
        
        double delta_tick = cur_tick - last_tick; //시차
        last_tick = cur_tick; //시차비교해서 값을 루프 돌림
        acc_tick += delta_tick; //시차누적
        acc_tick2 += delta_tick;

        if(acc_tick > 1.0){ //누적시차가 1초보다 크면
            nCount++;
            acc_tick = 0; //값초기화
        }
        if(acc_tick2 > 0.3){
            nCount2++;
            acc_tick2 = 0;
        }

        printf("%d %d \r",nCount,nCount2);
        
    }
}