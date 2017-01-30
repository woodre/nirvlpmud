#include "/players/khrell/define.h"
#include "/players/khrell/ansi.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIK+"The Underways"+NORM+" ("+HIW+"Tunnel"+NORM+")");
   set_long(
"   This tunnel is very cramped.  It's as if something short, and at\n"+
"ease in these conditions casually scraped and dug its way through \n"+
"the solid rock.  It looks to be quite long and continues to the \n"+
"south.\n");
   set_light(-1);
   add_property("fight_area");
   add_property("no_teleport");
   add_property("no_follow");
   add_property("no_magic");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "tunnel", "It is quite long and goes far to the south",
         "rock", "Solid stone that had been tunnled through"});
   dest_dir = ({
         "players/khrell/area/skaven/under2.c", "south",
         "players/khrell/area/underways/undermdh19.c", "north"});
   return 1; }
