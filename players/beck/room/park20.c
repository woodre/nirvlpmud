#include "/players/guilds/Rangers/RangerDefs.h"

inherit "room/room";
inherit "/players/guilds/Rangers/Room/RangerRoom.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc=
   "Angel Grove Park.\n"+
   "There are trees, flowers, and sunshine filling your visual senses.\n"+
   "A concrete walkway leads north/south.\n"+
   "There is a soil covered hill to the west.\n"+
   "The beach along the lake is to the east.\n"+
   "",
   items=
   ({
         "trees","A few small hardwood trees",
         "flowers","Small patches of flowers planted by volunteers",
         "walkway","A walkway made of concrete",
         "beach","A sand covered beach along the edge of Angel Grove Lake",
    });
   dest_dir=
   ({
         "players/beck/room/park19","north",
         "players/beck/room/park23","northeast",
         "players/beck/room/park24","east",
         "players/beck/room/park25","southeast",
         "players/beck/room/park21","south",
         "players/beck/room/park16","west",
         "players/beck/room/park15","northwest",
    });
   if(!find_living("ranger_zack")){
      move_object("/players/guilds/Rangers/Npc/Zack.c",this_object());
   }
}

short(){
   return "Angel Grove Park";
}

