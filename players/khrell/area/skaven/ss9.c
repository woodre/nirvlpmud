#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" [Slums]");
   set_long(
"   This is a dead end here.  With chisled walls that tower well\n"+
"over your head and into the dark expanse far above.\n");
   set_light(-1);
   add_property("fight_area");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "walls", "Chisled granite blocks placed in an uneven manner"});
   dest_dir = ({
         "players/khrell/area/skaven/ss8.c", "south"});
   move_object(clone_object("/players/khrell/monster/skaven/snikch.c"), this_object());
   return 1; }
