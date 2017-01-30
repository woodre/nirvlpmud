#include "../define.h"
inherit ROOM;

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("Hall of the Warriors");
   set_long(
   "  You find yourself in the lower levels of the Tower of\n"+
   "Warriors.  The walls here glow with an inner light, allowing\n"+
   "you to see where normally sunlight will not touch. There are\n"+
   "doors to the south and north, the south leading to the sparring\n"+
   "arena, and the north leading to the Master Craftsman's shop. A\n"+
   "stairway leads back up to the main hall.\n");
   add_property("NT");
   add_item(({"walls","floor",}),
   "A smooth stone that has been enchanted to glow");
   add_item("door",
   "Made of a heavy oak, it seems almost unbreakable by normal means");
   add_item("doors",
   "A pair of wooden doors, one leading to the arena, the other to the\n"+
   "Craftsman's shop");
   add_item("shop",
   "The Master Craftsman's shop.  There you can purchase items that\n"+
   "might assist you in your travels"); 
   add_item("arena",
   "The sparring arena of the Warrior's tower. Simply enter it and begin\n"+
   "fighting");
   add_exit(ROOMS+"sc2","up");
   add_exit(ROOMS+"sc7","south");
   add_exit(ROOMS+"sc8","north");
   }
init(){
 ::init();
 add_action("nogo","south", 1);
 }

nogo(){ write("The arena is not yet open.\n"); return 1; }


okay_follow() { return 1; }
query_no_fight() { return 1; }