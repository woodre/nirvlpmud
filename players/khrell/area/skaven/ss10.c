#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" [Slums]");
   set_long(
"   The pathway ends here at the city dump.  At one time there was\n"+
"a large pit to throw things into, but now it sits here filled to\n"+
"overflowing.  Back west is the only way out.\n");
   set_light(-1);
   add_property("fight_area");
   add_property("no_magic");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "pit", "The pit is now endlessly filled with trash"});
   dest_dir = ({
         "players/khrell/area/skaven/ss4.c", "west"});
   return 1; }
