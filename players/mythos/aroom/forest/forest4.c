inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(0);
    short_desc = "Forest";
    long_desc =
    "The forest is dark- very dark...light has trouble entering...  \n"+
    "in fact it is as if you have entered night.  The trees are creepy \n"+
    "and seem to move in the dim light. You feel as if something is watching\n"+
    "you.....\n";
  items = ({
    "east","The forest streches far as one can see",
    "west","Something between the trees catches your eyes",
    "north","The forest continues",
  });

  dest_dir = ({
    "/players/mythos/aroom/forest/forest9.c","south",
    "/players/mythos/aroom/forest/forest5.c","north",
    "/players/mythos/aroom/forest/pool.c","west",
    "/players/mythos/aroom/forest/forestr.c","east",
  });
} }
