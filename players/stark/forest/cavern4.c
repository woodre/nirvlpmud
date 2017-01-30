inherit "room/room";
reset(arg) {
  if(!present("neiz")) {
   move_object(clone_object("/players/stark/forest/mon/neiz.c"),this_object());
  }
  if (arg) return;
  set_light(1);
  short_desc="Cavern";
  long_desc=
"   Many paths in life end abruptly; this is one of those paths.  All \n"+
"sides of the cavern sink into one wall.  The cragged and crumbling \n"+
"rocks along the floor are evidence that the axes are winning the \n"+
"battle.  As a last defense, the stone has created a high content of \n"+
"dust in the area.\n";

  items=({
"path",
"This current tunnel into the rock ends here",
"paths",
"Some times the road less traveled by ends with a chunk of rock in your face",
"sides",
"The walls slide together into one wall that is being chipped away at",
"cavern",
"The cavern opens up westward and ends abruptly to the east",
"wall",
"The main focus point for many beatings and attacks",
"tunnel",
"This tunnel is an offshoot from the tree of caverns",
"rock",
"Busted rock of all sizes is scattered about the floor",
"floor",
"The lower curvature of the tunnel is filled with broken rock",
"stone",
"Matter that fights against the will of the pick axes, trying to stay solid",
"dust",
"Saturating the area, hindering any large organism that needs air to live"
  });

  dest_dir=({
    "/players/stark/forest/cavern3","west"
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

