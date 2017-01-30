inherit "room/room";
reset(arg) {
  if(!present("egg")) {
    move_object(clone_object("/players/mythos/amisc/egg2.c"),this_object()); }
  if(!arg) {
  set_light(-1);
    short_desc = "Forest pathway3";
    long_desc =
    "The forest is dark- very dark...light has trouble entering...  \n"+
    "in fact it is as if you have entered night.  The trees are creepy\n"+
    "and seem to move in the dim light. You try to go east or west but \n"+
    "the path stops you. The path grows darker....\n";
  items = ({
    "south","The path returns to the main forest",
    "northwest","The path turns to the west...",
  });

  dest_dir = ({
    "/players/mythos/aroom/forest/pathway2.c", "south",
    "/players/mythos/aroom/forest/pathway4.c","northwest",
  });
} }
