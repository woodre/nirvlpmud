inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("Desolate land");
  long_desc=
    "The trees become barren the further you travel. The sky\n"+
    "darkens and storm clouds move in swiftly, blocking out any\n"+
    "and all source of daylight. This place gives you the creeps.\n";
  dest_dir=
    ({
      "/players/bagera/jungle/room57.c", "west",
      "/players/bagera/jungle/room49.c", "northwest",
      "/players/bagera/jungle/room59a.c", "northeast",
     "/players/bagera/jungle/room66.c", "south",
       "/players/bagera/jungle/room65.c", "southwest"
  });
 }
