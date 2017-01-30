#include "/players/balowski/lib.h"
inherit PORTHEAL;

void
create()
{
    ::create();
    set_name("snapple");
    set_charge_name("snapple", "snapple");
    set_verb("drink");
    set_short("Bottle of Peach Ice Tea Snapple");
    set_long("A bottle of Peach Ice Tea Snapple that looks refreshing.\n");
    set_messages("You take a big swig of snapple.\n",
		" takes a big swig of snapple.\n");
    /*write("You finish the bottle.\n");*/
    set_charges(3);
    set_quench(20);
    set_heal(7);
}
