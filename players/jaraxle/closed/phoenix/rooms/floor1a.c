/*  10/08/06 - Rumplemintz
      Moved inherit above #include statements
      Removed trailing ; from #include
*/

inherit "/players/jaraxle/room.c";
#include "/players/jaraxle/define.h"
#include "/players/jaraxle/closed/phoenix/mons/random.h"

reset(arg) {
   if(arg) return;
   set_light(1);
   get_random_mob();
   short_desc = "Tower of the "+RED+"["+HIR+"Pho"+BLK+"e"+HIR+"nix"+NORM+RED+"]"+NORM;
   long_desc =
   "  A large forgotten tower in ruins.  Stones from\n"+
   "around the walls have crumbled to the floor.  A\n"+
   "small stairwell in the center of the room leads\n"+
   "further up the tower.\n";
   add_item("tower","Made of solid stone, the tower rises high above the land");
   add_item("stairwell","A large stone stairway leading up through the tower");
   add_item("stones","Large stones laying on the ground");
   add_item("floor","The stone floor is littered with large broken stones");
   
   add_exit("/players/jaraxle/closed/phoenix/rooms/floor2a.c","up");
   add_exit("/players/jaraxle/closed/phoenix/rooms/floor1b.c","around");
   add_exit("/players/jaraxle/closed/phoenix/rooms/floor1d.c","back");
   
}

init(){
   ::init();
   add_action("out","out");
}

out(){
   object where;
   where = find_living("tower of the phoenix");
   write("You exit the Tower at its current location.\n");
   move_object(TP,environment(where));
   command("look",TP);
   
   return 1; }
