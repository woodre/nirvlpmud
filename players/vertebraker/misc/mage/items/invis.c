#include "../def.h"

#define INVIS "/players/vertebraker/misc/mage/items/invis_call"

inherit POTION;

void
reset(int arg)
{
    if(arg) return;
    set_id("clear potion");
    set_alias("potion");
    set_short("A clear potion");
    set_long("\
A bottle containing some sort of clear liquid.  There is a\n\
brown cork on top.  It is unlabeled.\n");
    set_value(400);
    set_weight(1);
}

void
potion_effect()
{
    object z;

    if(present("verte_invis_thing", (z = this_player())))
      return;
    if(present("implants", z)) {
     write("CyberNinjas may not use this item.\n");
     return;
    }
    write("Something changes...\n\
You feel yourself fading from your surroundings.\n");
    z->set_invs_sp();
    move_object(clone_object(INVIS), z);
}
