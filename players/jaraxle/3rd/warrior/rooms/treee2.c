#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Tree-Top Village";
long_desc =
   "  The bridges across this flat look rather dangerous, and old.  A wooden hut has been\n"+
   "recently constructed here.  Two small torches light the doorway to the hut.  A bright\n"+
  "rainbow of light reflects through the hut's window.\n"; 

items = ({
  "flat","The flat is littered with broken tools and the remains of a tattered hut",
  "hut","A small hut with open windows and a small door",
  "torches","Two wooden torches, one on each side of the small door",
  "door","The door of a hut, you can "+HIW+"enter"+NORM+"",
  "light","A reflection from the inside of the hut",
  "window","An opening on the side of the hut.\nRainbow beams of light shine around the window",
  "bridges","Bridges that stretch north, south, and westward.\nThe bridges do not look properly connected to the flat",
});

dest_dir = ({
"/players/jaraxle/3rd/warrior/rooms/roome2.c","descend",
});

}
init() {

::init();

add_action("west","west");
add_action("enter","enter");
add_action("north","north");
add_action("south","south");
}

west() {
write("You go back west.\n");
this_player()->move_player("west#/players/jaraxle/3rd/warrior/rooms/tree2");
return 1; }

north(){
write("You cross the bridge to the north.\n");
this_player()->move_player("north#/players/jaraxle/3rd/warrior/rooms/treee3");
return 1; }

south(){
write("You cross the southern bridge.\n");
this_player()->move_player("south#/players/jaraxle/3rd/warrior/rooms/treee");
return 1; }

enter(arg){
if(arg == "hut"){
write("You quietly enter the hut.\n");
this_player()->move_player("into the hut#/players/jaraxle/3rd/warrior/rooms/hut4");
return 1; }
notify_fail("Enter hut.\n");
}
