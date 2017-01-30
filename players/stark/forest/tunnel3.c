inherit "room/room";
int sithos;
reset(arg) {
  if(!present("gir")) {
   move_object(clone_object("/players/stark/forest/mon/gir.c"),this_object());
  }
  if(!present("skir")) {
   move_object(clone_object("/players/stark/forest/mon/skir.c"),this_object());
  }

  if (arg) return;
  set_light(1);
  short_desc="Temple of Sithos";
  long_desc=
"   The shiny black rock opens up to an exact cube.  To the north a \n"+
"charred wood door is set between four blood red slabs of stone.  At \n"+
"the dead center of a room lies a statue of a large snake.  Torches \n"+
"have been lit in a circle around the Idol.\n";

  items=({
"rock",
"Black rock so smooth and shiny it seems wet",
"stone",
"This stone is like no other, black as night and smooth as a newborn",
"slabs",
"Red as blood and a meter thick, these encapsulate the door",
"door",
"A door to the north that has been charred black",
"cube",
"The room has the perfect dimensions of a cube",
"room",
"The room has the perfect dimensions of a cube",
"torches",
"Torches encircle the shrined idol",
"statue",
"A black sculpture of a giant snake.  It is coiled and ready to spring.  it's eyes flicker from the flames lit within.   \nPerhaps you could 'pray' to it",
"idol",
"A black sculpture of a giant snake.  It is coiled and ready to spring.  it's eyes flicker from the flames lit within.   \nPerhaps you could 'pray' to it",
"carving",
"A serpant coils as it slithers out of flames"
  });

  dest_dir=({
    "/players/stark/forest/tunnel2","north",
  });
}   

init() {
  ::init();
  add_action("search","search");
  add_action("pray","pray");
}

search(str) {
  write("You briefly search about the cave and find nothing.\n");
  return 1;
}

pray(str){
 if(str == "to sithos" || str == "to Sithos"){

 if(sithos){
  write("You pray before Sithos and nothing happens.\n");
 return 1; }

 write("You pray before Sithos and he comes alive!\n");
 move_object(clone_object("/players/stark/forest/mon/sithos.c"),this_object());
 sithos = 1;
return 1;}

  write("Pray to what?\n");
 return 1; }



    