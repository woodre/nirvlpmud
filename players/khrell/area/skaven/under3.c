#include "/players/khrell/define.h"
#include "/players/khrell/ansi.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIK+"The Underways"+NORM+" ("+HIW+"Tunnel"+NORM+")");
   set_long(
"   Claustrophobic conditions of this tunnel leaves nothing to \n"+
"the imagination, and is nothing more then a poorly made passage\n"+
"cut through the solid rock.  The tunnel, made by some unknown\n"+
"means, goes to the north and south.\n");
   set_light(-1);
   add_property("fight_area");
   add_property("no_teleport");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "tunnel", "It's long it's dark and it goes to the north and south",
         "passage", "It's long and dark and yes... it goes north and south."});
   dest_dir = ({
         "players/khrell/area/skaven/under2.c", "north",
         "players/khrell/area/skaven/under4.c", "south"});
   return 1; }
