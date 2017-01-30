inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("An old stone structure");
  long_desc=
    "You come upon a small break in the trees. A stone wall\n"+
    "is visible through the trees. Vines line the wall crawling\n"+
    "skyward, covering its surface and disappearing into the\n"+
    "cracks.\n";
  dest_dir=
    ({
      "/players/bagera/jungle/room36.c", "east",
      "/players/bagera/jungle/room34.c", "west",
      "/players/bagera/jungle/room27.c", "north"


});

 }
