#include "/sys/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
    ::reset(arg);
    if (arg) return;
    set_name("hot nuts");
    add_alias("bag");
    add_alias("sack");
    add_alias("nutsack");
    add_alias("nuts");

    set_short("A sack of " + HBRED + HIW + "HOT NUTS" + NORM);
    set_long("This is a fuzzy burlap sack filled with delicious, hot salty nuts. The aroma\n"+
             "of these is irresistable... you are just so tempted to put the sack to your\n"+
             "mouth, suck in a few hot nuts, and smother yourself in their rich, hot flavor.\n");
    set_type("handfuls");
    set_type_single("handful");
    set_msg(HIY+"You grab a few hot nuts out of the sack and stuff them in your mouth.\n"+NORM);
    set_msg2(" eats a few hot nuts out of a hairy burlap sack.\n");
    add_cmd("eat");
    set_heal(90,90);
    set_charges(4);
    set_soak(7);
    set_stuff(13);
    set_value(500);
}

query_save_flag()
{
    return 1;
}


