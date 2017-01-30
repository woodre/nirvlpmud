
#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(2);

short_desc = "Tree-Top Kingdom";
long_desc =
        "  A wooden flat hidden behind a wall of vines.  The floor\n"+
        "is made of several planks of branches, tightly tied together\n"+
        "with rope.  Four tall torches line the wall of a hut, which\n"+
        "takes up the entire northern point of the flat.\n";

items = ({
  "flat","The flat is quite large for the trees.  It has a smooth wooden floor",
  "floor","The floor is made of smoothed out branches called planks, which are tied together with rope",
  "rope","Rope made from dead vines",
  "planks","Dried branches, smoothed out and tied together with rope",
  "branches","Tree branches  smoothed out and tied together with rope",
  "hut","A rather plain looking hut.  The walls are made of tree bark.\nThere is an emblem over the entrance",
  "emblem","The emblem is for the Queen of the Warrior Maidens",
  "torches","Four torches about four feet in height.  Each one is very thin with a large bowl on the top.\n"+HIR+"Flames"+NORM+" burn high and bright out of the bowls",
  "wall","A thick wall of vines",
  "vines","Green vines tightly nit together create a formidable wall",
});

MOCO("/players/jaraxle/3rd/warrior/mon/w_guard.c"),TO);
MOCO("/players/jaraxle/3rd/warrior/mon/w_guard.c"),TO);

dest_dir = ({
  "/players/jaraxle/3rd/warrior/rooms/s_tree.c","down",
});

}
init() {

::init();

add_action("in_hut","enter");
}

in_hut() {
write("You bravely enter the hut.\n");
this_player()->move_player("into a hut#/players/jaraxle/3rd/warrior/rooms/hut3");
return 1; }


