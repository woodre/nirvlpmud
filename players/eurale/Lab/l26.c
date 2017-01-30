#include "DEFS.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("margoyle")) {
  move_object(clone_object("/players/eurale/Lab/NPC/margoyle.c"),TO); }
set_light(0);

short_desc = "Labyrinth";
long_desc =
  "  This hole in the rock was made by something very powerful.  Deep\n"+
  "lines in every surface indicate something dug this hole.  Pieces\n"+
  "of fur line the deepest part of the hole.\n";

items = ({
  "lines","Close examination leads you to believe that they are\n"+
          "actually claw marks",
  "fur","Animal fur of some kind, matted down into a mattress",
  "pieces","Animal fur pushed into a mattress for sleeping",
});

dest_dir = ({
  "players/eurale/Lab/l24.c","out",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("Search","search");
}

Search(str) {
if(!str) { write("What?\n"); return 1; }
if(str == "hole" && present("margoyle")) {
  write("You carefully feel along the hole surfaces....\n\n"+
        "and then you STOP..... something is there, against the\n"+
        "back wall and it seems to be breathing.\n");
  return 1; }
if(str == "back wall" && present("margoyle")) {
  write("You gently feel along the back wall.... THERE IT IS!!\n\n"+
        "It feels like the outline of a margoyle.....\n\n"+
        "but aren't they extinct?\n");
  return 1; }
write("You search the "+str+" but find nothing of interest.\n");
return 1;
}
