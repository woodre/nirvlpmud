inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("Stone wall");
  long_desc=
    "There is a stone wall to the north covered with vines and\n"+
    "hidden by bushes. The corner is to the east and turns\n"+
    "heading north. There is no entrance on this side of the\n"+
    "stone structure.\n";
  dest_dir=
    ({
      "/players/bagera/jungle/room60a.c", "north",
      "/players/bagera/jungle/room59.c", "west",
      "/players/bagera/jungle/room68.c", "south"
   });
 }
