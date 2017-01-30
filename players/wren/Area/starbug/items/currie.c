	/* currie */

inherit "/obj/generic_heal.c";

void reset(int arg)
{
    ::reset(arg);
    if(arg) return;
    set_name("currie");
    add_alias("tin");
    add_alias("chicken");
    set_short("A tin of chicken currie");
    set_long("This is a small aluminum tin of indian cuisine. Probably still edible\n");
    set_type("bites");
    set_msg("You take a bite of currie. Oooh Spicey.\n");
    set_msg2(" eats some currie. \n");
    add_cmd("eat");
    add_cmd("bite");
    set_heal(60,60);
    set_charges(3);
    set_stuff(15);
    set_value(500);
}

