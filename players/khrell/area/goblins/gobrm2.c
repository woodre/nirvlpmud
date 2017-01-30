#include "/players/khrell/define.h"
#include "/players/khrell/ansi.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIG+"Goblin Caves"+NORM);
   set_long(
"   Only the occasional drip of water and the complete lack of moving\n"+
"air give this area a humid oppresive atmosphere.  The dampness here \n"+
"makes it hard to draw any sort of refreshing breath.  Again placed\n"+
"around the walls are the poorly constructed support beams.  A few\n"+
"puddles splash about ones feet and you can see where it continues\n"+
"up ahead.\n");
             
   set_light(-1);
   add_listen("main", "You hear just a slight dripping of water\n");
   add_listen("drip", "You hear the slow drip of water\n");
   add_listen("dripping", "You hear the dripping of water\n");
   add_smell("main", "You smell only the stale fetid air\n");
   add_smell("air", "You smell only the stale fedit air\n");
   items = ({
         "beams", "They seem to be stable, but only just so.",
         "tunnel", "It looks to be of poor quality and not too stable,",
         "walls", "They are roughly formed and not a natural formation."
         });
   dest_dir = ({
         "players/khrell/area/goblins/gobrm1", "south",
         "players/khrell/area/goblins/gobrm3", "north"
         });
   move_object(clone_object("/players/khrell/monster/goblins/gobmob.c"), this_object());
   return 1; }
init()
{
	   ::init(); 
	   
   add_action("go_south","south");
   add_action("go_south","s");
}

go_south()
{
   if(!this_player()) return;
   if(this_player() && this_player()->is_player())
      return 0;
   else
      return 1;
}

         