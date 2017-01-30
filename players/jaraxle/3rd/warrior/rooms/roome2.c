#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Third Earth";
long_desc =
        "  This mideastern edge of the forest is quite tame and calm.  The\n"+
        "trees make a tall, close line along the edge of the forest barring\n"+
        "venture further to the east.  The grass is uneven, yet clear of forest\n"+
        "debris.  Groups of gathering flowers grow in sunlit patches to the north\n"+
        "and south.  A clear trail leads off to the western edge.\n";
items = ({
  "flowers","Small groups of dasies and dandelions grow in the sunlight that creeps through the treetops",
  "edge","The eastern edge of the forest is protected by an unpassable assemblage of trees",
  "forest","High reaching trees with thick branches waving slowly in the wind",
  "trees","Tall trees with thick branches surround the forest.  The trees are thickest to the east, where most of the passage is blocked.\nYou notice a thin break in a trees",
  "break","A gap between trees that looks like a path",
  "path","A thin path you can "+HIW+"walk"+NORM+"",
  "branches","Large branches which grow low to the ground.\nPerhaps you can use them to "+HIW+"climb"+NORM+" up the "+HIW+"trees"+NORM+" with",
  "grass","The grass grows in uneven heights up to six inches tall",
  "trail","A trail made of trampled grass from consistent travel",
  "trampled grass","Many footsteps have traveled this path",
  "dasies","Petit white and yellow dasies growing freely",
  "dandelions","Large puffs of dandelion seeds grow abundantly"
});


dest_dir = ({
  "/players/jaraxle/3rd/warrior/rooms/room2.c","west",
"/players/jaraxle/3rd/warrior/rooms/roome3.c","north", 
"/players/jaraxle/3rd/warrior/rooms/roome.c","south",
"/players/jaraxle/3rd/warrior/rooms/entrance.c","southwest",
"/players/jaraxle/3rd/warrior/rooms/room3.c","northwest",
});

}
init() {

::init();

add_action("climb","climb");
add_action("walk","walk");
add_action("walk","squeeze");
}
climb(arg) {
if(arg == "trees" || arg == "tree") {
write("You climb up the branches into the tree.\n");
this_player()->move_player("climbs up a tree#/players/jaraxle/3rd/warrior/rooms/treee2");
return 1; }
write("Climb what?\n"); return 1; }

walk(arg){
if(arg == "path" || arg == "east") {
write("You squeeze between the trees onto a path to the east.\n");
this_player()->move_player("walks the eastern path#/players/jaraxle/3rd/volcano/rooms/path");
return 1; }
notify_fail("Walk where?\n"); return 0; }
