inherit "room/room";
reset(arg) {
  if(!present("denaiz")) {
   move_object(clone_object("/players/stark/forest/mon/denaiz.c"),this_object());
  }
  if (arg) return;
  set_light(1);
  short_desc="Cave";
  long_desc=
"   The mouth of the cavern was created by natural means.  Water, \n"+
"pressure, time, gas, and maybe an earthquake were the contruction crew \n"+
"for this feat.  Rushing water can be heard to the north where the \n"+
"cavern opens up.  The tunnel continues southward.\n";

  items=({
"head",
"The cave starts from here in",
"tunnel",
"The natural tunnel runs south"
  });

  dest_dir=({
    "/players/stark/forest/water","north",
    "/players/stark/forest/cavern1","south"
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

