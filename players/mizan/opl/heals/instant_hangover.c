/*****************************************************************************
 *      File:                   instant_hangover.c
 *      Function:               Decoy heal item. Causes useless intoxication.
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
    set_name("instant hangover");
    add_alias("bottle");
    set_short("A bottle of " + BWHT + HIK + "Instant Hangover" + NORM);
    set_long(
        "    This is dark green glass bottle filled with some noxious and foul smelling\n"+
        "  liquid. You are skeptical as to the actual healing value it offers, but\n"+
        "  stranger things have been found in Nirvana which are useful.\n");
    set_type("drink");
    set_msg("You take a sip from the bottle. It tasted disgusting, and you're not sure\nif there was ANY VALUE WHATSOEVER to what you just drank...\n");
    set_msg2(" sips down some strange liquid which smells like boiling diarrhea from where\nyou are currently standing. Phew!\n");

    add_cmd("drink");
    set_heal(1,1);
    set_charges(4);
    set_intox(20);
    set_soak(0);
    set_value(400);
}

