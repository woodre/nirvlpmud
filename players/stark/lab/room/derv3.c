inherit "room/room";
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="Sandstorm";
  long_desc=
"   A Storm rages around you.  Sand, dust and rock are thrown up into \n"+
"the air.  Particles smash down into the ground, grinding away at all \n"+
"things.  You are now in the center of the storm.   All sides are near \n"+
"solid walls of dust and sand.\n";

  items=({
  });

  dest_dir=({
    "/players/stark/lab/room/derv2","south"
  });
}   

init() {
  ::init();
  add_action("search","search");
}

search(str) {
  write("You search the sands and find a metal door of interest.\n");
  return 1;
}

