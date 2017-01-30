#include "/players/khrell/define.h"
#include "/players/khrell/ansi.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIK+"The Underways"+NORM+" ("+HIW+"Tunnel"+NORM+")");
   set_long(
"   The tunnel widens here and allows one to stand up nearly strait\n"+
"up.  Crude chunks of warpstone have been beaten to the walls to\n"+
"provide a minimum illumination in these cramped confines.  Randomly\n"+
"scattered about is the occasional stain of blood.  You do not feel\n"+
"entirely safe here.\n");
   set_light(0);
   add_property("fight_area");
   add_property("no_teleport");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "tunnel", "It goes north and south",
         "warpstone", "They provide the minimum illumination",
         "walls", "Small ammounts of warpstone have been hammered here",
         "blood", "Despite the passage of time the blodo has not dried"});
   dest_dir = ({
         "players/khrell/area/skaven/under7.c", "north",
         "players/khrell/area/skaven/under9.c", "south"});
   return 1; }
