#include "/obj/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
    ::reset(arg);
    if (arg) return;
    set_name("bitch cake");
    add_alias("cake");
    set_short("A " + HBWHT + MAG + "BITCH CAKE" + NORM);
    set_long("    This is a magnificently feminine " + HBWHT + MAG + "BITCH CAKE" + NORM + " covered in purple and pink\n"+
             "  sprinkles, heavy sugar frosting, and something which looks like spray snow\n"+
             "  sparkles as the undercoat. Your masculinity is challenged just by the presence\n"+
             "  of this crazy thing.\n");

    set_msg("You take a bite into the " + HBWHT + MAG + "BITCH CAKE" + NORM + ".\n"+
            "You have absorbed so much girlishness that you can probably shit rainbows.\n");
    set_msg2(" takes a bite into a " + HBWHT + MAG + "BITCH CAKE" + NORM + " and instantly becomes more girly.\n");

    add_cmd("eat");
    set_heal(50,50);
    set_charges(3);
    set_stuff(8);
    set_soak(1);
    set_value(300);

    set_type("bites");              /* Plural description of charges */
    set_type_single("bite");        /* Singular description of 1 charge */

}

