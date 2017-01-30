inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/amon/messenger.c"),this_object()); }
  if(!present("egg")) {
    move_object(clone_object("/players/mythos/amisc/egg.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "Rice Paddy";
    long_desc =
    "You enter the rice paddy.  Here is where the people produce their\n"+
    "daily food- rice. The rice is planted in a small area where it is marsh\n"+
    "like and well tended. You can enter the forest, go to the main path, or \n"+
    "continue in the rice.\n";
  items = ({
    "south","You see the dry path above",
    "forest","The dark forest.  Enter it with care",
    "east","The rice patties continue",
    "west","The rice patties continue",
  });

  dest_dir = ({
    "/players/mythos/aroom/path2.c", "south",
    "/players/mythos/aroom/rice2.c","west",
    "/players/mythos/aroom/forest/forest.c","forest",
    "/players/mythos/aroom/ricev.c","east",
  });
} }
