inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("Deep jungle");
  long_desc=
    "This is the deep jungle. The sky is blotted out from the\n"+
    "trees. The dirt is moist and soft. You must go through the jungle.\n";
  dest_dir=
    ({
      "/players/bagera/jungle/room45.c", "west",
      "/players/bagera/jungle/room47.c", "east",
      "/players/bagera/jungle/room38.c", "north",
      "/players/bagera/jungle/room54.c", "south"
    });
  }
