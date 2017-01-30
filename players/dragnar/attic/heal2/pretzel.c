#include "/players/balowski/lib.h"
inherit PORTHEAL;

void
create()
{
    ::create();
    set_name("bag");
    set_charge_name("pretzels", "handfulls");
    set_verb("eat");
    set_short("A bag of pretzels");
    set_long("A bag of pretzels.  They look like they would make you thirsty.\n");
    set_messages("The pretzels makes you feel thristy again.\n",
		" munches a handful of pretzels.\n");
    /*write("You finish off the bag.\n");*/
    set_charges(4);
    set_quench(-7);
    set_heal(0);
}
