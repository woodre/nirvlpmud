#include "/players/guilds/Rangers/RangerDefs.h"

inherit "room/room";
inherit "/players/guilds/Rangers/Room/RangerRoom.c";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc=
   "Angel Grove Park.\n"+
   "There are trees, flowers, and sunshine filling your visual senses.\n"+
   "A small playground is located here.  There is a slide, a pole, and\n"+
   "a jungle gym all located in the center of a large sand area, with\n"+
   "railroad ties separating it from the grass.\n"+
   "There are playing fields to the northeast.\n"+
   "",
   items=
   ({
    "trees","A few small hardwood trees",
    "flowers","Small patches of flowers planted by volunteers",
    });
   dest_dir=
   ({
   "players/beck/room/park2","north",
   "players/beck/room/park7","northeast",
   "players/beck/room/park8","east",
   "players/beck/room/park9","southeast",
   "players/beck/room/park4","south",
   });
}

short(){
   return "Angel Grove Park";
}

