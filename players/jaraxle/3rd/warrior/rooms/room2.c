#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Third Earth";
long_desc =
        "  A large clearing, perhaps the middle of the forest.  Towering trees\n"+
        "encircle all around, almost capturing the clearing in a neat, upside\n"+
        "down bowl.  The treetops loom overhead, creating an umbrella like covering.\n"+
        "The grass is cold, yet solid and not damp to the touch.  Tiny rustlings can\n"+
        "be heard in the surrounding bushes, as leaves trickle down lightly like a\n"+
        "sprinkle of rain.\n";
items = ({
  "forest","A clearing in the forest, the trees make an almost perfect circle around you",
  "clearing","No trees grow in the center of the clearing.\nThe trees have risen around the clearing in an almost perfect circle",
  "grass","Thin, "+GRN+"green"+NORM+" grass softly grows here",
  "trees","High reaching trees with thick branches stretching out everywhere",
  "branches","Large branches which grow low to the ground",
  "leaves","Fallen leaves from the trees above. They are in shades of dark green to an almost translucent brown",
  "treetops","A large canopy of leaves and branches cover you like a ceiling",
});
MOCO("/players/jaraxle/3rd/warrior/mon/w_rabbit.c"),TO);
MOCO("/players/jaraxle/3rd/warrior/mon/w_rabbit.c"),TO);
MOCO("/players/jaraxle/3rd/warrior/mon/bl_rabbit.c"),TO);

add_object("/players/jaraxle/closed/phoenix/rooms/tower.c");

dest_dir = ({
  "/players/jaraxle/3rd/warrior/rooms/roomw2.c","west",
  "/players/jaraxle/3rd/warrior/rooms/roomw3.c","northwest",
  "/players/jaraxle/3rd/warrior/rooms/roome3.c","northeast",
  "/players/jaraxle/3rd/warrior/rooms/roome2.c","east",
  "/players/jaraxle/3rd/warrior/rooms/entrance.c","south",
  "/players/jaraxle/3rd/warrior/rooms/room3.c","north",
});

}

