#include "DEFS.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("wight")) {
  move_object(clone_object("/players/eurale/Lab/NPC/wight.c"),TO); }
set_light(0);

short_desc = "Labyrinth";
long_desc =
  "  The small cave branches into the darkness in numerous directions\n"+
  "here.  The surrounding darkness seems a bit lighter to the south-\n"+
  "west.  Bones of some kind litter the cave floor here.\n";

items = ({
  "bones","They appear to be animal in origin but it's pretty dark to\n"+
          "be positive of that",
});

dest_dir = ({
  "players/eurale/Lab/l4.c","east",
  "players/eurale/Lab/l19.c","southwest",
  "players/eurale/Lab/l6.c","northwest",
});

}

realm() { return "NT"; }
