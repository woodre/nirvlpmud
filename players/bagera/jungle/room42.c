inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("Stone wall");
  long_desc=
    "You see a stone wall to the east covered with vines\n"+
    "and hidden behind tall shubbery. Some of the old wall\n"+
    "is still visible. To the west the jungle thins out. Off in\n"+
    "the distance you can see the trees growing bare.\n";
  dest_dir=
 ({
      "/players/bagera/jungle/room34a.c", "north",
      "/players/bagera/jungle/room41.c", "west",
      "/players/bagera/jungle/room50.c", "south",
      "/players/bagera/jungle/room49.c", "southwest"
   });
}
