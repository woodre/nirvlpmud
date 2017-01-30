	/* Discreeto Burrito */

#include <ansi.h>
inherit "/obj/generic_heal.c";

void reset(int arg)
{
    ::reset(arg);
    if(arg) return;
    set_name("burrito");
    add_alias("Burrito");
    add_alias("discreeto");
    set_short("an Discreeto burrito.");
    set_long("This is a microwave burrito that may be a bit past expiration date \n"+
             "but it still seems like it might be edible. \n");
    set_type("bites");
    set_type_single("bite");
    set_msg("You gobble down a bite of the burrito. You feel odd.\n");
    set_msg2(" gobbles down a bite of their burrito and turns a bit green. \n");
    set_empty_msg("You remember now that the box of burritos had been moving and wimpering. Gross.\n");
    add_cmd("eat");
    add_cmd("bite");
    set_heal(50,50);
    set_charges(3);
    set_intox(5);
    set_stuff(8);
    set_value(650);
}

