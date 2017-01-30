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
   "There is a soil covered hill to the south.\n"+
   "",
   items=
   ({
         "trees","A few small hardwood trees",
         "flowers","Small patches of flowers planted by volunteers",
         "walkway","A walkway made of concrete",
    });
   dest_dir=
   ({
         "players/beck/room/park19","east",
         "players/beck/room/park20","southeast",
         "players/beck/room/park16","south",
         "players/beck/room/park12","southwest",
         "players/beck/room/park11","west",
    });
   if(!find_living("ranger_billy")){
      move_object("/players/guilds/Rangers/Npc/Billy.c",this_object());
   }
}

short(){
   return "Angel Grove Park";
}

