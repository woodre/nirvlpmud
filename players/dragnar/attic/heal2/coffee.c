#include "/players/balowski/lib.h"
inherit PORTHEAL;

void
create()
{
    ::create();
    set_name("thermos");
    set_charge_name("cup", "cups");
    set_verb("drink");
    set_short("A thermos of coffee");
    set_long("A thermos of coffee.  It looks good for a hangover.\n");
    set_messages(
	"The coffee seems to make you feel better from all of that alcohol.\n",
	" drinks a cup of coffee from a thermos.\n");
    /*set_empty_message("You notice your thermos is empty.\n");*/
    set_charges(4);
    set_intox(-7);
    set_heal(0);
}
