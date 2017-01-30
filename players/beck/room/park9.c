#include "/players/guilds/Rangers/RangerDefs.h"

inherit "room/room";
inherit "/players/guilds/Rangers/Room/RangerRoom.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc=
   "Angel Grove Park.\n"+
   "There are trees, flowers, and sunshine filling your visual senses.\n"+
   "A concrete walkway leads east/west.\n"+
   "",
   items=
   ({
    "trees","A few small hardwood trees",
    "flowers","Small patches of flowers planted by volunteers",
    "walkway","A walkway made of concrete",
    });
   dest_dir=
   ({
   "players/beck/room/park8","north",
   "players/beck/room/park13","northeast",
   "players/beck/room/park14","east",
   "players/beck/room/park4","west",
   "players/beck/room/park3","northwest",
   });
}

short(){
   return "Angel Grove Park";
}

