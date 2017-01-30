#include "DEFS.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("smilodon")) {
  move_object(clone_object("/players/eurale/Lab/NPC/smilodon.c"),TO); }
set_light(0);

short_desc = "Labyrinth";
long_desc =
  "  This small cave has been dug by something very powerful.  The deep\n"+
  "gouges left by sturdy claws can still be seen in the walls.  Though\n"+
  "not deep, the opening is far enough from the back to provide safety\n"+
  "and protection.\n";

items = ({
  "cave","A roundish cut through the sandstone",
  "gouges","Deep and irregular but hard to tell if they are new or old",
  "opening","A circular light leading out",
});

dest_dir = ({
  "players/eurale/Lab/l12.c","out",
});

}

realm() { return "NT"; }
