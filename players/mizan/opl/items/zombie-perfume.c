/*****************************************************************************
 *      File:                   zombie-perfume.c
 *      Function:               An expensive item which keeps zombies from
 *                              going aggro on players.
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:
 *      Change History:
 ****************************************************************************/

inherit "/players/mizan/core/object.c";
#include "/obj/ansi.h"

reset(arg)
{
    ::reset(arg);
    if(arg) return;

    set_get(1);
    set_value(10);
    set_weight(1);

    set_name("bottle");
    set_alias("perfume");
    set_short("A small bottle of " + HIR + "Rotting Meat Perfume" + NORM);

    set_long("In your hands you hold a fine product released by none other than the \n"+
            "intelligent and attractive businesswoman/socialite mogul Paris Hilton.\n"+
            "You cannot blame the impeccable taste of this upstanding and disease-free\n"+
	    "thinking machine for releasing a product with a loose screw top spritzer cap,\n"+
            "because selling a leaky bottle of rotting meat smell is clearly not her fault.\n"+
             "</SARCASM>\n");

    set_read("The label reads: Hilton Corporation. New New York, 2038\n");
    set_smell("Need I remind you that this bottle smells like rotting flesh?\n");
    set_taste("The power of the force stops you, you hoser.\n");
}


query_save_flag() { return 1; }
