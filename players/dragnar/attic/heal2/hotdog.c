#include "/players/balowski/lib.h"
inherit PORTHEAL;

void
create()
{
    ::create();
    set_name("hotdog");
    set_charge_name("bite", "bites");
    set_verb("eat");
    set_short("Texas Hot hotdog");
    set_long("A juicy Texas Hot hotdog.\n");
    set_messages("You stuff a huge bite into your mouth.\n",
		" takes a bite of a hotdog.\n");
    /*write("You finish your Texas Hot.\n");*/
    set_charges(4);
    set_satiate(17);
    set_heal(10);
}
