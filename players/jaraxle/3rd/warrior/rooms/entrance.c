#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Third Earth";
long_desc =
        "  This is the entrance to a large forest.  Thick trees grow wild\n"+
        "and freely.  The ground is covered with plush grass, and scattered\n"+
        "with rocks of all sizes.  The sunlight fights its way through the\n"+
        "thick branches of the trees above.  Shadows bounce off the trees,\n"+
        "casting dancing images at every glance.\n";

items = ({
  "grass","Thick, "+GRN+"green"+NORM+" grass seems to cover everything",
  "ground","Small rocks litter the ground, which is plush with very green grass",
  "forest","Looming trees overhead, dark shadows lurking in ever corner",
  "shadows","Dark shadows, spilling from the south which dance in and out of the forest here",
  "trees","High reaching trees with thick branches stretching out everywhere",
  "branches","Large branches which grow low to the ground",
  "rocks","Rocks of various small sizes scattered about",
  "sunlight","Few beams of sunlight break through the gaps created by the trees",
});

MOCO("/players/jaraxle/3rd/warrior/signpost.c"),TO);
dest_dir = ({
  "room/eastroad2","back",
  "/players/jaraxle/3rd/warrior/rooms/roomw.c","west",
  "/players/jaraxle/3rd/warrior/rooms/roomw2.c","northwest",
  "/players/jaraxle/3rd/warrior/rooms/roome2.c","northeast",
  "/players/jaraxle/3rd/warrior/rooms/roome.c","east",
  "/players/jaraxle/3rd/warrior/rooms/room2.c","north",
  "/players/jaraxle/3rd/warrior/rooms/pyr_path1.c","south",
});

}

