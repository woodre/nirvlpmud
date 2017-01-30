/*****************************************************************************
 *      File:                   baturine.c
 *      Function:               NA NA NA NA NA NA NA NA Bat piss. In a flask.
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
    set_name("urine");
    add_alias("flask");
    set_short("A flask of " + HBYEL + HIK + "BAT URINE" + NORM);
    set_long(
        "    This is large Pyrex glass flask filled with... Bat urine.\n"+
        "  You won't become a billionaire crimefighting vigilante extraordinaire\n"+
        "  by drinking this stuff, but you just might get healed a wee bit from\n"+
        "  it... Right.\n");
    set_type("drink");
    set_msg(HBYEL + HIK + "NA NA NA NA NA NA NA NA NA NA NA NA NA NA NA BAT PISS!" + NORM + "\n" +
            "You slurp bat urine out of the flask like a vigilante killing machine.\n");
    set_msg2(" sucks down some " + HBYEL + HIK + "BAT URINE" + NORM + " out of a large glass flask.\n");

    add_cmd("drink");
    set_heal(50,50);
    set_charges(4);
    set_intox(5);
    set_soak(10);
    set_value(450);
}

