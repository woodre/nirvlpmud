/* typo layed = laid fixed by Vertebraker [5.23.01] */
#include "DEFS.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("troglodyte")) {
  move_object(clone_object("/players/eurale/Lab/NPC/troglodyte.c"),TO); }
set_light(0);

short_desc = "Labyrinth";
long_desc =
  "  The tunnel dead ends here.  The density of the surrounding grey\n"+
  "rock makes passage this way impossible.  Pieces of rock still litter\n"+
  "the floor, left over from a time when workers filled the passage.\n";

items = ({
  "rock","Solid stone, laid from centuries of formation",
  "pieces","Small chips from the surrounding walls",
});

dest_dir = ({
  "players/eurale/Lab/l7.c","north",
});

}

realm() { return "NT"; }
