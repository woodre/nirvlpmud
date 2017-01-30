	/* pringles */

#include <ansi.h>
inherit "/obj/generic_heal.c";

void reset(int arg)
{
    ::reset(arg);
    if(arg) return;
    set_name("pringles");
    add_alias("chip");
    add_alias("chips");
    add_alias("crisps");
    add_alias("pringle");
    add_alias("Pringles");
    set_short("Pringles.");
    set_long("Chips that are stacked single file in a can. They are not  \n"+
             "as greasy as regular potato chips. These are regular flavor.\n");
    set_type("chips");
    set_type_single("chip");
    set_msg("You Pop the top and don't wanna stop.\n");
    set_msg2(" pops the top and eats a chip. \n");
    set_empty_msg("You get your hand stuck reaching for the crumbs, sometimes you just gotta let em go.\n");
    add_cmd("eat");
    add_cmd("pop");
    set_heal(50,50);
    set_charges(3);
    set_stuff(10);
    set_value(800);
}

