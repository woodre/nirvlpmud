inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("The jungle");
  long_desc=
    "This is the edge of the jungle. You can see only\n"+
    "an abyss towards the south. Tothe west the jungle\n"+
    "thins and becomes barren. To the east and north the\n"+
    "jungle grows thick.\n";
  dest_dir=
    ({
      "/players/bagera/jungle/room70.c", "west",
      "/players/bagera/jungle/room72.c", "east",
      "/players/bagera/jungle/room63.c", "north"
    });
 }
