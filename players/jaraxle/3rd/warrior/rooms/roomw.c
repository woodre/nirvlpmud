#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);
call_out("spring", 25);

short_desc = "Third Earth";
long_desc =
        "  The forest opens gradually to the west.  Tall trees grow untamed\n"+
        "to the south and  west making it almost impossible to see in those\n"+
        "directions.  The ground is very squishy and sloshy here.  Cute patches\n"+
        "of flowers grow in strange patterns around the tree trunks.  A small\n"+
        "spring gurgles faintly in the background.\n";

items = ({
  "forest","High reaching trees with thich branches stretching out everywhere",
  "spring","A small spring of bubbling hot water",
  "water","Steam rises slowly from the bubbling water",
  "ground","The ground is slightly wet, the dirt almost turns to mud from the small spring here",
  "trees","High reaching trees with thick branches stretching out everywhere",
  "branches","Large branches which grow low to the ground.\nPerhaps you can use them to "+HIW+"climb"+NORM+" up the "+HIW+"trees"+NORM+" with",
  "flowers","Daisies and dandilions grow in circular patterns around the tree trunks",
  "trunks","Thick tree trunks with flowers encircling them",
});


dest_dir = ({
  "/players/jaraxle/3rd/warrior/rooms/entrance.c","east",
"/players/jaraxle/3rd/warrior/rooms/roomw2.c","north",
"/players/jaraxle/3rd/warrior/rooms/room2.c","northeast",
});

}
init() {

::init();

add_action("climb","climb");
}
climb(arg) {
if(arg == "trees" || arg == "tree") {
write("You climb up the branches into the tree.\n");
 this_player()->move_player("climbs up a tree#/players/jaraxle/3rd/warrior/rooms/treew");
return 1; }
write("Climb what?\n"); return 1; }
spring(){
say("Water gurgles in the ground\n");
call_out("spring", 25);
return 1; }
