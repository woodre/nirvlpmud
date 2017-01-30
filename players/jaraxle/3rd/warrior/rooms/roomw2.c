#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Third Earth";
long_desc =
  "  The midwestern forest is abundant with trees.  Trails can\n"+
  "barely be seen leading off in many directions through the tree\n"+
  "trunks.  There is an opening through the trees to the east. A\n"+
  "mound defiantly pushes its way up through the disturbed ground.\n"+
  "Mushrooms and other fungi grow in bunches along the wet grass.\n"+
  "A cobblestone walkway has been built to the west.\n";

items = ({
  "forest","High reaching trees with thick branches stretching out everywhere",
  "walkway","A manmade walk of small stones",
  "cobblestone walkway","A manmade walk of small stones",
  "stones","Small round stones of various sizes",
  "mound","A hill of dirt with traces of grass around it from a rabbit making a new home",
  "trees","High reaching trees with thick branches stretching out everywhere",
  "opening","The trees grow lightly in the east, allowing for easy passage",
  "branches","Large branches which grow low to the ground.\nPerhaps you can use them to "+HIW+"climb"+NORM+" up the "+HIW+"trees"+NORM+" with",
  "mushrooms","Dark gray and brown mushrooms grow along the wet ground",
  "fungi","Bright green fungi growing along the west ground",
"trails","Trails off to the north, south, east, northeast, and southeastern directions",
  "grass","Moist grass covering the ground",
  "ground","Dirt and grass softened from water",
});

MOCO("/players/jaraxle/3rd/warrior/mon/w_rabbit.c"),TO);

dest_dir = ({
  "/players/jaraxle/3rd/warrior/rooms/room2.c","east",
  "/players/jaraxle/3rd/warrior/rooms/room3.c","northeast",
  "/players/jaraxle/3rd/warrior/rooms/entrance.c","southeast",
"/players/jaraxle/3rd/warrior/rooms/roomw.c","south",
"/players/jaraxle/3rd/warrior/rooms/roomw3.c","north",
 "/players/jaraxle/3rd/warrior/rooms/roomw_bridge.c","west",
});

}
init() {

::init();

add_action("climb","climb");
}
climb(arg) {
if(arg == "trees" || arg == "tree") {
write("You climb up the branches into the tree.\n");
 this_player()->move_player("climbs up a tree#/players/jaraxle/3rd/warrior/rooms/treew2");
return 1; }
write("Climb what?\n"); return 1; }

