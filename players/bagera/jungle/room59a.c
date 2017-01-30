inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("Stone wall");
  long_desc=
    "This is the southwest corner of the large stone structure.\n"+
    "The jungle stretches beyond as far as the eye can see.\n";
  dest_dir=
    ({
      "/players/bagera/jungle/room59.c", "east",
      "/players/bagera/jungle/room50.c", "north",
      "/players/bagera/jungle/room58.c", "southwest"
  });
 }
