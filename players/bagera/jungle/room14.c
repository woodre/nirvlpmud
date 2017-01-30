inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("The jungle");
  long_desc=
    "Trees surround you. Everywhere you look there are trees,\n"+
    "trees, and more trees.\n";
  dest_dir=
    ({
      "/players/bagera/jungle/room15.c", "east",
      "/players/bagera/jungle/room13.c", "west",
      "/players/bagera/jungle/room22.c", "south",
      "/players/bagera/jungle/room6.c", "north"
   });
  }
