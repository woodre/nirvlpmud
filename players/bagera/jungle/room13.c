inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("The jungle");
  long_desc=
    "Deeper into the jungle the light fades. The air is\n"+
    "moist and the smell of green plants and trees are strong. \n"+
    "The smell wafts up into your nostrils filling them\n"+
    "with a delightful smell.\n";
  dest_dir=
     ({
      "/players/bagera/jungle/room14.c", "east",
      "/players/bagera/jungle/room12.c", "west",
      "/players/bagera/jungle/room21.c", "south",
      "/players/bagera/jungle/room5.c", "north"
    });
  }
