#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+"("+HIG+"Mines"+NORM+")");
   set_long(
"   There is nothing of interest in this section of this mine. It's\n"+
"been worked clean, and now is only a depository for crude barrels\n"+
"of noxious sludge.\n");
   set_light(-1);
   add_property("no_magic");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "barrels", "Wood and covered with a sap to keep from leaking"});
   dest_dir = ({
         "players/khrell/area/skaven/skavenwarppit1.c", "descend"});
   move_object(clone_object("/players/khrell/monster/skaven/sludgespawn.c"), this_object());
   return 1; }
