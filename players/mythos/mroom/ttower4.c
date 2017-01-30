inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/mmon/bustle.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "<<Tokyo Tower- Fourth Floor>> ";
    long_desc =
    "                  Fouth Floor <Tokyo Tower>\n"+
    "A large patio stretches before you. High above the rest of the\n"+
    "tower stretches- the observation areas.  Here you may wish to\n"+
    "just take a stroll....\n";
  items = ({
    "up","Up and up....",
    "down","Down and down....",
  });

  dest_dir = ({
    "/players/mythos/mroom/ttower3.c","down",
    "/players/mythos/mroom/ttower5.c","up",
  });
} }
