#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" ["+HIR+"Council"+NORM+"]");
   set_long(
"   This is the center of the upper tier of the 'Council' district\n"+
"of 'Fester Peak'.  To the east and west are the two top seats of\n"+
"the ruling council.  This area is also well guarded and defended\n"+
"from invasion.\n");
   set_light(1);
   add_property("fight_area");
   add_property("no_teleport");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "item", "NO/N"});
   dest_dir = ({
         "players/khrell/area/skaven/ss13.c", "south",
         "players/khrell/area/skaven/ss19.c", "north"});
   move_object(clone_object("/players/khrell/monster/skaven/clanrat.c"), this_object());
   move_object(clone_object("/players/khrell/monster/skaven/clanrat.c"), this_object());
   move_object(clone_object("/players/khrell/monster/skaven/clanrat.c"), this_object());
   move_object(clone_object("/players/khrell/monster/skaven/clanrat.c"), this_object());
   return 1; }
