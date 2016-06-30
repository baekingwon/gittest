
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <stdio.h>
#include "engine2d.h"

struct termios orig_termios;


//키눌렀을때 블로킹 현상 제거 (쓰레드안쓰고 비동기구현)
//키눌렀을때 즉시처리
//블로킹 현상 제거 하는 방법 논블럭킹


// upcount
/*
int main(){

    int nCount=0;
    int nLoop=1;
    while(nLoop){
        printf("%d \r",nCount++);
    }

    return 0;
}
*/
//////



struct termios orig_termios;

void reset_terminal_mode()
{
	tcsetattr(0, TCSANOW, &orig_termios);
}

void set_conio_terminal_mode()
{
	struct termios new_termios;

	/* take two copies - one for now, one for later */
	tcgetattr(0, &orig_termios);
	memcpy(&new_termios, &orig_termios, sizeof(new_termios));

	/* register cleanup handler, and set the new terminal mode */
	atexit(reset_terminal_mode);
	cfmakeraw(&new_termios);
	tcsetattr(0, TCSANOW, &new_termios);
}

int kbhit() //키보드 입력들어왔는지 판단 함수
{
	struct timeval tv = { 0L, 0L };
	fd_set fds;
	FD_ZERO(&fds);
	FD_SET(0, &fds);
	return select(1, &fds, NULL, NULL, &tv);
}

int getch()  //키보드 입력 받기
{
	int r;
	unsigned char c;
	if ((r = read(0, &c, sizeof(c))) < 0) {
		return r;
	} else {
		return c;
	}
}


int main(){
    set_conio_terminal_mode();
    int nCount=0;
    int bLoop=1;
    int xpos,ypos;
    xpos=0;ypos=1;
    char cmd;
    while(bLoop){
    // scanf("%c",&cmd);
        if(kbhit() != 0){
            cmd = getch();
            switch(cmd){
                case 'w':
                ypos-=1;
                break;
                case 's':
                ypos+=1;
                break;
                case 'a':
                xpos-=1;
                break;
                case 'd':
                xpos+=1;
                break;
                case 'q':
                bLoop = 0;
                break;
            }
            if(cmd == 'q'){
                bLoop =0;
            }
            printf("%d \r\n",(int)cmd);
        }
        printf("%d \r",nCount);
        nCount++;
        nCount %=10;

        system("clear");
        drawMyBox(xpos,ypos,0,44,1,3);
        drawMyBox(nCount,5,0,42,1,5);
        gotoxy(0,20);
        printf("-----------------------");

    }
    reset_terminal_mode();
    return 0;
}