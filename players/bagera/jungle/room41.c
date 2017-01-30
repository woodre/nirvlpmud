inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("Desolate land");
  long_desc=
    "The trees are thinner and smaller here in size. The dirt on the ground\n"+
    "is hard and packed tight and dry, making it difficult\n"+
    "for trees or grass to grow.\n";
  dest_dir=
    ({
      "/players/bagera/jungle/room49.c", "south",
      "/players/bagera/jungle/room33.c", "north",
      "/players/bagera/jungle/room42.c", "east",
      "/players/bagera/jungle/room50.c", "southeast"
    });
  }
