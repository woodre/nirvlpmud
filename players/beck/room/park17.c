#include "/players/guilds/Rangers/RangerDefs.h"

inherit "room/room";
inherit "/players/guilds/Rangers/Room/RangerRoom.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc=
   "Angel Grove Park.\n"+
   "There are trees, flowers, and sunshine filling your visual senses.\n"+
"This is the top of the hill that is in the center of the park.\n"+
   "From here you have a good view of the rest of the park as well\n"+
   "as Angel Grove Lake.  There are also a few picnic tables under a\n" +
   "wooden canopy here.\n"+
   "Steep cliffs are on the east to the south side of the hill.\n"+
   "",
   items=
   ({
    "trees","A few small hardwood trees",
    "flowers","Small patches of flowers planted by volunteers",
    });
   dest_dir=
   ({
   "players/beck/room/park16","north",
   "players/beck/room/park13","west",
   "players/beck/room/park12","northwest",
   });
}

short(){
   return "Angel Grove Park";
}

