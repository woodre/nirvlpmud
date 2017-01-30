#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";
inherit "/players/earwax/housing/land";

reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc = "Tree-Top Kingdom";
   long_desc =
   "  The tree tops clear into a wide open area of thick branches\n"+
   "and planks of long wood.  A small staircase leads off to the\n"+
   "east while short rope bridges stretch towards flats in almost\n"+
   "every direction.\n";
   /* Land additions, thanks Earwax. */
   set_cost(400000);
   set_realm_name("Third Earth");
   set_lot_size(2);
   setup_land();
   /* End land additions */
   items = ({
         "tree tops","The tops of the large trees for the village",
         "branches","Large branches capeable of holding up small huts",
         "planks","Thick and flat planks of hefty wood",
         "staircase","A staircase to the east leading towards the shops",
         "bridges","Short bridges in the north, south, and west directions",
         "flats","Large flats of wood, normally for building huts on",
});
   
}
init() {
   ::init();
   add_action("north","north");
   add_action("south","south");
   add_action("west","west");
   add_action("east","east");
}

north() {
write("This bridge is closed at the moment.\n");
/*
   this_player()->move_player("north#/players/jaraxle/3rd/warrior/rooms/treew2");
*/
   return 1; }

east() {
   write("You cross the east bridge.\n");
   this_player()->move_player("goes east#/players/jaraxle/3rd/warrior/rooms/treew");
   return 1; }

south() {
write("This bridge is closed at the moment.\n");
/*
   this_player()->move_player("north#/players/jaraxle/3rd/warrior/rooms/treew2");
*/
   return 1; }

west() {
write("This bridge is closed at the moment.\n");
/*
   this_player()->move_player("north#/players/jaraxle/3rd/warrior/rooms/treew2");
*/
   return 1; }
