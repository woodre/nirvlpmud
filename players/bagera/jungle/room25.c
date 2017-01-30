inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("A meadow");
  long_desc=
    "Youcome upon a field of grass, also known as a meadow,\n"+
    "lies in front of you. The grass ishigh and sways back\n"+
    "and forth gently with the cool breeze.\n";
  dest_dir=
    ({
      "/players/bagera/jungle/room17.c", "north",
      "/players/bagera/jungle/room26.c", "east",
      "/players/bagera/jungle/room33.c", "south"
    });
 }
