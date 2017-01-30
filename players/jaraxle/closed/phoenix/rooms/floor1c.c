/* 10/08/06 - Rumplemintz
      Moved inherit above #include and removed trailing ; in #include
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
   "around the walls have crumbled to the floor.  At\n"+
   "the back side of the tower stands a large wooden\n"+
   "door.\n";
   add_item("tower","Made of solid stone, the tower rises high above the land");
   add_item("door","A large wooden door you can '"+HIW+"enter"+NORM+"'");
   add_item("stones","Large stones laying on the ground");
   add_item("floor","The stone floor is littered with large broken stones");
   add_exit("/players/jaraxle/closed/phoenix/rooms/floor1b.c","back");
   add_exit("/players/jaraxle/closed/phoenix/rooms/floor1d.c","around");
   
}

init(){
   ::init();
   add_action("enter_door","enter");
}

enter_door(str){
   if(!str) return (notify_fail("You may enter the door.\n"), 0);
   if(str == "door" || str == "wooden door"){
      write("You slowly open the door and enter the room.\n");
      this_player()->move_player("through the door#/players/jaraxle/closed/phoenix/rooms/door1");
      return 1; }
   notify_fail("Enter what?\n"); return 0; }
