#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" (Tunnel)");
   set_long(
"   The tunnel continues to spiral upward, its slope is almost\n"+
"completely vertical.  The handholds and footholds appear in \n"+
"greater numbers indicating some important use in the past.\n");   
   set_light(-1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "tunnel", "It goes up and it goes down",
         "handholds", "Used to help one climb or descend",
         "footholds", "Used to assist one climbing or descending"});
   dest_dir = ({
         "players/khrell/area/skaven/skaventunnel1.c", "descend",
         "players/khrell/area/skaven/skaventunnel3.c", "climb"});
   move_object(clone_object("/players/khrell/monster/skaven/warprat.c"), this_object());
   move_object(clone_object("/players/khrell/monster/skaven/warprat.c"), this_object());
   return 1; }
