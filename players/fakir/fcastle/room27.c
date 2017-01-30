inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "NE Guard Tower";
long_desc =
"   In the dim light of the open door, the room looks larger\n"+
"than it really is.  A spiral stairway circles upward through\n"+
"an open trap door in the rough wood ceiling.  Straw covers\n"+
"the stone floor in places, and a table and two chairs sit in\n"+
"the far corner.\n";

items = ({
"door",    "Sturdy and solid plank, it is unbarred and open",
"room",    "The interior room of the guard tower",
"stairway","Built in a circular fashion to conserve space, it\n"+
           "winds upward through a trap door into darkness",
"ceiling", "Rough wooden planks over heavy beams",
"straw",   "The regualar straw used in stables and guard houses everywhere",
"floor",   "Stone worn smooth from the boots of countless guards",
"table",   "Just a wooden table. Nothing special",
"chairs",  "Four legged chairs with cloth backing",
"corner",  "The straw has built up in the corner. Perhaps you should\n"+
           "search in the straw",
});

dest_dir = ({
   "/players/fakir/fcastle/room26.c", "out",
   "/players/fakir/fcastle/room28.c", "climb",
});
}


