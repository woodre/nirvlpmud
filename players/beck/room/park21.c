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
   "There is a steep cliff wall to the west.\n"+
   "The beach along the lake is to the east.\n"+
   "",
   items=
   ({
    "trees","A few small hardwood trees",
    "flowers","Small patches of flowers planted by volunteers",
    "walkway","A walkway made of concrete",
    "beach","A sand covered beach along the edge of Angel Grove Lake",
    "cliff","A steep cliff that is impossible to climb up",
    });
   dest_dir=
   ({
   "players/beck/room/park20","north",
   "players/beck/room/park24","northeast",
   "players/beck/room/park25","east",
   "players/beck/room/park22","south",
   "players/beck/room/park18","southwest",
   "players/beck/room/park16","northwest",
   });
}

short(){
   return "Angel Grove Park";
}

