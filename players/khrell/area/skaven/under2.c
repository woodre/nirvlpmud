#include "/players/khrell/define.h"
#include "/players/khrell/ansi.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIK+"The Underways"+NORM+" ("+HIW+"Tunnel"+NORM+")");
   set_long(
"   This cramped tunnel leaves nothing to the imagination, and is\n"+
"nothing more then a poorly made passage cut through the solid rock.\n"+
"The tunnel, made by some unknown means, it goes to the north and\n"+
"south.\n");
   set_light(-1);
   add_property("fight_area");
   add_property("no_magic");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "tunnel", "Long and dark it goes to the north and south",
         "passage", "It is long and goes to the north and south"});
   dest_dir = ({
         "players/khrell/area/skaven/under1.c", "north",
         "players/khrell/area/skaven/under3.c", "south"});
   return 1; }
