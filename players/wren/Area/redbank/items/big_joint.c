	/* big_joint */

#include <ansi.h>
inherit "/obj/generic_heal.c";

void reset(int arg)
{
    ::reset(arg);
    if(arg) return;
    set_name("joint");
    add_alias("weed");
    add_alias("Joint");
    add_alias("big joint");
    set_short("a big joint.");
    set_long("A large joint rolled from probably a dime bag worth of weed \n"+
             "and newspaper. It looks like it might be a challenge to finish \n"+
             "off before the cops or somebody shows up to hassle you.  \n");
    set_type("puffs");
    set_type_single("puff");
    set_msg("You take a long drag on the joint. You feel pretty good.\n");
    set_msg2(" puffs on a joint. \n");
    set_empty_msg("You really do see mermaids and sailboats now, that was some good stuff.\n");
    add_cmd("puff");
    add_cmd("smoke");
    set_heal(15,15);
    set_charges(3);
    set_intox(12);
    set_value(250);
}

