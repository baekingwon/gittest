//test2 2016.6.29 수 day2


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "engine2d.h"



int main(){
/*
	char *code = "★"; //문자열 포인터 선언
	printf("☏ \r\n"); //유니코드
	printf("%s \r\n",code); 
    printf("%x,%x,%x \r\n",code[0],code[1],code[2]); //코드로변환
	
	//e296

	printf("\u96e2\r\n"); 



int clear_o(){
	Sleep(2000);
    system("clear");
	Sleep(2000);
}

/////////////////////////////////////////////// part1
	clear_o();
///////////////////////////////////////////////


	
      int num1 = 10 , num2 = 20;
      printf("%d %d\r\n",num1, num2);

      int num3, num4;
	  num3 = 30;
	  num4 = 40;
	  printf("%d %d\r\n",num3, num4);


/////////////////////////////////////////////// part2
	clear_o();
///////////////////////////////////////////////

        int num5, num6;
        printf("1값을 입력하세요: ");
		scanf("%d,%d", &num5,&num6);
		printf("%d+%d=%d\r\n",num5, num6, num5+num6);
        printf("%d-%d=%d\r\n",num5, num6, num5-num6);
        printf("%d×%d=%d\r\n",num5, num6, num5*num6);
	    printf("%d÷%d=%d\r\n",num5, num6, num5/num6);

/////////////////////////////////////////////// part3
	clear_o();
///////////////////////////////////////////////


	   float num7, num8;
	   //num7 = 3.14;
	   //num8 = 9.8;
        printf("2값을 입력하세요: ");
	    scanf("%f,%f",&num7,&num8);
	    printf("%f+%f=%f\r\n",num7, num8, num7+num8);
        printf("%f-%f=%f\r\n",num7, num8, num7-num8);
        printf("%f×%f=%f\r\n",num7, num8, num7*num8);
	    printf("%f÷%f=%f\r\n",num7, num8, num7/num8);


/////////////////////////////////////////////// part4
	clear_o();
///////////////////////////////////////////////



        char *name = "Andrew Thomas Weil";
	    printf("%s \r\n",name);

		
		char first_name[32];
		char last_name[32];
		printf("이름을 입력하세요: ");
		scanf("%s %s",first_name,last_name);
		printf("my name is %s %s \r\n",first_name,last_name);


/////////////////////////////////////////////// part5
	clear_o();
/////////////////////////////////////////////// 문자열
	

       //str은 string
	  //char *strTemp = "hello world!";
		char strTemp[] = "hello world!";
		int index;

		
		printf("%s \r\n",strTemp);
		printf("%c \r\n",101);  //아스키코드
		printf("문자를 선택하세요...\r\n");

		scanf("%d",&index);

		strTemp[index] = strTemp[index] + 1; //암호화

		printf("%c , %d \r\n",strTemp[index],strTemp[index]);



/////////////////////////////////////////////// part6
	clear_o();
/////////////////////////////////////////////// 2d엔진헤더연결테스트
	

	
	setColor(32,44);
	printf("hello");
	setColor(0,0);

	
/////////////////////////////////////////////// part7
	clear_o();
/////////////////////////////////////////////// 




   printf("10 진수 상수 12 : %d\n", 12);
   printf("8 진수 상수 014 : %d\n", 014);
   printf("16 진수 상수 0xc : %d\n", 0xc);

   //음의보수 양의보수 테스트영역
  
   //1111 1111
   //0111 1111 = 127, 0x7f
   //1000 0000 = 128, 0x80
   //1111 1111 = 255, 0xff
  
   char a = 0xFF;  //양수 값 오버테스트 

   printf("%d , % d \r\n",a,0xFF); //값 오버되서 출력 이상하게나옴

////////////////////////////////////////////////
   char b= 0x7f; //양수의 최대범위
   
   printf("%d , % d \r\n",b,0x7f); //값정상출력

   ////////////////////////////////////////////

   a=0x80;
   printf("%d , %d \r\n",a,0x80); //음수범위

   /////////////////////////////////////////////

   a = 0xff;
   printf("%d , %d \r\n",a,0xff);
  ///////////////////////////////////

   unsigned char c = 0xff; 
   printf("%d \r\n",c);  //255정상출력 이유 부호가없기때문에.. 그리고, 버그잡을때 씀?
  ///////////////////////////////////////
   
  int d = 0xff;
  int f = 0xffffffff;
  int g = 0x7fffffff;
  int h = 0x80000000; //0x7fffffff에 1더한값
  
  int i = 255;
  char j = i;
  unsigned char k = i;
 
  printf("%d \r\n",d); //정상출력
  printf("%d \r\n",f); //값 오버
  
  printf("%d \r\n",g); // int 로 표현할 수 있는 가장 큰 수 양수범위

  printf("%d \r\n",h); // int 로 표현할 수 있는 가장 큰 수 음수범위

 // printf("%d , %d\r\n"(unsigned char)j, k);  //언사인드 케릭터 강제적으로 형 치환(타입케스트)
	

///////////////////////////////////////////

	
	 printf("%f \r\n",314e-2);  //지수표현
////////////////////////////////////////////


///자료형 크기 확인
 printf("char형의 크기 : %d\n", sizeof(char));
 printf("short형의 크기 : %d\n", sizeof(short));
 printf("int형의 크기 : %d\n", sizeof(int));
 printf("long형의 크기 : %d\n", sizeof(long));
 printf("float형의 크기 : %d\n", sizeof(float));
 printf("double형의 크기 : %d\n", sizeof(double));
 printf("long double형의 크기 : %d\n", sizeof(long double));
///////////////////////////////////////////////
	
//변환문자열을 사용한 다양한 데이터의 출력방법
 char ch = 'A';
 char name1[80]="뽕금박지";
 int in=10;
 double db=16.8;

 printf("정수형 상수의 출력 : %d\n", -10);
 printf("정수형 변수의 출력 : %d\n", in);
 printf("정수형 수식의 출력 : %d\n", in/3);

 printf("실수형 상수를 소수점 형태로 출력 : %lf\n",2.5);
 printf("실수형 변수를 지수 형태로 출력 : %le\n",db);
 printf("실수형 수식을 소수점 형태로 출력 : %1f\n",db/4);

 printf("문자상수의 출력 : %c\n", 'F');
 printf("문자변수의 출력 : %c\n", ch);
 printf("문자 배열의 출력 : %s\n", name1);
 printf("문자열상수의 출력 : %s\n","날아라 태극호");

/////////////////////////////////////////////// part8
	clear_o();
/////////////////////////////////////////////// 


   //조건식에사용되는 관계연산자
    int res = 1 > 2;

    printf("%d \r\n",res);

    res= 1 < 2;
    printf("%d \r\n",res);

    res = (1 == 2);
    printf("1==2 %d \r\n",res);

    res = (1 != 2);
    printf("1!=2 %d \r\n",res);

    res = (2 <= 2);
    printf("2<=2 %d \r\n",res);



    printf("%d,%d,%d,%d \r\n",(1&&1),(1&&0),(0&&1),(0&&0)); //and연산
    printf("%d,%d,%d,%d \r\n",(1||1),(1||0),(0||1),(0||0)); //or연산
    printf("%d \r\n",(!1<2)); //부등호

 /////////////////////////////////////////////// part8
	clear_o();
/////////////////////////////////////////////// 


 //비교연산
    int num0;
    printf("input :");
    scanf("%d",&num0);
    if(num0 > 5){
        printf("5보다 큽니다. \r\n");
    }
    else if(num0 > 3){
        printf("3보다는 큽니다. \r\n");
    }
    else{
        printf("5보다 작습니다. \r\n");

    }
 /////////////////////////////////////////////// part8
	clear_o();
/////////////////////////////////////////////// 
*/

//숫자 찾는 간단한 게임
//5~9
//
int num9;
scanf("%d",&num9);

if(num9 <= 9 && num9 >= 5){ //구간지정, 5~9사이

    printf("bingo! \r\n");
}

printf("game over \r\n");







	return 0;
}