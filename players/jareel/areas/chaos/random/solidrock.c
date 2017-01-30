#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/tvroom.c";

reset(arg){
  if(arg) return;
  short_desc = MAG+"Solid Rock"+OFF;
}

init(){
  if(this_player()){
    this_player()->hit_player(100000);
  }
add_action("nodo"); add_xverb("");
}

nodo(str){
  if(str == "quit") return 0;
  write("You can not do that since you are stuck in solid rock.\n");
  return 1;
}
