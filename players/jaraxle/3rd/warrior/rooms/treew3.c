#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Tree-Top Village";
long_desc =
        "  This flat is laid around a hefty tree trunk in the forest. There\n"+
        "is a soft covering of branches high above, reaching out from the\n"+
        "tree, creating the look of a ceiling from the dark greens.  The\n"+
        "floor is made of branches wrapped in dead vines.  Bridges are\n"+
        "connected to the flat by strong looking posts.\n";

items = ({
  "tree","There are SO many trees to look through, your eyes get lost",
  "trees","There are SO many trees to look through, your eyes get lost",
  "branches","Thick and thin branches creeping out from the many trees",
  "flat","A wooden flat in the shape of a circle, surrounding an abnormally large tree trunk",
  "vines","Green and grey vines wrapped around the floor of the flat",
  "floor","Branches wrapped in "+HIG+"vines"+NORM+" made into a sturdy floor",
  "posts","Thick wooden posts where the bridges are tied off",
  "forest","Tree tops of lush "+GRN+"green"+NORM+" leaves",
  "bridges","A bridge trails to the east and south of here",
  "trunk","A huge tree trunk.\nThere is a door constructed in the middle of the trunk",
  "door","A rather humble door with no designs.\nYou can "+HIW+"enter"+NORM+" the "+HIW+"trunk"+NORM+" of this massive tree through this door",
  "ceiling","Not really a ceiling, but a hefty covering of leaves",
});

dest_dir = ({
"/players/jaraxle/3rd/warrior/rooms/roomw3.c","descend",
});

}
init() {

::init();

add_action("east","east");
add_action("enter","enter");
add_action("south","south");
}

east() {
write("You cross the east bridge.\n");
this_player()->move_player("east#/players/jaraxle/3rd/warrior/rooms/tree3");
return 1; }

south(){
write("You cross the bridge to the south.\n");
this_player()->move_player("south#/players/jaraxle/3rd/warrior/rooms/treew2");
return 1; }
enter(arg){
if(arg == "trunk"){
write("You open the door and enter the tree trunk.\n");
this_player()->move_player("into the trunk#/players/jaraxle/3rd/warrior/rooms/hut2");
return 1; }
write("Enter what?\n");
return 1; }



