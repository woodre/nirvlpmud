#include "../def.h"

inherit POTION;

void
reset(int arg)
{
    if(arg) return;
    set_id("cyan potion");
    set_alias("potion");
    set_short("A " + CYN + "cyan" + NORM + " potion");
    set_long("\
A syrupy cyan liquid rolls around in this small bottle,\n\
probably enough for one good drink.  A cork stopper is\n\
sits in the top of the bottle.\n");
    set_value(400);
    set_weight(1);
}

void
potion_effect()
{
    object z, x;

    if((z = this_player()) && ((x = present("toxin", z)) ||
        (x = present("poison", z)) || (x = present("toxin2", z))
        || (x = present("virus", z)) || (x = present("hcl", z))
        || (x = present("scorptox", z))))
    {
      write(CYN + "\
You feel as though some affliction has been lifted.\n" + NORM);
      destruct(x);
      return;
    }
}
