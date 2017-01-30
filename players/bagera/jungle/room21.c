inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("The jungle");
  long_desc=
    "The trees are thick and green here. The branches are\n"+
    "full of green leaves, hanging vines, and vibrant with life.\n"+
    "The jungle floor is soft and full of exotic plant life.\n"+
    "The jungle stretches out all around, as far as the eye\n"+
    "can see. Everything looks the same. The trees\n"+
    "are identical and the light barely shines through.\n"+
    "You must beat your way through the underbrush to get where you\n"+
    "want to go.\n";
  dest_dir=
   ({
      "/players/bagera/jungle/room20.c", "west",
      "/players/bagera/jungle/room22.c", "east",
      "/players/bagera/jungle/room29.c", "south",
      "/players/bagera/jungle/room13.c", "north"
   });
  }
