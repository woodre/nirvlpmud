#include "/players/khrell/define.h"
#include "/players/khrell/ansi.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIK+"The Underways"+NORM+" ("+HIW+"Grotto"+NORM+")");
   set_long(
"   The tunnel here opens into a naturally formed grotto with jutting\n"+
"stalagmites and stalagtites.  A creeping darkness loosely lurks near\n"+
"the edges of this grotto.\n");
   set_light(-1);
   add_property("fight_area");
   add_property("no_teleport");
   add_property("no_follow");
   add_property("no_magic");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "grotto", "you are in this right now and it is large",
         "stalagmites", "Large spikes of rock that remind you of sharp fangs",
         "stalagtites", "large spikes of rock that remind you of sharp fangs",
         "darkness", "In the absense of light it exists"});
   dest_dir = ({
         "players/khrell/area/skaven/under17.c", "north",
         "players/khrell/area/skaven/under19.c", "south"});
   return 1; }
