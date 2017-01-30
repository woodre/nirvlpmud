#include "/players/balowski/lib.h"
inherit PORTHEAL;

void
create()
{
    ::create();
    set_name("burger");
    set_ids(({ "hamburger" }));
    set_charge_name("can", "cans");
    set_verb("gobble");
    set_short("A hamburger");
    set_long("A delicous hamburger.\nYou feel like gobbleing the whole thing.\n");
    set_messages("You gobble the burger and throw the wrapper on the ground.\n",
                " gobbles a burger.\n");
    set_charges(1);
    set_satiate(6);
    set_heal(18);
}
 
status
drop(int silently) {
   if (!silently) {
        write("The hamburger falls to the ground and is ruined.\n");
        say(this_player()->query_name() + " throws away a burger.\n");
   }
   destruct(this_object());
   return 1;
}
