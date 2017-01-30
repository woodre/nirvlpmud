#include "/players/wocket/closed/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
if(arg) return;
set_id("bench");
set_short("A stone bench");
set_long("A nice stone bench.  It seems to have seen many years in this park\n"+
         "from the weathering of it.  You may 'sit' on it with your loved one.\n");
}

get(){ return 0; }

init(){
  add_action("sit","sit");
}

sit(){
  write("You sit down upon the bench.\n");
  say(this_player()->query_name()+" sits on the bench.\n");
  return 1;
}
