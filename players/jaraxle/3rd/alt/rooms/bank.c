#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   if(arg) return;
   set_light(0);
   get_random_mob();
   short_desc = BLK+BOLD+"The bank"+NORM;
   long_desc =
   "  An abandoned establishment of old desks, kiosks\n"+
   "and small empty offices.  This office space looks\n"+
   "like an old bank depository.  You see a large safe\n"+
   "far in the rear of the room.\n";
   add_item("offices","This is where people conducted daily business");
   
   add_item("kiosks","Display areas with old pamphlets");
   add_item("safe","A huge safe in the backroom.\nLooks like you can enter");
   add_exit("/players/jaraxle/3rd/alt/rooms/northroad1.c","west");
   
}

init(){
   ::init();
   add_action("enter","enter");
}
enter(str){
   if(!str) return (notify_fail("You may enter the safe.\n"), 0);
   if(str == "safe" || str == "huge safe"){
      write("You walk to the backroom and enter the safe.");
      TP->move_player("into the safe#/players/jaraxle/3rd/alt/rooms/safe.c");
      return 1; }
   notify_fail("Enter what?\n"); return 0; }
