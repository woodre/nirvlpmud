#include "/players/guilds/Rangers/RangerDefs.h"

inherit "room/room";
inherit "/players/guilds/Rangers/Room/RangerRoom.c";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc=
   "Angel Grove Park.\n"+
   "There are trees, flowers, and sunshine filling your visual senses.\n"+
   "There is a small bridge that crosses a drainage gulley.\n"+
   "There are playing fields to the north.\n"+
   "",
   items=
   ({
    "trees","A few small hardwood trees",
    "flowers","Small patches of flowers planted by volunteers",
    "bridge","A 15 foot long bridge made of wood",
    });
   dest_dir=
   ({
   "players/beck/room/park7","north",
   "players/beck/room/park12","northeast",
   "players/beck/room/park13","east",
   "players/beck/room/park14","southeast",
   "players/beck/room/park9","south",
   "players/beck/room/park4","southwest",
   "players/beck/room/park3","west",
   "players/beck/room/park2","northwest",
   });
}

short(){
   return "Angel Grove Park";
}

