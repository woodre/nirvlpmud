inherit "room/room";
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="Cavern";
  long_desc=
"  The natural cave ends at this point.  Smooth rock merges into \n"+
"cragged and scraped granite.  Chips from the digging process still \n"+
"litter the ground.  The ceiling droops down at times, evidence of \n"+
"stronger rock.\n";

  items=({
"cave",
"A natural cave births a dug out tunnel leading south",
"cave",
"Water and time have dug out a small cave",
"rock",
"Below dirt and soft clay lies hard rock",
"granite",
"Solid granite has been painstakingly carved into",
"chips",
"Scattered across the ground is chips making their journey into sand",
"ceiling",
"It would seem that time was granted higher priority over beauty"
  });

  dest_dir=({
    "/players/stark/forest/cave","north",
    "/players/stark/forest/cavern2","south"
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

