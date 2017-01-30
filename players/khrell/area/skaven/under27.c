#include "/players/khrell/define.h"
#include "/players/khrell/ansi.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIK+"The Underways"+NORM+" ("+HIW+"Tunnel"+NORM+")");
   set_long(
"   The cramped tunnel widens slightly opening up towards the south\n"+
"and narrowing to the north. You can smell a faint aroma of something\n"+
"unplesant to your nose.\n");
   set_light(-1);
   add_property("fight_area");
   add_property("no_teleport");
   add_property("no_follow");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell a faint unplesant odor.\n");
   dest_dir = ({
         "players/khrell/area/skaven/under26.c", "north",
         "players/khrell/area/skaven/under28.c", "south"});
   return 1; }
