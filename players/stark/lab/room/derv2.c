inherit "room/room";
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="Desert Sands";
  long_desc=
"   The sand bakes whatever falls prey to it.  Dunes raise and fall as \n"+
"a churning ocean.  Waves of heat dance and rise with the wind.  \n"+
"Breezes pick up the small grains and push them around.  A solitary \n"+
"cactus stands tall as watch.  Far to the north, a raging sandstorm can \n"+
"be seen. \n";

  items=({
  });

  dest_dir=({
    "/players/stark/lab/room/derv3","north",
    "/players/stark/lab/room/derv1","south"
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

