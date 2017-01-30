#include "/players/khrell/define.h"
#include "/players/khrell/ansi.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIK+"The Underways"+NORM+" ("+HIW+"Tunnel"+NORM+")");
   set_long(
"   This tunnel here leaves nothing to the imagination, and is\n"+
"nothing more then a poorly made passage through the solid rock,\n"+
"made by some unknown diggers, it goes to the north and south.\n");
   set_light(-1);
   add_property("fight_area");
   add_property("no_teleport");
   add_property("no_follow");
   add_property("no_magic");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "tunnel", "It goes to the north and south",
         "passage", "It goes to the north and south"});
   dest_dir = ({
         "players/khrell/area/skaven/under20.c", "north",
         "players/khrell/area/skaven/under22.c", "south"});
   return 1; }
