inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("Deep jungle");
  long_desc=
    "This is the deep jungle. The sky is blotted out from the\n"+
    "trees. The dirt is moist and soft, You must venture to exit.\n";
  dest_dir=
    ({
      "/players/bagera/jungle/room61.c", "west",
      "/players/bagera/jungle/room63.c", "east",
      "/players/bagera/jungle/room70.c", "south",
      "/players/bagera/jungle/room54.c", "north"
    });
  }
