#include "/players/guilds/Rangers/RangerDefs.h"

inherit "room/room";
inherit "/players/guilds/Rangers/Room/RangerRoom.c";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc=
   "Angel Grove Park.\n"+
   "There are trees, flowers, and sunshine filling your visual senses.\n"+
   "",
   items=
   ({
    "trees","A few small hardwood trees",
    "flowers","Small patches of flowers planted by volunteers",
    });
   dest_dir=
   ({
   "players/beck/room/park3","north",
   "players/beck/room/park8","northeast",
   "players/beck/room/park9","east",
   });
if(!find_living("ranger_jason")){
move_object("/players/guilds/Rangers/Npc/Jason.c", this_object());
}
}

short(){
   return "Angel Grove Park";
}

