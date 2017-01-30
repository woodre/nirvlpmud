#include "../define.h"

inherit ROOM;

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("Hall of the Warriors");
   set_long(
   "You stand in the entry way of the steel tower of the\n"+
   "Warriors. The floor is a polished grey stone with white\n"+
   "marble along the walls. A door leads north, deeper into\n"+
   "the tower. Double doors lead out to the Continent of\n"+
   "Hirandea.\n");
   add_property("NT");
   add_item(({"walls","floor","marble"}),
   "A dull polished stone that is well crafted and cared for by the students");
   add_item(({"door","doors"}),
   "Made of a heavy oak, it seems almost unbreakable by normal means");
   
   add_exit(ROOMS+"sc2","north");
  add_exit("/players/maledicta/cont/rooms/218","out");
   }

okay_follow() { return 1; }
query_no_fight() { return 1; }
