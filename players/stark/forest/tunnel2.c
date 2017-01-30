inherit "room/room";
reset(arg) {
  if(!present("irz")) {
   move_object(clone_object("/players/stark/forest/mon/irz.c"),this_object());
  }
  if(!present("wahz")) {
   move_object(clone_object("/players/stark/forest/mon/wahz.c"),this_object());
  }
  if (arg) return;
  set_light(1);
  short_desc="Black Tunnel";
  long_desc=
"   Liquid like black stone encases the smooth cylinder of this \n"+
"tunnel.  Towards the north, it curves and banks to a slow climb.  \n"+
"Blood red slabs of stone cut the tunnel from going any further south.  \n"+
"The four slabs center around a wooden door.  There is a carving at the \n"+
"center of the door.\n";

  items=({
"rock",
"Black rock is polished to a shine",
"material",
"Darker than onyx, this smooth black rock leads downward",
"tunnel",
"No evidence of digging or boring can be seen in this solid tunnel",
"stone",
"This stone is like no other, black as night and smooth as a newborn",
"cylinder",
"The descent is as straight as a cylinder until the very bottom",
"slabs",
"Red as blood and a meter thick, these encapsulate the door",
"door",
"A simple wooden door with a carving",
"carving",
"A serpant coils as it slithers out of flames"
  });

  dest_dir=({
    "/players/stark/forest/tunnel1","north",
    "/players/stark/forest/tunnel3","south"
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

