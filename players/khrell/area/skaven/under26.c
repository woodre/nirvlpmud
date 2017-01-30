#include "/players/khrell/define.h"
#include "/players/khrell/ansi.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIK+"The Underways"+NORM+" ("+HIW+"Tunnel"+NORM+")");
   set_long(
"   The tunnel here leaves nothing to the imagination, and is\n"+
"nothing more then a poorly made passage through the solid rock,\n"+
"made by unknown diggers, it goes to the north and south.\n");
   set_light(-1);
   add_property("fight_area");
   add_property("no_teleport");
   add_property("no_follow");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   dest_dir = ({
         "players/khrell/area/skaven/under25.c", "north",
         "players/khrell/area/skaven/under27.c", "south"});
   return 1; }
