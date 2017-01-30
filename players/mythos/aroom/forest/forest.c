inherit "room/room";
reset(arg) {
  if(!present("ryo")) {
    move_object(clone_object("/players/mythos/amon/forest/ryo2.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "Forest entrance";
    long_desc =
    "The forest is dark- very dark...light has trouble entering...  \n"+
    "in fact it is as if you have entered night.  The 'trees' are \n"+
    "creepy and seem to move in the dim light You feel as if something \n"+
    "is watching you.....\n";
  items = ({
    "trees","Something fliters by you see a ryo",
    "rice","You can return to the rice patties",
    "east","The forest streches far as one can see",
  });

  dest_dir = ({
    "/players/mythos/aroom/rice.c", "rice",
    "/players/mythos/aroom/forest/forest2.c","east",
  });
} }
