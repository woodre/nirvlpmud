inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("A room of portals");
  long_desc=
    "This is a long hallway with many doors. Behind each door\n"+
    "is a portal to a disney movie. Unfortunately only one is\n"+
    "open at the moment, but is currently under renovation.\n"+
    "Keep checking for new doors to be opening in a theatre\n"+
    "near you!!\n";
  dest_dir=
    ({
      "room/forest4", "out",
      "/players/bagera/jungle/entrance1.c", "portal1"
  });
 }
