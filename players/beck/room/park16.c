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
   "It is mostly covered with loose soil.\n"+
   "",
   items=
   ({
         "trees","A few small hardwood trees",
         "flowers","Small patches of flowers planted by volunteers",
    });
   dest_dir=
   ({
         "players/beck/room/park15","north",
         "players/beck/room/park19","northeast",
         "players/beck/room/park20","east",
         "players/beck/room/park21","southeast",
         "players/beck/room/park17","south",
         "players/beck/room/park13","southwest",
         "players/beck/room/park12","west",
         "players/beck/room/park11","northwest",
    });
   if(!find_living("ranger_kimberly")){
      move_object("/players/guilds/Rangers/Npc/Kimberly.c",this_object());
   }
}

short(){
   return "Angel Grove Park";
}

