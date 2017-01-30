inherit "room/room";
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="Desert Oasis";
  long_desc=
"   A small pool of water is shaded by palm trees that feed of it.  \n"+
"Desert sands spread out in all directions.  Small gusts of wind brush \n"+
"sand again the floor.  Off to the north, dunes of piled sand are \n"+
"formed.  By the side of the oasis stands a metal door, untouched by \n"+
"the heat.\n";

  items=({
  });

  dest_dir=({
    "/players/stark/lab/room/derv2","north",
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

