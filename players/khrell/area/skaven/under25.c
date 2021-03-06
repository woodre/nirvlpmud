#include "/players/khrell/define.h"
#include "/players/khrell/ansi.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIK+"The Underways"+NORM+" ("+HIW+"Tunnel"+NORM+")");
   set_long(
"   The dull throbbing glow of warpstone dot this section of tunnel.\n"+
"It is cramped and is the same poorly made passage through solid rock\n"+
"by some unknown diggers, it goes to the north and south.\n");
   set_light(-1);
   add_property("fight_area");
   add_property("no_teleport");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   dest_dir = ({
         "players/khrell/area/skaven/under24.c", "north",
         "players/khrell/area/skaven/under26.c", "south"});
   return 1; }
