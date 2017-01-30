inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("The stone wall");
  long_desc=
    "This is the east side of the stone wall. There\n"+
    "are huge wooden doors here. They are cracked just enough\n"+
    "for you to go through. The doors are hanging crooked off\n"+
    "the hinges.\n";
  dest_dir=
   ({
      "/players/bagera/jungle/room37a.c", "north",
      "/players/bagera/jungle/room46.c", "east",
      "/players/bagera/jungle/room44.c", "west",
      "/players/bagera/jungle/room53.c", "south"
   });
  }
