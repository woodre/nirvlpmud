inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/mmon/bustle2.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "<<Another Place>> ";
    long_desc =
    "\n";
  items = ({
    "beyond","",
    "portal","",
    "enter","",
  });

  dest_dir = ({
    "/players/mythos/mroom/shinjuku.c", "beyond",
    "/players/mythos/enterance.c","portal",
    "/players/mythos/mroom/quad1.c","enter",
  });
} }
