	/* joint */

#include <ansi.h>
inherit "/obj/generic_heal.c";

void reset(int arg)
{
    ::reset(arg);
    if(arg) return;
    set_name("joint");
    add_alias("weed");
    add_alias("Joint");
    add_alias("small joint");
    set_short("a small joint.");
    set_long("A small joint rolled from what looks like the scant remains \n"+
             "of somebodies dime bag. It looks ok, just very small.\n");
    set_type("puffs");
    set_type_single("puff");
    set_msg("You smoke the joint down to nothing. You feel pretty good.\n");
    set_msg2(" puffs on a joint. \n");
    add_cmd("puff");
    add_cmd("smoke");
    set_heal(10,10);
    set_charges(1);
    set_intox(14);
    set_value(250);
}

