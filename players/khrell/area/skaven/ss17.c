#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" ["+YEL+"Pestilens"+NORM+"]");
   set_long(
"   The revolting Pestilens area only gets worse the deeper one goes\n"+
"into it.  Openly diseased corpses bloat the streets.  The maggots\n"+
"bursting from the swollen dead, spill outward while the thick clouds\n"+
"of endless flies choke and blot out light and sound.\n");
   set_light(-1);
   add_listen("main", "You hear loud buzzing of many flies.\n");
   add_smell("main", "You smell decay and rot.\n");
   items = ({
         "corpses", "They died to horrible diseases",
         "maggots", "The larvae of the flies",
         "flies", "They buzz in your eyes, ears, nose and mouth"});
   dest_dir = ({
         "players/khrell/area/skaven/ss16.c", "east",
         "players/khrell/area/skaven/skavenpestilenhall.c", "enter"});
   move_object(clone_object("/players/khrell/monster/skaven/plaguemonk1.c"), this_object());
   return 1; }
