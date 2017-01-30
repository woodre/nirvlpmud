#include "/sys/ansi.h"
inherit "/obj/generic_heal.c";
int is_decayed;

void reset(int arg)
{
    ::reset(arg);
    if (arg) return;
    is_decayed = 0;
    set_name("roll");
    add_alias("tuna");
    set_short("An "+ HBWHT + RED + "bitchingly spicy" + NORM + " tuna roll");
    set_long("This is a fairly large roll of sushi, whose center is comprised of a\n"+
	     "frighteningly potent spicy tuna filling. You should probably eat this\n"+
             "sooner rather than later, because the spice is not preserving the tuna\n"+
             "fish... it's probably melting and wasting it away!\n");
    set_type("bites");
    set_type_single("bite");
    set_msg(HIY+"You take a bite out of " + HIR + "BITCHINGLY HOT, INSANELY SPICY" + NORM + " tuna roll.\n");
    set_msg2(" takes a bite out of a " + HIR + "BITCHINGLY HOT, INSANELY SPICY" + NORM + " tuna roll.\n");
    add_cmd("eat");
    set_heal(50,50);
    set_charges(4);
    set_soak(0);
    set_stuff(16);
    set_value(300);
    call_out("decay", 1800);
}


query_save_flag()
{
    return 1;
}


decay()
{
    say(short() + " seems to be decaying.\n");
    call_out("decompose", 10);
}

decompose()
{
    say(short() + " appears to have decayed significantly.\nIt no longer looks tasty.\n");
    set_short("A decayed, spicy tuna roll");
    set_long("This is an uncomfortably warm spicy tuna roll which appears to have suffered\n"+
             "some sort of nuclear meltdown in its central, fishy core.\n"+
             "It seems to have decayed significantly since it was made.\n"+
             "This should not be surprising as the half life of sushi is quite small.\n");
    set_type("bites");
    set_msg(HIY+"You take a bite out of a decayed tuna roll.\n");
    set_msg2(" takes a bite out of a decayed tuna roll.\n");
    add_cmd("eat");
    set_heal(-10,-10);
    set_stuff(16);
    set_value(18);
    is_decayed = 1;
}
