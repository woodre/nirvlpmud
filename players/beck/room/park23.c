#include "/players/guilds/Rangers/RangerDefs.h"

inherit "room/room";
inherit "/players/guilds/Rangers/Room/RangerRoom.c";

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
         "players/beck/room/park24","south",
         "players/beck/room/park20","southwest",
         "players/beck/room/park19","west",
    });
   if(!find_living("goldar"), this_object()){
      move_object("/players/beck/DarkRangers/Npc/Goldar.c",this_object());
   }
}

short(){
   return "Angel Grove Park";
}
