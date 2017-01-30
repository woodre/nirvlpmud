inherit "room/room";
#include "definitions.h"


void init()
{
  command("gasp", TP);
  ::init();
}


reset(arg)
{

  if (!present("lord"))
    move_object(clone_object(CASTLEMONSTER+"/soultephar_lord.c"), this_object());

  if(!arg)
  {
    set_light(1);
    short_desc=("Chamber of the Sithi Lord");
    long_desc=
"       In the place of stone walls, a waterfall of liquid magma blasts upwards.\n"+
"The room trembles, as if the volcano were about to erupt. Everything around\n"+
"you moves, except for the chunk of obsidian that you stand upon.\n"+
"A stairway spirals down into the obsidian.\n";

    dest_dir=({
CASTLEROOM+"/archive.c","down"  ,
CASTLEROOM+"/treasurehall.c","west"  ,
    });

    items=({
"waterfall","     The magma flows upwards every direction above you",
"obsidian", "     The obsidian island seems to float in the magma",
"stairway", "     It leads to a room inside the obsidian",
    });
  }
}
