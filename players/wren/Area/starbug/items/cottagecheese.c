/* Kochanskis cottage cheese */

inherit "/obj/generic_heal.c";

void reset(int arg)
{
    ::reset(arg);
    if(arg) return;
    set_name("cheese");
    add_alias("cottage cheese");
    add_alias("tub");
    set_short("a small tub of cottage cheese.");
    set_long("Kochanski is fond of cottage cheese with pinapple chunks in.\n");
    set_type("bites");
    set_msg("You take a bite of the cottage cheese. Its pretty good.\n");
    set_msg2(" eats a bite of cottage cheese. \n");
    add_cmd("eat");
    add_cmd("bites");
    set_heal(50,50);
    set_charges(4);
    set_stuff(25);
    set_value(500);
}
