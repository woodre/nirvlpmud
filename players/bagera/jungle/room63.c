inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("The jungle");
  long_desc=
    "The trees are dense here. They loom overhead and spread\n"+
    "every which way.\n";
  dest_dir=
    ({
      "/players/bagera/jungle/room62.c", "west",
      "/players/bagera/jungle/room64.c", "east",
      "/players/bagera/jungle/room55.c", "north",
      "/players/bagera/jungle/room71.c", "south"
    });
  }
