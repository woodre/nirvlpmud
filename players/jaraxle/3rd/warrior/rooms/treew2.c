#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Tree-Top Bridge";
long_desc =
        "  This is the center of a long wooden bridge.  Trees grow in\n"+
        "irregular patterns around the bridge.  There is a junction to\n"+
        "the east where the bridge sinks quickly into the shadows of the\n"+
        "heavily leafed branches.\n";

items = ({
  "trees","Exciting trees that grow untamed through forest",
  "landing","A small platform connected to the bridge by hardened handrails",
  "branches","Branches with an overwhelming amount of leaves growing on them",
  "bridge","A long wooden bridge that disappears into the trees, north and south.\nThere is a thin portion of the bridge streatching out to the east.\nThere is a small landing on the bridge that you can "+HIW+"look over"+NORM+" the "+HIW+"bridge"+NORM+" from",
  "forest","Trees of all sizes, growing to numerous heights.\nDark greens and browns tangle with bright greens throughout the forest",
  "junction","A junction in the middle of the bridge where it leads to the east",
  "shadows","Dark shadows where the sunlight does not breakthrough the leafy trees",
});


}
init() {

::init();

add_action("north","north");
add_action("south","south");
add_action("east","east");
add_action("lok","look");
}

north() {
write("You go north over the bridge.\n");
this_player()->move_player("north#/players/jaraxle/3rd/warrior/rooms/treew3");
return 1; }
east(){
write("You move over the bridge to the east.\n");
this_player()->move_player("east#/players/jaraxle/3rd/warrior/rooms/tree2");
return 1; }

south() {
write("You move over the bridge to the south.\n");
this_player()->move_player("goes east#/players/jaraxle/3rd/warrior/rooms/treew");
return 1; }

lok(arg){
if(arg == "over bridge"){
write("You look over the bridge . . .\n\n");
      move_object(this_player(), "/players/jaraxle/3rd/warrior/rooms/roomw2.c");
      command("look", TP);
  move_object(this_player(), this_object());
return 1; }
}


