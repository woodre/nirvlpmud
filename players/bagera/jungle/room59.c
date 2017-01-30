
inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("Stone wall");
  long_desc=
    "There is a stone wall to the north covered with\n"+
    "vines and hidden partially behind bushes. The corner\n"+
    "to the west turns left heading north. There is no\n"+
    "entrance on the portion of the stone structure.\n";
  dest_dir=
    ({
      "/players/bagera/jungle/room59a.c", "west",
      "/players/bagera/jungle/room60.c", "east",
      "/players/bagera/jungle/room67.c", "south"
   });
 }
