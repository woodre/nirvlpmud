#include "/players/khrell/define.h"
#include "/players/khrell/ansi.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIK+"The Underways"+NORM+" ("+HIW+"Tunnel"+NORM+")");
   set_long(
"   The tunnel here leaves nothing to the imagination and looks to\n"+
"be a poorly made passage through solid rock.  Warpstone shards have\n"+
"been placed into select places along the tunnel here.  A absence of\n"+
"magical energy pervades here robbing you of any energy to escape from\n"+ 
"the confines of this place.\n");
   set_light(-1);
   add_property("fight_area");
   add_property("no_teleport");
   add_property("no_magic");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "tunnel", "It goes north and south",
         "passage", "It goes north and south, you think",
         "warpstone", "Chunks of raw chaos energy used to give light"});
   dest_dir = ({
         "players/khrell/area/skaven/under13.c", "north",
         "players/khrell/area/skaven/under15.c", "south"});
   return 1; }
