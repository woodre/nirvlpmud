inherit "room/room";
reset(arg) {
  set_light(1);
short_desc=("A Steep Ravine");
  long_desc=
  "You are at the bottom of a very steep ravine.  The ravine seems\n"+
 
  "impossible to climb but there are paths open in other directions.\n";
  dest_dir=
  ({
          "/players/bagera/jungle/r13.c", "south",
          "/players/bagera/jungle/r6.c", "east",
          "/players/bagera/jungle/r4.c", "west"
          "/players/bagera/jungle/r13.c", "south"
   });
  }
