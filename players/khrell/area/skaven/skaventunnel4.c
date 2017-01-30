#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" (Tunnel)");
   set_long(
"   The vertical tunnel widens slightly here.  The rock here curves\n"+
"outward and spirals in a circular pattern.  Faint traces of some  \n"+
"type of scratches line the walls.\n");      
   set_light(-1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell urine and fecal matter.\n");
   items = ({
         "rock", "Solid stone apparently has been worked by unknown means",
         "tunnel", "It goes up and it goes down",
         "pattern", "Smooth and hypnotic, you feel strange when you look at them",
         "scratches", "The scratches were apparently carved by the claws of some unknown creatures"});
   dest_dir = ({
         "players/khrell/area/skaven/skaventunnel3.c", "descend",
         "players/khrell/area/skaven/skaventunnel5.c", "climb"});
   move_object(clone_object("/players/khrell/monster/skaven/warprat.c"), this_object());
   return 1; }
