
#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/treasure";


reset(arg){
set_weight(0);
  }


init(){
  ::init();
  
  }
short () { 
  return (HIG+"--`--}"+ HIB +"@ "+NORM+"Francesco's "+HIY+"golden "+NORM+"wedding ring (hmmm, I am not married)");
}

void long() { 
  write("You see a wide band of pure gold, simple and elegant.\n\n"); 
  write("Type \"help ring.\"\n");
}

id(str) {return str=="ring";}