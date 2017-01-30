#include "/obj/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
    ::reset(arg);
    if (arg) return;
    set_name("jelly donut");
    add_alias("donut");
    set_short("A " + HBWHT + RED + "jelly donut" + NORM);
    set_long("    This is a glorious " + HBWHT + RED + "jelly donut" + NORM + " from parts unknown.\n"+
             "  Despite its dubious origins, it smells WONDERFUL and is just asking to\n"+
             "  be devoured voraciously.\n");

    set_msg("You take a bite into the " + HBWHT + RED + "jelly donut" + NORM + " and become one with it's holy goodness.\n");
    set_msg2(" takes a bite into a " + HBWHT + RED + "jelly donut" + NORM + ". Holy goodness ensues.\n");

    add_cmd("eat");
    set_heal(50,50);
    set_charges(3);
    set_stuff(8);
    set_soak(1);
    set_value(300);

    set_type("bites");              /* Plural description of charges */
    set_type_single("bite");        /* Singular description of 1 charge */

}

