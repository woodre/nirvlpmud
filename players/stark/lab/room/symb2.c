inherit "room/room";
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="Rooftop";
  long_desc=
"   You stand at edge of the roof on a tall building.  The lights and \n"+
"movement of the city lay beneith you.  The dark night sky is all \n"+
"stands higher.  A shack with a small door is situated just north of \n"+
"you.  The roof is covered in tar and air vents.\n";

  items=({
  });

  dest_dir=({
    "/players/stark/lab/room/symb3","north",
    "/players/stark/lab/room/symb1","south",
  });
}

init() {
  ::init();
  add_action("search","search");
}

search(str) {
  write("Searchtastic\n");
  return 1;
}

