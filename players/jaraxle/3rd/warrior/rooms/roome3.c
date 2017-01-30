#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Third Earth";
long_desc =
        "  In the northeast corner of the forest there is a fallen tree\n"+
        "trunk laying across the grass.  The ground comes in from the\n"+
        "west, full of humps and hills but flattens itself out when it \n"+
        "reaches the eastern edge of the forest.  The trees fence you\n"+
        "into the middle of the forest.\n";


items = ({
  "tree trunk","A large hollow tree trunk.\nThe perfect living area for snakes or skunks",
  "grass","The grass is pressed hard against the ground where the tree trunk lays.\nIt grows freely around the trunk",
  "humps","Small rises of the ground",
  "hills","Small inclines of the ground and grass",
  "ground","Solid ground from which thick, plush grass grows from",
  "trunk","A large hollow tree trunk.\nThe perfect living area for snakes or skunks",
  "forest","High reaching trees with thick branches waving slowly in the wind",
  "trees","High reaching trees with thick branches stretching out everywhere",
  "branches","Large branches which grow low to the ground.\nPerhaps you can use them to "+HIW+"climb"+NORM+" up the "+HIW+"trees"+NORM+" with",
});
MOCO("/players/jaraxle/3rd/warrior/mon/bl_rabbit.c"),TO);

dest_dir = ({
"/players/jaraxle/3rd/warrior/rooms/room3.c","west",
"/players/jaraxle/3rd/warrior/rooms/roome2.c","south",
"/players/jaraxle/3rd/warrior/rooms/room2.c","southwest",});

}
init() {

::init();

add_action("climb","climb");
}
climb(arg) {
if(arg == "trees" || arg == "tree") {
write("You climb up the branches into the tree.\n");
this_player()->move_player("climbs up a tree#/players/jaraxle/3rd/warrior/rooms/treee3");
return 1; }
write("Climb what?\n"); return 1; }

