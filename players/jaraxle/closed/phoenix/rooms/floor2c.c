/*  10/08/06 - Rumplemintz
      Moved inherit above #include and removed trailing ; from #include
*/

inherit "/players/jaraxle/room.c";
#include "/players/jaraxle/define.h"
#include "/players/jaraxle/closed/phoenix/mons/random.h"

int locked;
reset(arg) {
   if(arg) return;
   locked == 0;
   set_light(1);
   get_random_mob();
   short_desc = "Tower of the "+RED+"["+HIR+"Pho"+BLK+"e"+HIR+"nix"+NORM+RED+"]"+NORM;
   long_desc =
   "  A large forgotten tower in ruins.  Stones from\n"+
   "around the walls have crumbled to the floor.  At\n"+
   "the back side of the tower stands a large wooden\n"+
   "door.\n";
add_item("door","blah");
add_item("slot","A round slot.  It looks like you\nwould be able to place somekind\nof sphere inside of it");
   add_item("tower","Made of solid stone, the tower rises high above the land");
   add_exit("/players/jaraxle/closed/phoenix/rooms/floor2d.c","around");
   add_exit("/players/jaraxle/closed/phoenix/rooms/floor2b.c","back");
}

init(){
   ::init();
   add_action("enter_door","enter");
   add_action("unlock_door","place");
}

long(arg)
{
   if(arg == "door")
      {
      string mod;
      
      if(locked == 1)
         mod = ""+CYN+"a glowing sphere"+NORM+"";
      else
         mod = ""+HIW+"an empty slot"+NORM+"";
      
      write("A large wooden door with the symbol of the Vulpine\n"+
         "carved across the top.  In the center of the door\n"+
         "there is "+mod+" which is round and smooth.\n");
      
      return;
   }
   
   ::long(arg);
}

enter_door(str){
   if(!str) return (notify_fail("You may enter the door.\n"), 0);
   if(str == "door" || str == "wooden door"){
      if(locked == 0){
         write("The door will not budge.\n");
         return 1; }
      write("You use all your might to push open the door and\n"+
         "walk inside slowly.\n");
      TP->move_player("through a door#/players/jaraxle/closed/phoenix/rooms/throne");
      return 1; }
   notify_fail("Enter what?\n"); return 0; }

unlock_door(str){
   if(!present("key_sphere1",TP)){ write("Place what?\n"); return 1; }
   if(locked >=1){ write("There is a Key Sphere in the slot already.\n"); return 1; }
   if(!str) return (notify_fail("Place what?\n"), 0);
   if(str == "key in slot" || str == "sphere in slot" || str == "key sphere in slot"){
      write("You reach up and place the Key Sphere in the round slot\non the door and hear a click.\n");
destruct(present("key_sphere1",TP));
      locked +=1;
      return 1; }
   notify_fail("Place what?\n"); return 0; }
