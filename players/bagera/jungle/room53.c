inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("Stone wall");
  long_desc=
    "This is the east side of the stone structure, which\n"+    
    "which continues north and south. There is a door further\n"+
    "north along the wall. The jungle extends all around you.\n"+
    "There seems to be no end to all the trees.\n";
  dest_dir=
    ({
      "/players/bagera/jungle/room45.c", "north",
      "/players/bagera/jungle/room60a.c", "south",
      "/players/bagera/jungle/room54.c", "east"
    });
 }
