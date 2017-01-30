/*****************************************************************************
 *      File:                   cloacacola.c
 *      Function:               Ass Soda
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
    set_name("cola");
    add_alias("bottle");
    set_short("A bottle of " + HBRED + HIW + "CLOACA COLA" + NORM);
    set_long(
        "    You bet your ass that this is the finest tasting soda that you have\n"+
        "  every had! It's probably the best value for the bottom dollar out there.\n"+
        "  It tastes so good it's almost magical. The key to a long life is a healthy\n"+
        "  colon, and you can bet that Cloaca Cola helps that happen in spades!\n");

    set_type("drink");
    set_msg("You take a sip from the bottle. " + HBRED + HIW + "FINE ASS TASTY!" + NORM + "\n");
    set_msg2(" sips down some " + HBRED + HIW + "CLOACA COLA" + NORM + ".\n");

    add_cmd("drink");
    set_heal(75,75);
    set_charges(4);
    set_intox(0);
    set_soak(10);
    set_value(400);
}

