#include "/players/guilds/Rangers/RangerDefs.h"

inherit "room/room";
inherit "/players/guilds/Rangers/Room/RangerRoom.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc=
   "Angel Grove Park.\n"+
   "There are trees, flowers, and sunshine filling your visual senses.\n"+
"This is the side of the hill that is in the center of the park.\n"+
   "There is a concrete walkway leading southeast to the top of the hill.\n"+
   "There are playing fields to the west.\n"+
   "",
   items=
   ({
    "trees","A few small hardwood trees",
    "flowers","Small patches of flowers planted by volunteers",
    });
   dest_dir=
   ({
   "players/beck/room/park11","north",
   "players/beck/room/park15","northeast",
   "players/beck/room/park16","east",
   "players/beck/room/park17","southeast",
   "players/beck/room/park13","south",
   "players/beck/room/park8","southwest",
   "players/beck/room/park7","west",
   "players/beck/room/park6","northwest",
   });
}

short(){
   return "Angel Grove Park";
}
