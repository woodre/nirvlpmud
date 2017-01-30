inherit "room/room";
#include "definitions.h"


reset(arg)
{
  if (!present("wytch"))
    move_object(clone_object(CASTLEMONSTER+"/wytch.c"), this_object());

  if(!arg)
  {
    set_light(1);
    short_desc="Swamp thickets";
    long_desc=
"     You weave your way through the thick unrelenting thickets\n"+
"and deep water pools of the swamp. Tiny insects bite at your neck.\n"+
"Leaches suck at your feet from underneath the water surface.\n";

    dest_dir=({
CASTLEROOM+"/sroad3.c","east",
    });

    items=({
"thickets","     Thorny thickets itch at your side",
"pools",   "     You constantly have to step in semi-shallow pools", 
"insects", "     The insects are too tiny to see in the dim light",
    });
  }
}
