#include "/players/guilds/Rangers/RangerDefs.h"

inherit "room/room";
inherit "/players/guilds/Rangers/Room/RangerRoom.c";

string name;
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc=
   "Angel Grove Park.\n"+
   "There are trees, flowers, and sunshine filling your visual senses.\n"+
   "There are some playing fields here, where people can come to play\n"+
   "some recreational games like soccer or softball.\n"+
   "",
   items=
   ({
    "trees","A few small hardwood trees",
    "flowers","Small patches of flowers planted by volunteers",
    "fields","Fields of short well kept grass excellent for playing sports",
    });
   dest_dir=
   ({
   "players/beck/room/park6","north",
   "players/beck/room/park11","northeast",
   "players/beck/room/park12","east",
   "players/beck/room/park13","southeast",
   "players/beck/room/park8","south",
   "players/beck/room/park3","southwest",
   "players/beck/room/park2","west",
   "players/beck/room/park1","northwest",
   });
}

short(){
   return "Angel Grove Park";
}

