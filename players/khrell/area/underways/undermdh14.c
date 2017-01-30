#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(YEL+"Ruins of Khazad Naggrund"+NORM);
   set_long("\
This was at one time a hidden or secret workshop.  The invasion has taken\n\
it's toll on it as well.  A great stone bench lays against one wall, a big\n\
split has sundered it into two large pieces.  Everything else of any value\n\
has been stripped and looted.\n");   
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "bench", "At one time this would have been for the workman, now it's a ruin",
         "piece", "A large heavy piece of what was once a large bench",
         "workshop", "Once used to craft things of value",
         "shop", "Once used to craft things of value",
         "stone", "Once used for workers  as a bench",
         "wall", "Against this lays a shattered stone bench",
         "pieces", "Large and heavy pieces of what was once a large bench"});
   dest_dir = ({
         "players/khrell/area/underways/undermdh12.c", "north"});
   move_object(clone_object("/players/khrell/monster/underways/golrnd.c"), this_object());
   move_object(clone_object("/players/khrell/monster/underways/golrnd.c"), this_object());
   move_object(clone_object("/players/khrell/monster/underways/golrnd.c"), this_object());
   move_object(clone_object("/players/khrell/monster/underways/golrnd.c"), this_object());
   return 1; }
