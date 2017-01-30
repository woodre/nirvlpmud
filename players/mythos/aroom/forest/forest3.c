inherit "room/room";
reset(arg) {
  if(!present("ryo")) {
    move_object(clone_object("/players/mythos/amon/forest/ryo2.c"),this_object());
  }
  if(!arg) {
  set_light(1);
    short_desc = "Forest entrance3";
    long_desc =
    "The forest is dark- very dark...light has trouble entering...  \n"+
    "in fact it is as if you have entered night.  The 'trees' are creepy \n"+
    "and seem to move in the dim light. You feel as if something is watching\n"+
    "you.....\n";
  items = ({
    "northeast","The forest streches far as one can see",
    "west","The forest ends that way",
    "north","Something attracts your eye",
    "trees","You notice something strange flying around...it is a Ryo- an evil spirit",
  });

  dest_dir = ({
    "/players/mythos/aroom/forest/forest9.c","east",
    "/players/mythos/aroom/shrinear.c","shrine",
    "/players/mythos/aroom/forest/forest2.c","west",
    "/players/mythos/aroom/forest/pool.c","north",
  });
} }
