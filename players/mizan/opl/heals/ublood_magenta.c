/*****************************************************************************
 *      File:                   ublood_magenta.c
 *      Function:               A heal which is actually a puzzle piece
 *                              Everything they say is in all capitals
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
    set_name("blood");
    add_alias("vial");
    set_short("A tiny vial of " + HBMAG + HIW + "MAGENTA" + NORM + " Unicorn's blood");
    set_long(
        "   This is a very tiny crystal vial of magenta liquid distilled from the rainbow\n"+
        "  colored blood of Unicorns. How and why this liquid exists eludes you... and\n"+
        "  while you may not be a Unicorn blood connoisseur, you do have a sense of\n"+
        "  nightmarish logistics and effort that must have been gone through to\n"+
        "  separate this color component from its original rainbow form.\n");
    set_type("drink");
    set_msg("You crack open the vial and tip a few drops of the liquid down...\n"+
    HBMAG + HIW + "It tastes like being sucked off by a prom queen in a purple, glittery wig." + NORM + "\n");
    set_msg2(" tips down a few drops of " + HBMAG + HIW + "MAGENTA" + NORM + " Unicorn's blood\n");

    add_cmd("drink");
    set_heal(90,90);
    set_charges(2);
    set_intox(5);
    set_value(5000);
}

query_color() { return "magenta"; }
