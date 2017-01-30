	/* cats fish */

inherit "/obj/generic_heal.c";

void reset(int arg)
{
    ::reset(arg);
    if(arg) return;
    set_name("fish");
    add_alias("box");
    add_alias("trout");
    set_short("A box of trout ala crem");
    set_long("This is a boxed fish dinner. Cat found the vending machines.\n");
    set_type("bites");
    set_msg("You take a bite of fish. Enjoy your meal. I will.\n");
    set_msg2(" eats some fish. \n");
    add_cmd("eat");
    add_cmd("bite");
    set_heal(50,50);
    set_charges(3);
    set_stuff(18);
    set_value(700);
}

