inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("The jungle");
  long_desc=
    "The jungle is a beautiful and exotic, as well as\n"+
    "dark and mysterious. The branches are thick and blot\n"+
    "out most of the sky. It's shady and cool underneath\n"+
    "the trees.\n";
  dest_dir=
    ({
      "/players/bagera/jungle/room13.c", "east",
      "/players/bagera/jungle/room11.c", "west",
      "/players/bagera/jungle/room20.c", "south",
      "/players/bagera/jungle/room4.c", "north"
  });
 }
