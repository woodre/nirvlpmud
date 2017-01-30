inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("Desolate land");
  long_desc=
    "The trees are increasingly barren here. They\n"+
    "also grow smaller and are less healthier looking. The\n"+
    "branches are limp and the leaves are wilting. The dirt\n"+
    "is dry and cracked like a desert floor. It's next to\n"+
    "impossible for anything to grow here.\n";
  dest_dir=
    ({
      "/players/bagera/jungle/room66.c", "west",
      "/players/bagera/jungle/room59.c", "north",
      "/players/bagera/jungle/room68.c", "east"
    });
  }
