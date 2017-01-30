	/* M&Ms attempt #5 */

#include <ansi.h>
inherit "/obj/generic_heal.c";

void reset(int arg)
{
    ::reset(arg);
    if(arg) return;
    set_name("M&Ms");
    add_alias("m&ms");
    add_alias("m&m");
    add_alias("candy");
    set_short("a bag of"+HIB+" M&Ms"+NORM+".");
    set_long("These are the fabled "+HIB+"blue M&M's"+NORM+" promised for assisting in world conquest.\n"+
             "They actually look like they turned out ok.\n");
    set_type("pieces");
    set_msg("You pop a few "+HIB+"M&Ms"+NORM+" in your mouth. Melts in your mouth not in your hands.\n");
    set_msg2(" eats some "+HIB+"M&Ms"+NORM+". \n");
    add_cmd("eat");
    add_cmd("bites");
    set_heal(0,0);
    set_charges(10);
    set_stuff(2);
    set_value(0);
}

