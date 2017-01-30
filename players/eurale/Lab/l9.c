#include "DEFS.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("poisonous toad")) {
  move_object(clone_object("/players/eurale/Lab/NPC/ptoad.c"),TO); }
set_light(0);

short_desc = "Labyrinth";
long_desc =
  "  This narrow ledge looks down out of dark shadows on the cave below.\n"+
  "Small tufts of fur lay scattered about here and a few bones can\n"+
  "just be made out in the darkness.\n";

items = ({
  "ledge","A one foot wide ledge, left from pick axes",
  "cave","A small opening that disappears down into the dark",
  "tufts","Small bits of animal fur",
  "fur","Small bits of an animal's fur",
  "bones","The cleaned bones of something unfortunate",
});

dest_dir = ({
  "players/eurale/Lab/l7.c","down",
});

}

realm() { return "NT"; }
