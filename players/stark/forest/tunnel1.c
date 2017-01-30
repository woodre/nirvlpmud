inherit "room/room";
reset(arg) {
  if(!present("par")) {
   move_object(clone_object("/players/stark/forest/mon/par.c"),this_object());
  }
  if (arg) return;
  set_light(1);
  short_desc="Black Tunnel";
  long_desc=
"   Smooth polished rock descends slowly southward.  The slope is \n"+
"gradual enough to prevent slipping.  Material not unlike onyx creates \n"+
"a smooth and sheer tunnel.  There don't seem to be any cracks of any \n"+
"sort along the passage.\n";

  items=({
"rock",
"Black rock is polished to a shine",
"material",
"Darker than onyx, this smooth black rock leads downward",
"tunnel",
"No evidence of digging or boring can be seen in this solid tunnel",
"cracks",
"You don't see any cracks because there aren't any",
"passage",
"Deeper into the earth it goes",
  });

  dest_dir=({
    "/players/stark/forest/cavern2","north",
    "/players/stark/forest/tunnel2","south"
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

