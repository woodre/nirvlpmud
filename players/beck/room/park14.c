#include "/players/guilds/Rangers/RangerDefs.h"

inherit "room/room";
inherit "/players/guilds/Rangers/Room/RangerRoom.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc=
   "Angel Grove Park.\n"+
   "There are trees, flowers, and sunshine filling your visual senses.\n"+
   "A concrete walkway leads east/west and north up the hill.\n"+
   "",
   items=
   ({
    "trees","A few small hardwood trees",
    "flowers","Small patches of flowers planted by volunteers",
    "walkway","A walkway made of concrete",
    "cliff","A steep cliff that is impossible to climb up",
    });
   dest_dir=
   ({
   "players/beck/room/park13","north",
   "players/beck/room/park18","east",
   "players/beck/room/park9","west",
   "players/beck/room/park8","northwest",
   });
}

short(){
   return "Angel Grove Park";
}
