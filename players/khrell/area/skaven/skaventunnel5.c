#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" (Tunnel)");
   set_long(
"   The tunnel widens the farther up one goes, as if it is some\n"+
"sort of gigantic funnel.  The stone here is smooth and there are\n"+
"fewer handholds. The air also seems to be a lot more clear here\n"+
"and half-way breathable.  Above your head looks to be some sort\n"+
"of opening.\n");   
   set_light(-1);
   add_listen("main", "You hear faint chittering sounds from above.\n");
   add_smell("main", "You smell 'human' waste, but it is not as strong here.\n");
   items = ({
         "tunnel", "It has widened here making it easier to traverse",
         "opening", "It looks large enough to enter",
         "stone", "This rock is smooth and almost slippery",
         "handhold", "For ease of climbing and descending in this tunnel",
         "handholds", "For ease of climbing and descending in this tunnel"});
   dest_dir = ({
         "players/khrell/area/skaven/skaventunnel4.c", "descend",
         "players/khrell/area/skaven/skavenwarpmine1.c", "enter"});
   move_object(clone_object("/players/khrell/monster/skaven/warprat.c"), this_object());
   return 1; }
