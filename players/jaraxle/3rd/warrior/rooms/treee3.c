#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Tree-Top Village";
long_desc =
        "  This northeastern corner of the forest is a very populated\n"+
        "area of the village.  There are a set of bridges connected to this\n"+
        "flat.  A growth of thick, green vines growing from the floor make\n"+
        "a wall on the east side of the flat.\n";

items = ({
  "forest","A thick, plush area of trees",
"vines","Large, thick, green vines make a wall possibly protecting something behind it",
"wall","A large wall made from vines.\nThere are noises comming from behind the wall.\  Maybe you can "+HIG+"cut"+NORM+" your way through",
  "flat","The wooden floor is full of vines, wrapped around everything",
  "bridges","A long set of wooden bridges that sink into the trees.\nYou can go west or south",
  "floor","The floor is covered in vines, which trail to the east.\nThe vines then grow straight up making a large wall about nine feet in height"
});
MOCO("/players/jaraxle/3rd/warrior/mon/liza.c"),TO);


}
init() {

::init();

add_action("west","west");
add_action("south","south");
add_action("cut_me","cut");
}

west() {
write("You go back west.\n");
this_player()->move_player("west#/players/jaraxle/3rd/warrior/rooms/tree3");
return 1; }

south() {
write("You continue south on the bridge.\n");
this_player()->move_player("south#/players/jaraxle/3rd/warrior/rooms/treee2");
return 1; }

cut_me(arg){
if(arg == "vines" || arg == "wall"){
if(present("machete",TP)){
write("You hack at the vines and make your way through.\n");
this_player()->move_player("into the wall#/players/jaraxle/3rd/warrior/rooms/s_tree");
return 1; }
}
write("What?\n");
return 1; }

