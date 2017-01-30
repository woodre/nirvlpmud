inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("A meadow");
  long_desc=
    "You make your way into a meadow. To the west in the,\n"+
    "middle of the field, yousee a herd of Rhinos eating lunch.\n";
  dest_dir=
     ({
      "/players/bagera/jungle/room26.c", "west",
      "/players/bagera/jungle/room28.c", "east",
      "/players/bagera/jungle/room35.c", "south",
      "/players/bagera/jungle/room19.c", "north"
    });
  }
