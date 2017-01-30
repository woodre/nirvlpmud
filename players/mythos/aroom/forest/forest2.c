inherit "room/room";
reset(arg) {
  if(!present("ryo")) {
    move_object(clone_object("/players/mythos/amon/forest/ryo2.c"),this_object());
  }
  if(!arg) {
  set_light(1);
    short_desc = "Forest entrance2";
    long_desc =
    "The forest is dark- very dark...light has trouble entering...  \n"+
    "in fact it is as if you have entered night.  The 'trees' are creepy\n"+
    "and seem to move in the dim light. You feel as if something is watching\n"+
    "you.....\n";
  items = ({
    "rice","You can return to the rice patties",
    "north","There seems to be a dark path leading off- just thinking \n"+
    "of going down it sends shivers down your back",
    "east","The forest streches far as one can see",
    "west","You see the end of the forest",
    "trees","Something wispy catches your eyes....A malicious spirit- a Ryo- is nearby",
  });

  dest_dir = ({
    "/players/mythos/aroom/ricev.c","rice",
    "/players/mythos/aroom/forest/forest3.c","east",
    "/players/mythos/aroom/forest/pathway.c","north",
    "/players/mythos/aroom/forest/forest.c","west",
  });
} }
