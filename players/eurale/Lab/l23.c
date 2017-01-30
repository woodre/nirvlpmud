#include "DEFS.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("couatl")) {
  move_object(clone_object("/players/eurale/Lab/NPC/couatl.c"),TO); }
set_light(0);

short_desc = "Labyrinth";
long_desc =
  "  A very narrow ledge with jagged edged up above the fissure floor.\n"+
  "A small indentation in the rock provides just enough room for a\n"+
  "relatively small animal.  The rock walls ascend straight up from\n"+
  "here making it impossible to climb higher.\n";

items = ({
  "ledge","Relatively flat surface about a foot wide with fluffy\n"+
          "feathers scattered about",
  "floor","A dark surface quite some distance below",
  "indentation","A natural hollow where it appears a large chunk of\n"+
                "rock broke away long ago",
  "walls","Rough and straight up limiting visibility",
});

dest_dir = ({
  "players/eurale/Lab/l22.c","down",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("Search","search");
}

Search(str) {
if(!str) { write("What?\n"); return 1; }
write("You search the "+str+" but find nothing of interest.\n");
return 1;
}
