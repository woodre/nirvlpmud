inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("Desolate land");
  long_desc=
    "The trees grow thin here. The green fades to a darker\n"+
    "color, more black and burnt looking. These trees are\n"+
    "also smaller and scrawnier looking then the ones deeper\n"+
    "in the jungle. It is even more desolate and barren to the\n"+
    "south.\n";
  dest_dir=
    ({
      "/players/bagera/jungle/room57.c", "south",
      "/players/bagera/jungle/room50.c", "east",
      "/players/bagera/jungle/room58.c", "southeast",
      "/players/bagera/jungle/room41.c", "north",
      "/players/bagera/jungle/room42.c", "northeast"
   });
  }
