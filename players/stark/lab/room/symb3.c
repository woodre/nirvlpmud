inherit "room/room";
reset(arg) {
  if (arg) return;
  set_light(0);
  short_desc="Dark Cavern";
  long_desc=
"   You are in a cramped dark cavern.  There is an opening to the east.  \n"+
"There is a slick black liquid that covers and coats the entire cave.  \n"+
"The black matter seems to pulse like a beating heart.  The liquid \n"+
"drips down slowly to the floor.\n";

  items=({
  });

  dest_dir=({
    "/players/stark/lab/room/symb2","south",
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

