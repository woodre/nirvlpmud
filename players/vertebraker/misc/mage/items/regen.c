#include "../def.h"

#define HPHEAL "/players/vertebraker/misc/mage/items/hp_regen"

inherit POTION;

void
reset(int arg)
{
    if(arg) return;
    set_id("green potion");
    set_alias("potion");
    set_short("A " + GRN + "green" + NORM + " potion");
    set_long("\
A potion containing some kind of green liquid.\n\
A label on the front contains a picture of a vigorous fist.\n");
    set_value(500);
    set_weight(1);
}

void
potion_effect()
{
    object x;

    if(present("verte_hp_regen", (x = environment())))
      return;

    move_object(clone_object(HPHEAL), x);
    write("Your wounds seem to close faster.\n");
}
