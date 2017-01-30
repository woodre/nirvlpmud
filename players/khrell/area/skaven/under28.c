#include "/players/khrell/define.h"
#include "/players/khrell/ansi.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIK+"The Underways"+NORM+" ("+HIW+"Tunnel"+NORM+")");
   set_long(
"   The tunnel widens quite a bit here, and one can almost stand up\n"+
"straight.  The scents here are nearly overwhelming.  The long miles\n"+
"of cramped tunnel finally begin to widen to the north, where the tunnel\n"+
"ends abruptly at a dark opening.\n");
   set_light(-1);
   add_property("fight_area");
   add_property("no_teleport");
   add_property("no_follow");
   items = ({
	   "opening", "Perhaps you can 'enter' this dark hole"});
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell foul excremental secretions and industrial waste.\n");
   dest_dir = ({
         "players/khrell/area/skaven/under27.c", "north",
         "players/khrell/area/skaven/skaventunnel1.c", "enter"});
   return 1; }
