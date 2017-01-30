#include "/players/balowski/lib.h"
inherit PORTHEAL;

void
create()
{
    ::create();
    set_name("pitcher");
    set_charge_name("sisco", "sisco");
    set_verb("pound");
    set_short("Pitcher of sisco");
    set_long("A pitcher of sisco.\nYou feel like pounding the whole thing.\n");
    set_messages("You pound the sisco and smash the pitcher on the ground.\n",
                " pounds a pitcher of sisco.\n");
    set_charges(1);
    set_heal(1000);
}

status
drop(int silently) {
    if (!silently) {
        write("The pitcher breaks and the sisco soaks into the ground.\n");
        say(this_player()->query_name() +
                " drops a pitcher and the sisco soaks into the ground.\n");
    }
    destruct(this_object());
    return 1;
}
