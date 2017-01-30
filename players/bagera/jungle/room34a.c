inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("Stone wall");
  long_desc=
    "This isthe northwest corner of the stone structure.\n"+
    "Vines cling onto the wall, crawling up the side and bushes\n"+
    "cover the base. To the northwest you see a heard of animals\n"+
    "You must get a closer look to distinguish the kind of\n"+
    "animals they are. The wall continues to the west.\n";
  dest_dir=
  ({
      "/players/bagera/jungle/room35.c", "east",
      "/players/bagera/jungle/room34.c", "northwest",
      "/players/bagera/jungle/room42.c", "south"
   });
  }
