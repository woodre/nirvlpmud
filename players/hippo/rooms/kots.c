inherit "room/room";
#include "room.h"
#include "/players/hippo/bs.h"

reset(arg) {
   if(arg) return;
   short_desc = "Woush... what a mess!" ;
   long_desc = "Maybe you'd have been better off not having chose this dir to go!"+BS+
      "What the hell is this? What is this crap? You can't see anything, "+BS+
      "and this substance is biting you!"+BS;
    dest_dir =
   ({
   "/room/jetty2.c","help",
    }) ;
    set_light(1) ;
}

init()  {
	::init();
add_action ("help","help");
	}

help() {
say(this_player()->query_name()+" leaves with the puke"+BS);
move_object(this_player(),"/room/jetty2.c");
write("You are sitting in the middle of a substance of all wierd hard"+BS+
   "little pieces of recognizable food, combined with a yellow fluid"+BS+
   "you don't like at all. But you're outside the body, and that's"+BS+
   "what you wanted, right?"+BS);
command("look",this_player());
say("Hippo pukes... and you see "+this_player()->query_name()+" falling down with it!"+BS);
return 1;
}
