inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/mmon/bustle2.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "<<The Quad- Andrew's Room>> ";
    long_desc =
    "\n";
  items = ({
    "common","",
  });

  dest_dir = ({
    "/players/mythos/mroom/quad1.c", "common",
  });
} }
