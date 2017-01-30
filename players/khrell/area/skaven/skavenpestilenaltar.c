#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" ["+YEL+"Pestilens"+NORM+"]");
   set_long(
"   These are the sacrifical chambers dedicated to the 'Horned Rat'. It\n"+
"also serves as the place the current Plague Lord gives out his fevered\n"+
"visions to his devoted.\n");
   set_light(-1);
   add_property("fight_area");
   add_property("no_teleport");
   add_property("no_follow");
   add_listen("main", "You hear the distant buzzing of flies.\n");
   add_smell("main", "It smells so bad here you want to vomit.\n");
   dest_dir = ({
         "players/khrell/area/skaven/skavenpestilenhall.c", "south"});
   move_object(clone_object("/players/khrell/monster/skaven/nurglitch.c"), this_object());
   return 1; }
