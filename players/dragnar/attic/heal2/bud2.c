#include "/players/balowski/lib.h"
inherit PORTHEAL;

void
create()
{
    ::create();
    set_name("can");
    set_ids(({ "beer", "bud" }));
    set_charge_name("can", "cans");
    set_verb("drink");
    set_short("A can of Bud");
    set_long("A can of bud ice.  It looks very inviting.\n");
    set_messages("You feel the healing power in the beer as soon as you drink it.\n",
		" slams a can of bud.\n");
    /*set_empty_message("You crush the can and throw it on the ground.\n");*/
    set_charges(1);
    set_intox(12);
    set_heal(30);
}
