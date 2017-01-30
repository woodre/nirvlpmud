inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(1);
    short_desc = "Village Enterance";
    long_desc =
      "You reach the enterance to the village.  To the east the\n"+
      "rest of the village stretches.  To the north is the SHOP\n"+
      "and to the south is the BAR.\n";
  items = ({
      "north","You see the grand shop to the north",
      "south","To the south is a place to relax- the bar",
      "east","The rest of the village stretches to the east",
      "west","The portal, the hut, and the rice fields are to the west",
  });

  dest_dir = ({
    "/players/mythos/aroom/shopa.c", "north",
    "/players/mythos/aroom/puba.c","south",
    "/players/mythos/aroom/path2.c","west",
  });
} }
