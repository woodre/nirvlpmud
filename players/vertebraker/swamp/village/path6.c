#include "../define.h"
inherit ROOM;

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("The end of the village");
   set_long(
      "     The village path ends here in a thick cluster of trees.  A\n"+
      "small, dark hole rests in the ground next to a small wooden\n"+
      "sign.  A few trees around you seem to wobble a bit, as though\n"+
      "they contain some degree of wildlife within their branches.\n");
   add_item("trail","You could \"walk\" the trail down to the\n"+
      " SwampLands");
   add_item(({"town","village"}),"The village stands back to the northwest");
   add_item("road","The dusty road wraps back up the hill to town");
   add_item("trees","A few puffy, sullen trees seem to harbor some\n"+
      " wildlife");
   add_item("sign","There is a small wooden sign here that you can 'read'");
   add_item("hole",
      "A small and dark hole burrowed into the ground.  You might be able\n"+
      " to \"descend\" into the hole, and see where it takes you");
   add_item(({"animals","wildlife"}),"You spy a few critters wandering around");
   add_item("critters","Just a few forest critters that appear, and then dart\n"+
      " back beneath the safety of the trees"); 
   add_object(NPC_DIR+"villager");
   add_object(NPC_DIR+"guard");
   add_exit(VILLAGE+"path5","northwest"); }

init() {
   ::init();
   add_action("descend","descend");
   add_action("read","read");
   add_action("descend","enter");
}

descend(str) {
   if(str == "hole") {
      write("You descend into the dark hole...\n");
      TP->move_player("down into the hole#"+VILLAGE+"tun1");
      return 1; }
}

read(str) {
   if(str == "sign" || str == "the sign") {
      write("The sign reads:\n\n"+
         "  TO ENTER THE SWAMPLANDS, HEAD DOWN THE HOLE.\n"+
         "\n\nSome newly scratched writing reads:\n"+
         "** DANGER ** Swamp closed by order of Juribel, 8-2000.\n");
      return 1;
   }
}
