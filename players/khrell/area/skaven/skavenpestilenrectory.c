#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" ["+YEL+"Pestilens"+NORM+"]");
   set_long(
"   Here is where the leperous abbott administers to his festering\n"+
"flock.  A large vat dominates the center of the room, and a foul\n"+
"and noxious vapor lazily climbs out from its inside.\n");  
   set_light(-1);
   add_property("fight_area");
   add_property("no_teleport");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell disgusting  odors in here.\n");
   items = ({
         "vat", "It is here the plague monks create new plagues",
         "vapor", "The by-product of whats been created in the vat"});
   dest_dir = ({
         "players/khrell/area/skaven/skavenpestilenhall.c", "north"});
   move_object(clone_object("/players/khrell/monster/skaven/plaguepriest.c"), this_object());
   return 1; }
