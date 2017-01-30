/* Ranger Code is in /players/guilds/Rangers now - 2005.10.15 */
#include "/players/guilds/Rangers/RangerDefs.h"

inherit "room/room";
inherit "/players/guilds/Rangers/Room/RangerRoom.c";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc=
   "Angel Grove Park.\n"+
   "There are trees, flowers, and sunshine filling your visual senses.\n"+
   "There are playing fields to the east.\n"+
   "",
   items=
   ({
         "trees","A few small hardwood trees",
         "flowers","Small patches of flowers planted by volunteers",
    });
   dest_dir=
   ({
         "players/beck/room/park1","north",
         "players/beck/room/park6","northeast",
         "players/beck/room/park7","east",
         "players/beck/room/park8","southeast",
         "players/beck/room/park3","south",
         "players/beck/room/street4","west",
    });
}

short(){
   return "Angel Grove Park";
}

