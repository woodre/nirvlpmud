#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Third Earth";
long_desc =
  "  Dense trees form a barrier from the north and west.  A\n"+
  "dwarfed row of bushes grow along the treeline to the north.\n"+
  "The ground is littered with pebbles and stones of assorted\n"+
  "sizes, and begins to rise and fall with small hills and humps in\n"+
  "the eastern direction.\n";

items = ({
  "forest","High reaching trees with thick branches stretching out everywhere",
  "treeline","High reaching trees growing side by side, creating a wall to the north",
  "humps","The humps are small raises in the ground",
  "hills","The hills are low, raised portions of the ground",
  "bushes","A row of "+HIG+"green"+NORM+" bushes growing all by themselves",
  "pebbles","Pebbles of various sizes lying about",
  "stones","Stones of rather small sizes.  The stones are smooth in texture",
  "trees","High reaching trees with thick branches stretching out everywhere",
  "ground","The ground here starts flat from the west, then takes the shape of small, low, hills to the east",
  "branches","Large branches which grow low to the ground.\nPerhaps you can use them to "+HIW+"climb"+NORM+" up the "+HIW+"trees"+NORM+" with",
});

MOCO("/players/jaraxle/3rd/warrior/mon/w_rabbit.c"),TO);
MOCO("/players/jaraxle/3rd/warrior/mon/w_rabbit.c"),TO);

dest_dir = ({
  "/players/jaraxle/3rd/warrior/rooms/room3.c","east",
  "/players/jaraxle/3rd/warrior/rooms/room2.c","southeast",
  "/players/jaraxle/3rd/warrior/rooms/roomw2.c","south",
   "/players/jaraxle/cont/rdragon/rooms/pond2.c","northwest",
});

}
init() {

::init();

add_action("climb","climb");
}
climb(arg) {
if(arg == "trees" || arg == "tree") {
write("You climb up the branches into the tree.\n");
 this_player()->move_player("climbs up a tree#/players/jaraxle/3rd/warrior/rooms/treew3");
return 1; }
write("Climb what?\n"); return 1; }

