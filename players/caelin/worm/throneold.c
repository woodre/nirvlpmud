#include "universal.h"
inherit ROOM;

reset(arg) {
   if(arg) return;
   set_light(1);
  set_short(RED+"Worm's Throne Room"+NORM);
   set_long(
"This dimly lit room extends in length from the massive doors \n"+
"to a dais at the far end. On the dais sits a large throne-like \n"+
"chair. In front of the dais there is one spot in the room where \n"+
"all the lights seem to focus, as if to give the throne's occupant \n"+
"a clearer view of whoever approaches. The rest of the room is \n"+
"lost in greater and smaller darknesses.  The wary find that they \n"+
"feel glad that shadows hide so much of this room.  Still, they \n"+
"cannot help but wonder what inhabits this private sanctuary \n"+
"of the man who has sacrificed so much to serve his god.\n\n\n"
+RED+"Worm's Bloody Throne\n"+NORM);
add_exit("/players/vertebraker/closed/shardak/room/grotto.c","grotto");

add_item("throne","Worm's kick ass throne.  It is made of the bones of his enemies and covered with the skins of those who have been disloyal to the guild.\n");


   add_item("stain",
      "This reddish stain was caused perhaps by ..\n"+
      " bloodshed? .. Hmm");
   add_item("hole",
      "The large hole seems to be hiding something behind it....");
   add_item("wall",
      "The large stone wall on your left has a large hole\n"+
      "in the middle of it.\n");
}

okay_follow() { return 1; }
init() {
  ::init();
  add_action("sit","sit"); }

sit(){
  write("You sit your fat, lazy ass down.\n");
   say("Worm sits on his throne like the pimp motha fucker he is.\n");
   return 1;
}
