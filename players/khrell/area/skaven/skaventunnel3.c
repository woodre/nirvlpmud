#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" (Tunnel)");
   set_long(
"   The tunnel continues to slope upward at an even greater angle,\n"+
"and the stench is nearly overwhelming.  Small, roughly chisled niches\n"+
"provide an easy way to climb farther into the darkness, or descend\n"+
"into the vast expanse of the underways.\n");   
   set_light(-1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell the horrible stench of fecal matter.\n");
   items = ({
         "niches", "The roughly-cut niches provide handholds and footholds",
         "niche", "Roughly cut, it provides hand or footholds",
         "darkness", "It exists from the lack if visible light"});
   dest_dir = ({
         "players/khrell/area/skaven/skaventunnel2.c", "descend",
         "players/khrell/area/skaven/skaventunnel4.c", "climb"});
   move_object(clone_object("/players/khrell/monster/skaven/warprat.c"), this_object());
   return 1; }
