/*****************************************************************************
 *      File:                   ublood_black.c
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
    set_short("A tiny vial of " + HBWHT + HIK + "BLACK" + NORM + " Unicorn's blood");
    set_long(
        "   This is a very tiny crystal vial of black liquid distilled from the rainbow\n"+
        "  colored blood of Unicorns. How and why this liquid exists eludes you... and\n"+
        "  while you may not be a Unicorn blood connoisseur, you do have a sense of\n"+
        "  nightmarish logistics and effort that must have been gone through to\n"+
        "  separate this color component from its original rainbow form.\n" +
        "  You think for a minute and realize that black is not one of the colors\n"+
        "  of the rainbow... therefore this stuff is either counterfeit, or if it\n"+
        "  is real, it has a tremendous monetary value.\n");
    set_type("drink");
    set_msg("You crack open the vial and tip a few drops of the liquid down...\n"+
    HBWHT + HIK + "It tastes being vigorously beaten with sacks of coal... at night." + NORM + "\n");
    set_msg2(" tips down a few drops of " + HBWHT + HIK + "BLACK" + NORM + " Unicorn's blood\n");

    add_cmd("drink");
    set_heal(150,150);
    set_charges(2);
    set_intox(5);
    set_value(15000);
}

query_color() { return "black"; }
