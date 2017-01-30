#include "/players/khrell/define.h"
#include "/players/khrell/ansi.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIG+"Goblin Caves"+NORM);
   set_long(
"   The tunnel continues and the stone gives a cramped feeling. Here\n"+
"and there the support beams creak and groan slightly as if barely\n"+
"holding back the stone overhead. Some sounds seem to be coming from\n"+
"the north.\n");      
   set_light(-1);
   add_listen("main", "You hear the creak and groan of the beams above\n");
   add_listen("sounds", "You hear some vague sounds from the north\n");
   add_smell("main", "You smell nothing special\n");
   items = ({
         "beams", "Numerous cracks mar their imperfect surface",
         "tunnel", "It slopes up slightly north and descends south",
         "stone", "It appears to be granite or some other rock like substance"});
   
   dest_dir = ({
         "players/khrell/area/goblins/gobrm2", "south",
         "players/khrell/area/goblins/gobrm4", "north",
         });
   move_object(clone_object("/players/khrell/monster/goblins/gobmob.c"), this_object());
   return 1; }
