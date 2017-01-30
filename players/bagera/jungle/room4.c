inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("The bottom of a ravine");
  long_desc=
      "You are walking along the bottom of a deep ravine.\n"+
      "It slopes sharply upwards to the north and a thick\n"+
      "jungle lies to the south. The ravine stretches east\n"+
      "and west.\n";
  dest_dir=
    ({
      "/players/bagera/jungle/room3.c", "west",
      "/players/bagera/jungle/room5.c", "east",
      "/players/bagera/jungle/room12.c", "south"
   });
  }
