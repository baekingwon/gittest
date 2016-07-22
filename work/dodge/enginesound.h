#ifndef __ENGINE__SOUND__

#define __ENGINE__SOUND__
#include <windows.h>

#define DO    262
#define RE    294
#define MI    330
#define PA    349    
#define SOL    392
#define RA    440
#define SI    449
#define _DO    524

int Stage_Clear_Sound(){

Beep(DO, 500); /* 레 음계 */

Beep(MI, 500); /* 솔 음계 */

Beep(SOL, 500); /* 높은도 음계 */

}



int Boom_Sound(){

Beep(RE, 100); /* 레 음계 */

Beep(SOL, 100); /* 솔 음계 */

Beep(_DO, 100); /* 높은도 음계 */

}






#endif
