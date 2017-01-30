inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(0);
    short_desc = "Forest pathway";
    long_desc =
    "The forest is dark- very dark...light has trouble entering...  \n"+
    "in fact it is as if you have entered night.  The trees are creepy \n"+
    "and seem to move in the dim light. The path is gloomy and all is dark....\n";
  items = ({
    "south","The path returns to the forest",
    "north","The dark path continues",
    "east","The forest continues on",
  });

  dest_dir = ({
    "/players/mythos/aroom/forest/forest2.c", "south",
    "/players/mythos/aroom/forest/pathway2.c","north",
    "/players/mythos/aroom/forest/pool.c","east",
  });
} }
