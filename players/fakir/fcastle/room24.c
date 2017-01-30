inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "NW Guard Tower";
long_desc =
"   In the dim light of the open door, the room looks messy\n"+
"and unkept.  A table is covered in dirty plates and trays,\n"+
"and several mice are dining on some moldy food spilled on\n"+
"the floor.  A spiral stairway circles upward through an open\n"+
"trap door in the rough wood ceiling.\n";

items = ({
"door",    "Sturdy and solid plank, it is unbarred and open",
"room",    "The interior room of the guard tower",
"stairway","Built in a circular fashion to conserve space, it\n"+
           "winds upward through a trap door into darkness",
"ceiling", "Rough wooden planks over heavy beams",
"straw",   "The regualar straw used in stables and guard houses everywhere",
"floor",   "Stone worn smooth from the boots of countless guards",
"table",   "Just a wooden table covered in old greasy plates and trays",
"plates",  "Pewter plates from the castle kitchen, covered in gravy",
"trays",   "Wooden trays from the castle kitchen",
"mice",    "Small grey mice with big ears and long tails",
"food",    "Bones, stale moldy bread, and half eaten bits of fruit",
});

dest_dir = ({
   "/players/fakir/fcastle/room23.c", "out",
   "/players/fakir/fcastle/room25.c", "climb",
});
}


