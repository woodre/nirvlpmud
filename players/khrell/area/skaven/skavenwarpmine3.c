#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+"("+HIG+"Mines"+NORM+")");
   set_long(
"   This is where the raw, unrefined warpstone is brought from the \n"+
"mine to be refined.  Brass machinery sits in places along a long \n"+
"conveyer belt.  The occasional hiss of released steam and the near\n"+
"constant puffing of the large bellows nearly drown out the roaring\n"+
"fires of the refinement furnace.                                  \n");   
   set_light(1);
   add_listen("main", "You hear the near deafening furnace fires.\n");
   add_smell("main", "A stong, and near over-powering burnt odor.\n");
   items = ({
         "machinery", "Crafted from brass alloys for the express purpose of warpstone refinement",
         "conveyer", "It allows a great volume of warpstone to be moved down through the refinement process",
         "belt", "It is made from stretched and dried skin from many races",
         "bellows", "These pump in a steady rythm, stoking the furnaces",
         "furnace", "Large and bulbous with many pipes"});
   dest_dir = ({
         "players/khrell/area/skaven/skavenwarpmine1.c", "north"});
   move_object(clone_object("/players/khrell/monster/skaven/skavenslave.c"), this_object());
   move_object(clone_object("/players/khrell/monster/skaven/skavenslave.c"), this_object());
   return 1; }
