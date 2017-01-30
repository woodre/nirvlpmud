	/* pretzels */

#include <ansi.h>
inherit "/obj/generic_heal.c";

void reset(int arg)
{
    ::reset(arg);
    if(arg) return;
    set_name("pretzels");
    add_alias("pretzel");
    add_alias("packet");
    set_short("a packet of pretzels.");
    set_long("This is a small paper bag full of chocolate covered \n"+
             "pretzels. They are a little melty but oh so tastey. \n");
    set_type("pretzels");
    set_type_single("pretzel");
    set_msg("You get chocolate all over yourself eatting a chocolate covered pretzel.\n");
    set_msg2(" gets chocolate all over themself eating a chocolate covered pretzel. \n");
    set_empty_msg("You're hands are covered with chocolate. Those were messy but oh so tasty.\n");
    add_cmd("eat");
    add_cmd("chomp");
    set_heal(30,30);
    set_charges(3);
    set_stuff(8);
    set_value(400);
}

