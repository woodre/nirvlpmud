inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/amon/messenger.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "Village Path2";
    long_desc =
    "You stand on the path that cuts through the village\n"+
    "As you trod on it, you see the shops and buildings of\n"+
    "of the village.  South is the pet shop.\n";
  items = ({
    "south","You see a pet shop",
    "west","You see the Shrine and Smithy",
  });

  dest_dir = ({
    "/players/mythos/aroom/petshop.c","south",
    "/players/mythos/aroom/vil1.c","west",
  });
} }
