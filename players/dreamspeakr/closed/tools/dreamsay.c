/* Coded by wocket for dreamspeakr */

#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/treasure";

reset(){
  set_id("dreamsay");
}

init(){
#ifndef __LDMUD__
add_action("xsay");add_xverb("'");
#else
  add_action("xsay", "'", 3);
#endif
add_action("xsay","say");
}

xsay(string str){
write(HIB+"You say: "+NORM+str+"\n");
say(HIB+"Dreamspeakr says: "+NORM+str+"\n");
return 1;
}
