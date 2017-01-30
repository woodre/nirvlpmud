/*****************************************************************************
 *      File:                   gatekeeper-suit.c
 *      Function:               Worn by the gatekeeper.
 *                              Not something players can normally take.
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:
 *      Change History:
 ****************************************************************************/

inherit "/obj/armor.c";
#include "/obj/ansi.h"

reset(arg) 
{

    ::reset(arg);
    if(arg) return;
    set_name("red devil suit");
    set_short("A tiny fuzzy " + HIR + "red Devil's" + NORM + " suit");

    set_long("This a tiny red Devil's suit made of a fine, fuzzy red velvet.\n");

    set_value(1500);
    set_ac(0);
    set_type("armor");
    set_alias("suit");

    set_weight(1);
    set_size(1);
}

