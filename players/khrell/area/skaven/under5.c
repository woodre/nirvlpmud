#include "/players/khrell/define.h"
#include "/players/khrell/ansi.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIK+"The Underways"+NORM+" ("+HIW+"Tunnel"+NORM+")");
   set_long(
"   The tunnel continues and narrows again. it leaves nothing to\n"+
"the imagination and is a poorly made passage through solid rock.\n"+ 
"The tunnel, made by some unknown means, it goes to the north and\n"+
"south.\n");
   set_light(-1);
   add_property("fight_area");
   add_property("no_teleport");
   add_property("no_magic");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "tunnel", "It's long it's dark and it goes to the north and south",
         "passage", "It goes to the north and south"});
   dest_dir = ({
         "players/khrell/area/skaven/under4.c", "north",
         "players/khrell/area/skaven/under6.c", "south"});
   return 1; }
