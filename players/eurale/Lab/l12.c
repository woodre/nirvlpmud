#include "DEFS.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "Labyrinth";
long_desc =
  "  A dark pool, apparently fed from some underground spring hugs the\n"+
  "western wall.  The sand underneath your feet is damp and packed\n"+
  "quite firmly like it had been wetted recently.  The sandstone has\n"+
  "been eroded away leaving about 15 feet of space above you.  The\n"+
  "slope leading up completly hides your way here.\n";

items = ({
  "pool","Dark and from the looks of it very deep as nothing can be\n"+
         "seen in its depths.  Your reflection stares back at you from\n"+
         "a glass-smooth surface and beckons you to dive in and enjoy\n"+
         "its liquid coolness",
  "wall","The western wall has layers of colored stone from the water\n"+
         "all the way up to the ceiling",
  "ceiling","The same sandstone rock, suspended do to the erosion here",
  "sand","Damp and hard, resisting even a boot print",
  "sandstone","As your eyes slowly survey the sandstone walls, you\n"+
              "notice a small hole about 7 feet from the ground on the\n"+
              "northern wall and a fairly large horizontal crack in the\n"+
              "southern wall with trickles of water coming from it",
  "slope","An irregular part of the sandstone surroundings that angles\n"+
          "upward to somewhere above",
  "hole","A small cavelike opening in the wall.  It is not a natural\n"+
         "part of the wall and it looks as though you  might be able\n"+
         "to climb into it",
  "crack","A crack in the sandstone about 15 feet long.  It looks to\n"+
          "to be wider in the center like someone or something might\n"+
          "enter it there",
});

dest_dir = ({
  "players/eurale/Lab/l10.c","up",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("climb","climb");
  add_action("dive","dive");
  add_action("enter","enter");
}

climb(str) {
if(!str) { write("Climb what?\n"); return 1; }
if(str == "hole" || str == "cave") {
  write("You find a good hand hold and climb up into the "+str+".\n");
  TP->move_player("climbing#players/eurale/Lab/l13.c");
  return 1; }
}

dive(str) {
if(!str) { write("Dive?\n"); return 1; }
if(str == "pool" || str == "water") {
  write("You take a breath and dive into the "+str+".\n");
  TP->move_player("into the pool#players/eurale/Lab/l15.c");
  return 1; }
}

enter(str) {
if(!str) { write("Enter?\n"); return 1; }
if(str == "crack") {
  write("You hoist yourself up and enter the crack.\n");
  TP->move_player("into the crack#players/eurale/Lab/l14.c");
  return 1; }
}
