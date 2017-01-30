inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("A cave");
  long_desc=
    "It is darker here. Yu can barely make out shapes or see\n"+
    "the walls of the cave. You see many pairs of glowing eyes\n"+
    "to the south. You also hear wimpering and yelping coming\n"+
    "from that direction.\n";
  dest_dir=
  ({
   "/players/bagera/jungle/cave1.c", "north",
   "/players/bagera/jungle/cave3.c", "south"
    });
  }
