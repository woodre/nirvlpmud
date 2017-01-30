#include "/players/khrell/define.h"
#include "/players/khrell/ansi.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIK+"The Underways"+NORM+" ("+HIW+"Tunnel"+NORM+")");
   set_long(
"   To the north is a grotto and to the south is an all too familiar\n"+
"tunnel.  This passage is unimpressive and the edges of it seem to\n"+
"absorb the light as if feeding off of it.\n");
   set_light(-1);
   add_property("fight_area");
   add_property("no_teleport");
   add_property("no_follow");
   add_property("no_magic");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
"grotto", "It is to the north",
"tunnel", "It is to the south",
"passage", "A median between the grotto and the tunnel",
"edges", "You can't quite make them out even upon close inspection"});
   dest_dir = ({
         "players/khrell/area/skaven/under18.c", "north",
         "players/khrell/area/skaven/under20.c", "south"});
   return 1; }
