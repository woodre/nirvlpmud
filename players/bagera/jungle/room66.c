inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("Desolate lands");
  long_desc=
    "The trees become barren the further west you travel.\n"+
    "The branches extend toward you like gnarled old claws. It\n"+
    "is dark and desolate at this end of the jungle.\n";
  dest_dir=
    ({
      "/players/bagera/jungle/room67.c" , "east",
      "/players/bagera/jungle/room65.c", "west",
      "/players/bagera/jungle/room58.c", "north"
   });
  }
