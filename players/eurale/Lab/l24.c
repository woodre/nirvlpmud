#include "DEFS.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "Labyrinth";
long_desc =
  "  The large fissure ends here at a wall of solid rock.  Large pieces\n"+
  "have broken away and litter the area.  Huge roots from trees growing\n"+
  "up above dangle like giant tentacles.  A large, dead piece, surely\n"+
  "petrified, angles between two walls casting deep shadows in the dim\n"+
  "light.\n";

items = ({
  "wall","Rough and nearly verticle, it seems to have a maze of cracks\n"+
         "that run through it every which way",
  "cracks","Some large, some small, all heading in different directions",
  "pieces","Large sections of rock broken away from the walls",
  "roots","Dangling roots, covered with dirt, almost like you could\n"+
          "climb them like a rope",
  "piece","A petrified piece of tree root that still shows bark-like\n"+
          "roughness even though it's hard as stone",
  "shadows","The darkness nearly hides a small hole that you might be\n"+
            "able to squeeze into",
  "light","Small shafts of light coming through holes up above",
});

dest_dir = ({
  "players/eurale/Lab/l22.c","east",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("Search","search");
  add_action("Climb","climb");
  add_action("Squeeze","squeeze");
}

Search(str) {
if(!str) { write("What?\n"); return 1; }
if(str == "cracks") {
  write("You search the larger cracks and find one you might just\n"+
        "be able to get into if you squeeze.\n");
  return 1; }
write("You search the "+str+" but find nothing of interest.\n");
return 1;
}

Climb(str) {
if(!str) { write("What?\n"); return 1; }
if(str == "root" || str == "roots") {
  write("You jump and grab the root and begin to climb..\n\n"+
        "Just when you think you're almost out, you run into a "+
        "dead end....\n\n\n");
  TP->move_player("up#players/eurale/Lab/l25.c");
  return 1; }
}

Squeeze(str) {
if(!str) { write("What?\n"); return 1; }
if(str == "hole") {
  write("You squeeze into the small dark hole....\n");
  TP->move_player("into the shadows#players/eurale/Lab/l26.c");
  return 1; }
if(str == "crack") {
  write("You turn sideways and squeeze into the narrow crack...\n");
  TP->move_player("into the shadows#players/eurale/Lab/l27.c");
  return 1; }
}
