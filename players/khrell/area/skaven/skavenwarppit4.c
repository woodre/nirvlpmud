#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+"("+HIG+"Mines"+NORM+")");
   set_long(
"   The ooze collects here, forming a gigantic pool.  There is hardly\n"+
"any place to stand without being near the sludge.  The only way out\n"+
"is back 'up' the way you came.\n");   
   set_light(-2);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell the toxic fumes of the ooze.\n");
   items = ({
         "ooze", "The toxic waste product of warpstone refinement",
         "pool", "A place where the ooze has collected",
         "sludge", "The toxic waste product of warpstone refinement"});
   dest_dir = ({
         "players/khrell/area/skaven/skavenwarppit3.c", "up"});
   move_object(clone_object("/players/khrell/monster/skaven/sludgespawn.c"), this_object());
   move_object(clone_object("/players/khrell/monster/skaven/sludgespawn.c"), this_object());
   move_object(clone_object("/players/khrell/monster/skaven/sludgespawn.c"), this_object());
   move_object(clone_object("/players/khrell/monster/skaven/sludgespawn.c"), this_object());
   return 1; }
