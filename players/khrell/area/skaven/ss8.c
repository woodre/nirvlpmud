#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" ["+HIK+"Eshin"+NORM+"]");
   set_long(
"   This is clearly the Eshin Clan area.  The oppresive shadows are\n"+
"held at bay by some unknown means.  The clutter, normally seen in\n"+
"the slums, is not present here, leaving this area with a somewhat\n"+
"clean appearence.\n");
   set_light(-1);
   add_property("fight_area");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "shadows", "They look to be held back, like the eye of the storm"});
   dest_dir = ({
         "players/khrell/area/skaven/ss7.c", "south",
         "players/khrell/area/skaven/skaveneshindojo.c", "east",
         "players/khrell/area/skaven/ss9.c", "north"});
   move_object(clone_object("/players/khrell/monster/skaven/nightrun1.c"), this_object());
   return 1; }
