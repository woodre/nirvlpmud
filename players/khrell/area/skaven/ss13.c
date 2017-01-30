#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" ["+HIR+"Council"+NORM+"]");
   set_long(
"   The massive gates lay open all around leading into the heart\n"+
" of the 'Council' district.  Here are the holdings for the greater\n"+
"clans of the skaven in 'Fester Blight'.\n");
   set_light(1);
   add_property("fight_area");
   add_property("no_teleport");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "gates", "Three sets: One north, one west and one east"});
   dest_dir = ({
         "players/khrell/area/skaven/ss12.c", "south",
         "players/khrell/area/skaven/ss16.c", "west",
         "players/khrell/area/skaven/ss18.c", "north",
         "players/khrell/area/skaven/ss14.c", "east"});
   move_object(clone_object("/players/khrell/monster/skaven/clanrat.c"), this_object());
   move_object(clone_object("/players/khrell/monster/skaven/clanrat.c"), this_object());
   return 1; }
