#include "/players/guilds/Rangers/RangerDefs.h"

inherit "room/room";
inherit "/players/guilds/Rangers/Room/RangerRoom.c";
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
         "players/beck/room/park24","north",
         "players/beck/room/park22","southwest",
         "players/beck/room/park21","west",
         "players/beck/room/park20","northwest",
    });
   if(!find_living("ranger_trini")){
      move_object("/players/guilds/Rangers/Npc/Trini.c", this_object());
   }
AResource(({"sand",100,"water",500,"sunlight",5000,"metal|iron",5}));
}

short(){
   return "Angel Grove Park";
}
