#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" ["+YEL+"Pestilens"+NORM+"]");
   set_long(
"   This area is ripe with all manner of disgusting, gut churning\n"+
"filth.  It is as if everything loathsome and sickening has been\n"+
"gathered here.  The walls drip with ichor, mucus and pus.  The\n"+
"floors undulate with a carpet of writhing maggots.  Patches of\n"+
"diseased flesh hang from the ceiling like grotesque tapestries\n");
   set_light(-1);
   add_property("fight_area");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell rot and decay.\n");
   items = ({
         "walls", "They drip with ichor, mucus, and pus",
         "ceiling", "It is high above covered in filth",
         "ichor", "A loathsome liquid of unnatural creatures",
         "mucus", "It drops and oozes down upon you",
         "pus", "It burbles and spurts forcing you to look away",
         "floors", "It's totally covered in maggots, both large and small",
         "maggots", "An endless amount of these larvae flies",
         "flesh", "Some poor unfortunate had his bone removed and then hung here"});
   dest_dir = ({
         "players/khrell/area/skaven/ss17.c", "exit",
         "players/khrell/area/skaven/skavenpestilenhall.c", "enter"});
   move_object(clone_object("/players/khrell/monster/skaven/plaguemonk2.c"), this_object());
   return 1; }
