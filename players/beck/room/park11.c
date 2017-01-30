#include "/players/guilds/Rangers/RangerDefs.h"

inherit "room/room";
inherit "/players/guilds/Rangers/Room/RangerRoom.c";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc=
   "Angel Grove Park.\n"+
   "There are trees, flowers, and sunshine filling your visual senses.\n"+
   "A concrete walkway leads east/west, south up the hill.\n"+
   "There is a wooded area to the north, but the bushes along the edge are\n"+
   "too thick to walk there.\n"+
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
         "players/beck/room/park15","east",
         "players/beck/room/park16","southeast",
         "players/beck/room/park12","south",
         "players/beck/room/park7","southwest",
         "players/beck/room/park6","west",
    });
}

short(){
   return "Angel Grove Park";
}

