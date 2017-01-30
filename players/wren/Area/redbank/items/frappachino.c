	/* frappachino */

#include <ansi.h>
inherit "/obj/generic_heal.c";

void reset(int arg)
{
    ::reset(arg);
    if(arg) return;
    set_name("frappachino");
    add_alias("bottle");
    add_alias("frap");
    add_alias("coffee");
    set_short("a bottle of Frappachino.");
    set_long("A small bottle of Frappachino. This is a drink that is \n"+
             "composed of coffee and cream served iced. An aquired  \n"+
             "taste for most folks.\n");
    set_type("gulps");
    set_type_single("gulp");
    set_msg("You gulp down the Frappachino. You feel invigorated.\n");
    set_msg2(" gulps the Frappachino. \n");
    add_cmd("gulp");
    add_cmd("drink");
    set_heal(60,0);
    set_charges(3);
    set_soak(8);
    set_stuff(6);
    set_value(600);
}
