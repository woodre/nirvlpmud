inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("The jungle");
  long_desc=
    "The trees stand tall and noble. The trunks\n"+
      "measuring at least four feet in diameter.\n"+
      "Moss grows thick along the north side of\n"+
      "the trees.  The path is covered with thick\n"+
      "underbrush. You can see the sun peek through\n"+
      "the thinning trees.\n";
  dest_dir=
   ({
      "/players/bagera/jungle/room27.c", "west",
      "/players/bagera/jungle/room29.c", "east",
      "/players/bagera/jungle/room20.c", "north",
      "/players/bagera/jungle/room28.c", "south"
  });
}
