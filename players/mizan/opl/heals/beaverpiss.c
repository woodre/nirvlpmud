/*****************************************************************************
 *      File:                   beaverpiss.c
 *      Function:               Beer.
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
    set_name("piss");
    add_alias("bottle");
    set_short("A bottle of " + BCYN + HIW + "BEAVER PISS" + NORM);
    set_long(
        "    This is brown glass bottle filled with beaver piss. Well... at least\n"+
        "  that is what it proudly says on the label. It could just be beer for\n"+
        "  all you know, or some magical elixir of youth. Who knows. Try some!\n");
    set_type("drink");
    set_msg("You take a sip from the bottle. It's beaver piss alright...\n");
    set_msg2(" sips down some Bud Light from a large brown bottle.\n");

    add_cmd("drink");
    set_heal(50,50);
    set_charges(4);
    set_intox(10);
    set_soak(10);
    set_value(400);
}

