inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("The jungle");
  long_desc=
    "There are trees and bushes all around you. They\n"+
    "are endowed with Prickly Paw fruit. Over yonder you\n"+
    "hear a rustling and faint singing.\n";
  dest_dir=
   ({
      "/players/bagera/jungle/room12.c", "north",
      "/players/bagera/jungle/room21.c", "east",
      "/players/bagera/jungle/room19.c", "west",
      "/players/bagera/jungle/room28.c", "south"
   });
  }
