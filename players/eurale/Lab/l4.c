#include "DEFS.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "Labyrinth";
long_desc =
  "  This small, dark cave angles slightly down to the west.  The rough\n"+
  "walls and ceiling make for treacherous traveling.  Because of the\n"+
  "narrow diameter here, you must walk stooped over making your back\n"+
  "ache.  The coolness here also seems to have an uncommon freshness\n"+
  "that seems out of place so far underground.\n";

items = ({
  "walls","Chipped out of rock with a pickaxe by the looks of it",
  "ceiling","Pointed pieces of rock sticking down near your head",
});

dest_dir = ({
  "players/eurale/Lab/l3.c","east",
  "players/eurale/Lab/l5.c","west",
});

}

realm() { return "NT"; }
