#include "/players/khrell/define.h"
#include "/players/khrell/ansi.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIK+"The Underways"+NORM+" ("+HIW+"Tunnel"+NORM+")");
   set_long(
"   The cramped tunnel opens up here allowing you to stand and move\n"+
"about with some ammount of comfort.  Still crude and poorly made it\n"+
"is not totally stable and should be traversed with care.\n");
   set_light(-1);
   add_property("fight_area");
   add_property("no_teleport");
   add_property("no_follow");
   add_property("no_magic");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "tunnel", "It goes north and south"});
   dest_dir = ({
         "players/khrell/area/skaven/under16.c", "north",
         "players/khrell/area/skaven/under18.c", "south"});
   return 1; }
