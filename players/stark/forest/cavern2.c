inherit "room/room";
reset(arg) {
  if(!present("trasz")) {
   move_object(clone_object("/players/stark/forest/mon/trasz.c"),this_object());
  }
  if (arg) return;
  set_light(1);
  short_desc="Cavern";
  long_desc=
"   The ceiling domes up at this junction.  The jagged floor has been \n"+
"softened by paths in many directions.  The smooth stone of the south \n"+
"wall leads to a tunnel.  The other walls have a gritty and rough \n"+
"texture about them.  Interspersed slabs of granite leap out of the \n"+
"floor.\n";

  items=({
"ceiling",
"This nexus of tunnel paths was made extra large in case of later needs",
"junction",
"Two separate paths connect for ease of travel",
"floor",
"Seas of jagged rocks and sharp stones are parted by worn paths",
"paths",
"The four main polar directions are represented by connecting paths",
"stone",
"A black slick stone leads downward",
"tunnel",
"Downward and southward leads a tunnel of solid dark rock",
"walls",
"Carved from solid rock, these walls are not made to be admired",
"slabs",
"Too difficult to clear out, some chunks of stone were kept standing",
"granite",
"The material from which this cavern was dug from"
  });

  dest_dir=({
    "/players/stark/forest/cavern1","north",
    "/players/stark/forest/tunnel1","south",
    "/players/stark/forest/cavern3","east",
    "/players/stark/forest/cavern5","west"
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

