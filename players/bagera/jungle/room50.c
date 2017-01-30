inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("Stone wall");
  long_desc=
    "A stone wall is visible to the east. It runs north\n"+
    "and south. You can see the corner of the structure\n"+
    "to the south.  The jungle clears to the west, looking\n"+
    "barren and desolate.\n";
  dest_dir=
    ({
      "/players/bagera/jungle/room59a.c", "south",
      "/players/bagera/jungle/room42.c", "north",
      "/players/bagera/jungle/room49.c", "west",
      "/players/bagera/jungle/room41.c", "northwest"
  });
 }
