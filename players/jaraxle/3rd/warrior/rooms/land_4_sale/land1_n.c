#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";
inherit "/players/earwax/housing/land";

reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc = "Tree-Top Kingdom";
   long_desc =
   "  A small flat to the north of the clearing in the tree tops.  Long\n"+
   "wood planks line the thick branches that stretch out from the trees.\n"+
   "A short rope bridge leads towards the south into the open clearing.\n";
   add_item("flat","A clearing of branches and trees. [perfect for building]");
   add_item("clearing","A wide open area among the tree tops");
   add_item("planks","Planks of thick wood stretched across the clearing");
   add_item("branches","Thick branches that have grown from the healthy trees");
   add_item("trees","Wonderfully landscaped and lushly grown trees");
   add_item("bridge","A short bridge to the south");
   add_item("clearing","A wide open clearing");
   /* Land additions, thanks Earwax. */
   set_cost(750000);
   set_realm_name("Third Earth");
   set_lot_size(2);
   setup_land();
   /* End land additions */
   
}
init() {
   ::init();
   add_action("south","south");
   add_action("east","east");
}
south() {
   write("This bridge is closed at the moment.\n");
   TP->move_player("north#/players/jaraxle/3rd/warrior/rooms/land_4_sale/land1");
   return 1; }
