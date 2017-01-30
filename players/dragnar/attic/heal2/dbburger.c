#include "/players/balowski/lib.h"
inherit PORTHEAL;

void
create()
{
    ::create();
    set_name("hamburger");
    set_charge_name("burger", "burger");
    set_verb("gobble");
    set_short("A double hamburger");
    set_long("A delicous hamburger.\nYou feel like gobbleing the whole thing.\n");
    set_messages(
        "You gobble the burger and throw the wrapper on the ground.\n",
        " gobbles a burger.\n");
    set_charges(1);
    set_satiate(9);
    set_heal(26);
}

status
drop(int silently) {
    if (!silently) {
        write("The hamburger falls to the ground and is ruined.\n");
        say(this_player()->query_name() + " throws away a double hamburger.\n");
    }
    destruct(this_object());
    return 1;
}
