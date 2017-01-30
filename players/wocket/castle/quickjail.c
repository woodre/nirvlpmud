#include "/players/wocket/closed/ansi.h"
inherit "room/room";

reset(arg){
    if(arg) return;
    short_desc = HIB+"A Holding Cell"+NORM;
}

init(){
if(this_player()->query_level() < 21){
    add_action("psay","say");
#ifndef __LDMUD__
   add_action("psay"); add_xverb("'");
   add_action("stopcmds");add_xverb("");

#else
   add_action("psay", "'", 3);
   add_action("stopcmds","", 3);

#endif
}

}

int psay(string str){
write("ok.\n");
say(this_player()->query_name()+" says: "+str+"\n");
return 1;
}

int stopcmds(){
write("You cant do that here.\n");
return 1;
}
