inherit "room/room";
#include "room.h"
#include "/players/hippo/bs.h"

reset(arg) {
   if(arg) return;
    short_desc = "Woush... what a mess!" ;
   long_desc = "You can't go back now.. this is it! "+BS+                       
      "'Thank you for filling my stomach', you hear Hippo saying"+BS;
    dest_dir =
   ({
    "/room/jetty2.c" ,"hole"  ,
    }) ;
    set_light(1) ;
}

init()  {
	::init();
	add_action("hole","hole");
	}

hole() { 
say(this_player()->query_name()+" leaves hole.\n");
move_object(this_player(),"/room/jetty2.c");
write("You are thrown out of the rectum, through a strange hole"+BS+
   "that was growing bigger and bigger as you came closer."+BS+
   "As you look up, you realize that the hole must have been the"+BS+
   "anus, at the other end of the digestive channel as you entered"+BS+
   "a while ago. "+BS+
   "But then you realize two things. First: you came here through"+BS+
   "Hippo's anus! And second: what you see around you, must be "+BS+
   "something you normally drop into a toilet! And it's Hippo's!!!! "+BS+
   ""+BS+
   "As you start to think that you wanna kill him for this, you"+BS+
   "stand up and see the hand where this all started, in front of you."+BS+BS);
command("look",this_player());
say("You see "+this_player()->query_name()+" sitting in front of you in Hippo's shit"+BS);
return 1;
}
