#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   if(arg) return;
   set_light(0);
   get_random_mob();
   short_desc = BLK+BOLD+"Village road"+NORM;
   long_desc =
   "  A long, deserted road going through the village. This\n"+
   "road is well worn from constant travel of people long\n"+
   "lost.  There is a sign on the north side of the road\n"+
   "and a broken down brick building to the south.\n"+
   "There is a dark hole in the ground.\n";
   
add_item("hole","A dark hole you might be able to "+HIW+"enter"+NORM+"");
   add_item("sign","You can barely make out the word 'shop' on the sign");
   add_item("building","This looks like a huge gathering place stood here");
   add_item("brick building","This looks like a huge gathering place stood here");
   
   add_exit("/players/jaraxle/3rd/alt/rooms/road1.c","west");
   add_exit("/players/jaraxle/3rd/alt/rooms/road3.c","east");
   add_exit("/players/jaraxle/3rd/alt/rooms/adv_guild.c","south");
   add_exit("/players/jaraxle/3rd/alt/rooms/shop.c","north");
}


init(){
   ::init();
   add_action("enter","enter");
}
enter(str){
   if(!str) return (notify_fail("You may enter the hole.\n"), 0);
   if(str == "hole" || str == "dark hole"){
write("You jump down into the dark hole.\n");
TP->move_player("into a hole#/players/jaraxle/3rd/alt/rooms/hole.c");
      return 1; }
   notify_fail("Enter what?\n"); return 0; }
