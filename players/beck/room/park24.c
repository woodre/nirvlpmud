#include "/players/guilds/Rangers/RangerDefs.h"

inherit "/players/guilds/Rangers/Room/RangerRoom.c";
inherit "room/room";
inherit "/players/beck/Lib/Resource.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc=
   "Angel Grove Park.\n"+
"You are right on the beach along Angel Grove Lake.\n"+
   "",
   items=
   ({
    "trees","A few small hardwood trees",
    "flowers","Small patches of flowers planted by volunteers",
    });
   dest_dir=
   ({
"players/beck/room/park23","north",
   "players/beck/room/park25","south",
   "players/beck/room/park21","southwest",
   "players/beck/room/park20","west",
"players/beck/room/park19","northwest",
   });
AResource(({"sand",30,"water",100,"sunlight",5000}));
}

short(){
   return "Angel Grove Park";
}

