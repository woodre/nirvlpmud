#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Tree-Top Bridge";
long_desc =
        "  This is the center of a long wooden bridge which slithers amongst the\n"+
        "trees that here grow abundantly.  They flourish under the slight sunlight\n"+
        "that peeks through leaves into the forest.\n";
MOCO("/players/jaraxle/3rd/warrior/mon/ahna.c"),TO);

items = ({
  "forest","An endless forest full of trees",
  "trees","Exciting trees that grow untamed in the forest",
  "bridge","A long, thin wooden bridge that slithers through a few trees.\nIt stretches to the east and west",
  "sunlight","Sunlight is filtered into the forest through the plush trees",
});


}
init() {

::init();

add_action("west","west");
add_action("east","east");
}

west() {
write("You go back west.\n");
this_player()->move_player("west#/players/jaraxle/3rd/warrior/rooms/treew2");
return 1; }

east() {
write("You continue eastward on the bridge.\n");
this_player()->move_player("east#/players/jaraxle/3rd/warrior/rooms/treee2");
return 1; }



