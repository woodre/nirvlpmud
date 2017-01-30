#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" (Tunnel)");
   set_long(
"   This cramped passage is more of a crawlspace than an actual\n"+
"tunnel.  Sloping upward into the dark, the air is smells of a\n"+
"musky smell, along with other bodily excretions.  The floor is\n"+ 
"sticky and seems to 'squelch' with every step.\n");   
   set_light(-1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell urine, fecal matter and a thick musky odor.\n");
   items = ({
"passage",
 "The passage obviously began as a natural formation, but has clearly been worked by some unnamed creature to make it passable",
"floor",
 "It is completely coated in old fecal matter",
"passage",
 "The passage obviously began as a natural formation, but has clearly been worked by some unnamed creature to make it passable"});
   dest_dir = ({
         "players/khrell/area/skaven/under28.c", "exit",
         "players/khrell/area/skaven/skaventunnel2.c", "up"});
   move_object(clone_object("/players/khrell/monster/skaven/warprat.c"), this_object());
   return 1; }
