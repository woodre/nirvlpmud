#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" [Slums]");
   set_long(
"   These slums are cluttered with refuse and junk of the skaven.\n"+
"The enclosed space is very claustrophobic, and gives one a sense\n"+
"of hopelessness.  To the east, and west the slums continue.\n");
   set_light(-1);
   add_property("fight_area");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "refuse", "Various assorted trash",
         "junk", "A lot of trash"});
   dest_dir = ({
         "players/khrell/area/skaven/ss1.c", "east",
         "players/khrell/area/skaven/ss5.c", "west"});
   move_object(clone_object("/players/khrell/monster/skaven/clanrat.c"), this_object());
   return 1; }
