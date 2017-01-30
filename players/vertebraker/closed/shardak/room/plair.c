#pragma strict_types
#include "/players/balowski/lib.h"
#include "../def.h"
#include "../tasks.h"

inherit ROOM;

void
create()
{
    ::create();
    set_short("The pyromancer's lair");
    set_long("\
You stand in a warmer section of the cave.  Heat\n\
rises and swirls around you, permeating the area\n\
with an intensity that you have not seen before.  A\n\
stone dragon's head extends from the southern side\n\
of the cavern, spewing hot lava beneath the rock.\n");
    set_exits( ([
        "north" : (PATH + "descent"),
    ]) );
    set_items( ([
        ({ "cave", "cavern" }) : "\
The cave leads back up in a northward area to the\n\
main section of the grotto.\n",
        "heat" : "\
The thick steam rises all around you, pounding into\n\
your pores...\n",
        ({ "dragon's head", "head" }) : "\
The stone dragon's head pumps a porous dark red lava\n\
into a thick obsidian dish, where it seems to disappear.\n",
        ({ "obsidian dish", "dish" }) : "\
The black obsidian dish appears to some sort of portal\n\
to another world.. or dimension.\n",
        ({ "hot lava", "lava" }) : "\
Burning hotly, the lava flows effortlessly through the\n\
stone dragon head to the dish, where it dissolves into\n\
nothingness.  It is pouring out of the wall with no end\n\
in sight, apparently.\n", 
       ]) );

    set_light(2);
    set_property("fight area", 1);
    set_property("no teleport", 1);
}

void
reset(int arg)
{
    ::reset(arg);
    if (!present("pyromancer", this_object()))
      move_object(clone_object(PATH + "pyromancer"), this_object());
}
