#include "/players/guilds/Rangers/RangerDefs.h"

inherit "room/room";
inherit "/players/guilds/Rangers/Room/RangerRoom.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc=
   "Angel Grove Park.\n"+
   "There are trees, flowers, and sunshine filling your visual senses.\n"+
   "A concrete walkway leads east/west, and southeast up the hill.\n"+
   "There is a path leading north into a small wooded area of the park.\n"+
   "There are some playing fields to the south.\n"+
   "",
   items=
   ({
    "trees","A few small hardwood trees",
    "flowers","Small patches of flowers planted by volunteers",
    "walkway","A walkway made of concrete",
    "path","A small nature trail into the woods",
    });
   dest_dir=
   ({
   "players/beck/room/park5","north",
   "players/beck/room/park11","east",
   "players/beck/room/park12","southeast",
   "players/beck/room/park7","south",
   "players/beck/room/park2","southwest",
   "players/beck/room/park1","west",
   });
}

short(){
   return "Angel Grove Park";
}

