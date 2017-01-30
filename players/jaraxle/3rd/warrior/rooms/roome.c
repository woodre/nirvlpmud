#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Third Earth";
long_desc =
        "  The forest opens to a square shaped clearing.  Rustling leaves can\n"+
        "be heard throughout the waving trees overhead.  The ground is hard and\n"+
        "flat, yet warm in patches from the sunlight flickering through the treetops.\n"+
        "Mounds of dirt push their way through the ground in several locations\n"+
        "of this clearing.\n";

items = ({
  "leaves","Large leaves of various shapes.\nThey must have fallen from the trees above",
  "sunlight","Bright beams of sunlight entering the clearing through breaks of leaves and branches in the treetops",
  "treetops","High above you the trees crest with dark hues of green and brown leaves growing on mighty branches",
  "forest","High reaching trees with thick branches waving slowly in the wind",
  "ground","Flat green grass, with mounds of dirt all around.  Spots shine out with brightness from the sunlight",
  "trees","High reaching trees with thick branches stretching out everywhere",
  "mounds","Small cave-like mounds also known as rabbit holes",
  "branches","Large branches which grow low to the ground.\nPerhaps you can use them to "+HIW+"climb"+NORM+" up the "+HIW+"trees"+NORM+" with",
  "dirt","Light brown dirt recently disturbed",
  "clearing","Flat grass surrounded in a square shape by high trees",
});


dest_dir = ({
  "/players/jaraxle/3rd/warrior/rooms/entrance.c","west",
"/players/jaraxle/3rd/warrior/rooms/roome2.c","north",
"/players/jaraxle/3rd/warrior/rooms/room2.c","northwest",
});

}
init() {

::init();

add_action("climb","climb");
}
climb(arg) {
if(arg == "trees" || arg == "tree") {
write("You climb up the branches into the tree.\n");
 this_player()->move_player("climbs up a tree#/players/jaraxle/3rd/warrior/rooms/treee");
return 1; }
write("Climb what?\n"); return 1; }


