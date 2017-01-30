inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("The jungle");
  long_desc=
    "The trees are dense here. They loom overhead and spread\n"+
    "every which way.\n";
  dest_dir=
    ({
      "/players/bagera/jungle/room32.c", "north",
      "/players/bagera/jungle/room48.c", "south",
      "/players/bagera/jungle/room39.c", "west"
    });
  }
