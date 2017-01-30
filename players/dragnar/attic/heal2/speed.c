#include "/players/balowski/lib.h"
inherit PORTHEAL;

void
create()
{
    ::create();
    set_name("pack");
    set_charge_name("pill", "pills");
    set_verb("eat");
    set_short("A pack of speed pills");
    set_long("A pack of 10 speed pills.  They look like they would make you very hungry.\n");
    set_messages("The speed makes you feel hungry again.\n",
		" pops a speed pill.\n");
    /*write("You use up the last of your pills.\n");*/
    set_charges(4);
    set_satiate(-7);
    set_heal(0);
}
