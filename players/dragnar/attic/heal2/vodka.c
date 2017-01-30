#include "/players/balowski/lib.h"
inherit PORTHEAL;

void
create()
{
    ::create();
    set_name("bottle");
    set_charge_name("shot", "shots");
    set_verb("drink");
    set_short("A bottle of vodka");
    set_long("A bottle of vodka.\n");
    set_messages("The vodka hurts the back of your throat.\n",
		" slams a shot of vodka.\n");
    /*("You smash the bottle on the ground as you finish the vodka.\n");*/
    set_charges(6);
    set_intox(14);
    set_heal(15);
}
