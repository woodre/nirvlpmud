inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "SW Guard Tower";
long_desc =
"   In the dim light of the narrow slat type windows, the tower's\n"+
"main room looks smaller than it really is.  A worn spiral stair-\n"+
"way of smooth stone circles upward through an open trap door in\n"+
"the rough wood-plank ceiling.  Straw covers the stone floor in\n"+
"places, and a table and two chairs sit in the far corner.\n";

items = ({
"door",    "Sturdy and solid plank, it is unbarred and open",
"room",    "The interior room of the guard tower",
"stairway","Built in a circular fashion to conserve space, it\n"+
           "winds upward through a trap door into darkness",
"ceiling", "Rough wooden planks over heavy beams",
"straw",   "The regualar straw used in stables and guard houses everywhere.\n"+
           "It seems to be piled rather high in the corner",
"floor",   "Stone worn smooth from the boots of countless guards",
"table",   "Just a wooden table. Nothing special",
"chairs",  "Four legged chairs with reed-cloth backing",
"corner",  "The straw has built up in the corner. Perhaps you should\n"+
           "search in the straw",
});

dest_dir = ({
   "/players/fakir/fcastle/room20.c", "out",
   "/players/fakir/fcastle/room22.c", "climb",
});
}


