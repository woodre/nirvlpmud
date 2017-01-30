#include "/players/guilds/Rangers/RangerDefs.h"

inherit "room/room";
inherit "/players/guilds/Rangers/Room/RangerRoom.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc=
   "Angel Grove Park.\n"+
   "There are trees, flowers, and sunshine filling your visual senses.\n"+
   "A concrete walkway leads north and west.\n"+
   "There is a steep cliff wall to the northwest.\n"+
   "",
   items=
   ({
    "trees","A few small hardwood trees",
    "flowers","Small patches of flowers planted by volunteers",
    "walkway","A walkway made of concrete",
    "beach","A sand covered beach along the edge of Angel Grove Lake",
    "cliff","A steep cliff that is impossible to climb up",
    });
   dest_dir=
   ({
   "players/beck/room/park21","north",
   "players/beck/room/park25","northeast",
   "players/beck/room/park18","west",
   });
}

short(){
   return "Angel Grove Park";
}
