inherit "room/room";
reset(arg) {
  if(!present("derz")) {
   move_object(clone_object("/players/stark/forest/mon/derz.c"),this_object());
  }
  if (arg) return;
  set_light(1);
  short_desc="Cavern";
  long_desc=
"   Pebbles, rocks, and piled stones litter the ground.  The walls are \n"+
"cut roughly and show no signs of being worn down.  The ceiling is \n"+
"considerably lower than the dome to the west.  The air is ripe and \n"+
"saturated with dust.\n";

  items=({
"boulders",
"There are no boulders in this room",
"stones",
"Smaller versions of boulders, stones are rock that has been broken down",
"rocks",
"Smaller versions of stones, rocks are pieces of material known as rock",
"Pebbles",
"Very small pieces of rock, one is more likely to slip on these than kick them",
"dust",
"Very small boulders.  Pieces of rock so small then can float in the air when sifted",
"walls",
"Recently drafted from solid stone into the ranks of walls, they are still in need of refinement",
"ceiling",
"The ceiling lowers as the tunnel continues"
  });

  dest_dir=({
    "/players/stark/forest/cavern2","west",
    "/players/stark/forest/cavern4","east",
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

