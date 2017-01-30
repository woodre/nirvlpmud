inherit "room/room";
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="Cave";
  long_desc=
"   Rock has long been carved by water into an open cave.  A single \n"+
"beam of light pinpoints the source of the water.  Water splashes down \n"+
"the wall and hits a cliff before making the final plunge.  The stream \n"+
"of water adds to a roaring river far below.  The cliff opens deeper \n"+
"into a tunnel.\n";

  items=({
"rock",
"Carved long ago by water, this solid rock has become a large cave",
"water",
"The water flows from a small opening to the east",
"wall",
"Water flows down the eastern wall",
"stream",
"A steady stream of water enters the cave",
"cliff",
"The water splashes against the edge of a cliff",
"cave",
"A cave opens up to the south"

  });

  dest_dir=({
    "/players/stark/forest/forest4","climb",
    "/players/stark/forest/cave","south"
  });
}   

init() {
  ::init();
  add_action("search","search");
}

search(str) {
  write("You briefly search about the cave and find nothing.\n");
  return 1;
}

