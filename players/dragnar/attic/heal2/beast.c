#include "/players/balowski/lib.h"
inherit PORTHEAL;

void
create()
{
    ::create();
    set_name("12 pack");
    set_charge_name("beast", "beasts");
    set_verb("drink");
    set_short("A 12 pack of beast");
    set_long("A case of Milwaukie's Best.\n");
    set_messages("The taste makes you feel sick, but stronger.\n",
		" chucks a can of beast.\n");
    set_charges(12);
    set_intox(14);
    set_heal(30);
}
