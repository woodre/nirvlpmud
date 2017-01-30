#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" ["+HIY+"Commons"+NORM+"]");
   set_long(
"   The commons begins to open up wide here and give way to the well-\n"+
"kept 'Council' district to the north.\n");
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   dest_dir = ({
         "players/khrell/area/skaven/ss6.c", "south",
         "players/khrell/area/skaven/ss13.c", "north"});
   return 1; }
