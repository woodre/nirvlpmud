/*****************************************************************************
 *      File:                   bacon_lemonade.c
 *      Function:               A generic heal.
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:
 *      Change History:         DONE Initial revision - 09 Mar 2011
 ****************************************************************************/
inherit "/obj/generic_heal.c";
#include "/obj/ansi.h"

void reset(int arg)
{
    ::reset(arg);
    if (arg) return;
    set_name("lemonade");
    add_alias("thermos");
    set_short("A thermos of " + HBYEL + HIR + "BACON FLAVORED LEMONADE" + NORM);
    set_long(
        "    This is large Pyrex glass flask filled with... Bat urine.\n"+
        "  You won't become a billionaire crimefighting vigilante extraordinaire\n"+
        "  by drinking this stuff, but you just might get healed a wee bit from\n"+
        "  it... Right.\n");
    set_type("drink");
    set_msg(HBYEL + HIR + "HOLY COW THANK THE GODS FOR BACON FLAVORED EVERYTHING!" + NORM + "\n" +
            "You suck down a swig of bacon flavored lemonade. Life is good.\n");
    set_msg2(" sucks down some " + HBYEL + HIR + "BACON FLAVORED LEMONADE" + NORM + ".\n");

    add_cmd("drink");
    set_heal(50,50);
    set_charges(4);
    set_intox(8);
    set_soak(14);
    set_value(400);
}

