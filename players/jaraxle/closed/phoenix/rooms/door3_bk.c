#include "/players/jaraxle/define.h"
#include "/players/jaraxle/closed/phoenix/mons/random.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   get_random_mob();
   short_desc = "Tower of the "+RED+"["+HIR+"Pho"+BLK+"e"+HIR+"nix"+NORM+RED+"]"+NORM;
   long_desc =
   "  A huge square room at the back of the tower.\n"+
   "The walls are singed in ashen black from the ground\n"+
   "up.  The stone floor is warm to the touch. A\n"+
   "tall door stands as the only exit from the room.\n";
   items = ({
         "tower","Made of solid stone, the tower rises high above the land",
         "door","A large wooden door you can '"+HIW+"enter"+NORM+"'",
   });
   
add_object("/players/jaraxle/closed/phoenix/mons/mon2.c");
}

init(){
   ::init();
   add_action("enter_door","enter");
}

enter_door(str){
   if(!str) return (notify_fail("You may enter the door.\n"), 0);
if(str == "door" || str == "wooden door"){
      write("You slowly open the door and enter the room.\n");
this_player()->move_player("through the door#/players/jaraxle/closed/phoenix/rooms/floor4c");
      return 1; }
notify_fail("Enter what?\n"); return 0; }
