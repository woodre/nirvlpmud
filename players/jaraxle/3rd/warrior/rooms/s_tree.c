#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Tree-Top Kingdom";
long_desc =
        "  This flat is a lavish treasure area full of sparkling jewels.\n"+
        "There are several vines hanging still against the wall.  Leaves\n"+
        "and sticks carpet the floor of the flat.  A chest sits in the\n"+
        "center, part way open.\n";

items = ({
  "jewels","There are rather large red jewels, small blue haze and yellow jewels.\nUpong closer inspection, they are just worthless glass",
  "wall","A wall made strictly of dark green vine",
  "leaves","Green and brown leaves fall from the tree tops and land on the floor of this room",
  "vines","Several medium sized vines hanging about, there is one thick vine grabbing your attention",
  "thick vine","A thick, green vine you can probably "+HIW+"climb"+NORM+"",
  "floor","Green and Brown leaves from the branches around you have fallen silent onto the floor.\nSticks and twigs are scattered about",
  "sticks","Assorted sizes and lengths of sticks from the branches surrounding the room have fallen to the floor",
  "twigs","Assorted sizes and lengths of twigs from the branches surrounding the room have fallen to the floor",
  "chest","A partway open chest.\nThere is nothing inside",
  "flat","A platform full of sparkling jewels",
});

MOCO("/players/jaraxle/3rd/warrior/mon/w_guard.c"),TO);
MOCO("/players/jaraxle/3rd/warrior/mon/w_guard.c"),TO);
MOCO("/players/jaraxle/3rd/warrior/mon/w_guard.c"),TO);

dest_dir = ({
  "/players/jaraxle/3rd/warrior/rooms/treee3.c","back",
});

}
init() {

::init();

add_action("climb_up","climb");
}

climb_up() {
write("You grab onto the vine and pull yourself up.\n");
this_player()->move_player("up#/players/jaraxle/3rd/warrior/rooms/s_tree2");
return 1; }


