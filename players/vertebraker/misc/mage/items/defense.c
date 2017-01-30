#include "../def.h"

#define DEFEND "/players/vertebraker/misc/mage/items/defend_call"

inherit POTION;

void
reset(int arg)
{
    if(arg) return;
    set_id("magenta potion");
    set_alias("potion");
    set_short("A " + HIM + "magenta" + NORM + " potion");
    set_long("\
This potion bubbles with a strange magenta liquid.  A\n\
white label on the front of the bottle has the picture\n\
of a shield on it.  A cork sticks out of the top of the\n\
glass bottle.\n");
    set_value(500);
    set_weight(1);
}

void
potion_effect()
{
    object z;

    if(present("verte_defend_thing", (z = this_player())))
      return;
    write(BOLD + "You feel protected by some unknown force.\n" + NORM);
    move_object(clone_object(DEFEND), z);
}
