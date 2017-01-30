	/* listers poppadom */


inherit "/obj/generic_heal.c";

void reset(int arg)
{
    ::reset(arg);
    if(arg) return;
    set_name("poppadom");
    add_alias("poppadoms");
    add_alias("packet");
    set_short("A paper packet of poppadoms");
    set_long("These are poppadoms. A tasty Indian food appetizer. A bit stale.\n");
    set_type("bites");
    set_msg("You snap off a piece of poppadom.\n");
    set_msg2(" eats a poppadom. \n");
    add_cmd("eat");
    add_cmd("bite");
    set_heal(2,3);
    set_charges(5);
    set_stuff(12);
    set_value(20);
}

