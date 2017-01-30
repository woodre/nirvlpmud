inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("Deep jungle");
  long_desc=
    "This is the deep jungle. The sky is blotted out from the\n"+
    "trees. The dirt is moist and soft, You must venture to exit.\n";
  dest_dir=
    ({
      "/players/bagera/jungle/room47.c", "south",
      "/players/bagera/jungle/room31.c", "north",
      "/players/bagera/jungle/room38.c", "west",
      "/players/bagera/jungle/room40.c", "east"
    });
  }
