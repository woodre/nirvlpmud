inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("A small clearing");
  long_desc=
    "There is a small clearing in the trees here. Slightly\n"+
    "camoflauged by bushes and underbrush around the edges\n"+
    "but somewhat visible is a small cave or den.\n";
  dest_dir=
    ({
      "/players/bagera/jungle/cave1.c", "enter",
      "/players/bagera/jungle/room9.c", "north",
      "/players/bagera/jungle/room18.c", "east",
      "/players/bagera/jungle/room25.c", "south"
    });
  }
