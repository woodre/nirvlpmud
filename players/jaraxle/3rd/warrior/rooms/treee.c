#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Tree-Top Village";
long_desc =
        "  A flat of the Tree-Top Village.  The floor is made of branches\n"+
        "tied with rope, and covered in large leaves.  A square shaped hut\n"+
        "sits on the eastern edge of the flat.  A set of bridges dip into\n"+
        "the trees, connected to the flat by small posts.\n";
items = ({
  "branches","Thick branches make up the floor of the flat.\nThe branches are tied together with dried vines",
  "vines","Dried, grey vines wrapped and tied around branches to make a floor",
  "trees","A close gathering of trees",
  "bridges","A pair long wooden bridges that disappears to the west and north",
  "hut","A small size hut, smelling of sweet fruit.\nPerhaps you can "+HIW+"enter"+NORM+" this "+HIW+"hut"+NORM+"",
  "posts","A pair of thin posts on the west and north end of the flat.\nThe bridges are tied off to the posts",
  "flat","A large open flat, with a floor made of branches",
  "leaves","Large green leaves covering the floor of the flat",
  "floor","Thick branches make up the floor of the flat.\nThe branches are tied together with dried vines and covered with large leaves",
});

MOCO("/players/jaraxle/3rd/warrior/mon/maiden.c"),TO);
dest_dir = ({
"/players/jaraxle/3rd/warrior/rooms/roome.c","descend",
});

}
init() {

::init();

add_action("west","west");
add_action("enter","enter");
add_action("north","north");
}

west() {
write("You go back west.\n");
this_player()->move_player("west#/players/jaraxle/3rd/warrior/rooms/tree");
return 1; }

north(){
write("You cross the bridge to the north.\n");
this_player()->move_player("north#/players/jaraxle/3rd/warrior/rooms/treee2");
return 1; }
enter(arg){
if(arg == "hut"){
write("You quietly enter the hut.\n");
this_player()->move_player("into the hut#/players/jaraxle/3rd/warrior/rooms/hut1");
return 1; }
write("Enter what?\n");
return 1; }


