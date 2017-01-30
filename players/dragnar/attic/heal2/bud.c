#include "/players/balowski/lib.h"
inherit PORTHEAL;

void
create()
{
    ::create();
    set_name("12 pack");
    set_charge_name("can", "cans");
    set_verb("drink");
    set_short("A 12 pack of Bud");
    set_long("A 12 pack of Bud.\n");
    set_messages("You feel the healing power in the beer as soon as you drink it.\n",
		" slams a can of bud.\n");
    /*set_empty_message("You finish off the last can of bud.\n");*/
    set_charges(12);
    set_intox(12);
    set_heal(30);
}
