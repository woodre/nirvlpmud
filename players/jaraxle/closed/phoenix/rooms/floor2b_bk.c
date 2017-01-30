#include "/players/jaraxle/define.h"
#include "/players/jaraxle/closed/phoenix/mons/random.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   get_random_mob();
   short_desc = "Tower of the "+RED+"["+HIR+"Pho"+BLK+"e"+HIR+"nix"+NORM+RED+"]"+NORM;
   long_desc =
   "  A large forgotten tower in ruins.  Stones from\n"+
   "around the walls have crumbled to the floor.  A\n"+
   "round hallway leads around the stairwell to the\n"+
   "back side of the tower.\n";
   add_item("tower","Made of solid stone, the tower rises high above the land");
   add_exit("/players/jaraxle/closed/phoenix/rooms/floor2c.c","around");
   add_exit("/players/jaraxle/closed/phoenix/rooms/floor2a.c","back");
}

cmd_search(str)
{
   if(str == "walls")
      {
      write("You search the walls and find a crack you can squeeze through.\n");
   }
   else ::cmd_search(str);
   return 1;
}

init(){
   ::init();
   add_action("enter_door","squeeze");
}

enter_door(str){
   if(!str) return (notify_fail("You may 'squeeze crack'.\n"), 0);
   if(str == "crack" || str == "through crack"){
      write("You manage to squeeze through the crack.\n");
      this_player()->move_player("through the crack#/players/jaraxle/closed/phoenix/rooms/crack1");
      return 1; }
   notify_fail("Squeeze through what?\n"); return 0; }
