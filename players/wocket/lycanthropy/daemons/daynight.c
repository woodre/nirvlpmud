#include "/players/wocket/closed/ansi.h"
int isNight;
int startTime,difTime;
int phase;
string msg;

reset(arg){
  if(!arg){
    startTime = time();
  }
  if(arg){
    if(isNight){
    isNight = 0;
    } else {
    isNight = 1;
    }
    phase++;
    switch(phase){
    case 0: msg = ""; break;
    case 1: msg = "The moon begins to rise above the horizon."; break;
    case 2: msg = "The moon shines bright across the sky."; break;
    case 3: msg = "The moon sets below the horizon."; break;
    default: phase = 0; break;
}
    difTime = time()-startTime;
    if(find_player("wocket")){
      tell_object(find_player("wocket"),BOLD+"The daemon has been reset: isNight = "+isNight+".\n"+OFF);
      tell_object(find_player("wocket"),BOLD+"time: "+startTime+"  current time:"+time()+"  dif:"+difTime+" \n"+OFF);
    }
  }
}


query_isNight(){ return isNight; }
