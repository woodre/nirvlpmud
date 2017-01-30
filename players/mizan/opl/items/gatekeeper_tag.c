/*****************************************************************************
 *      File:                   gatekeeper-tag
 *      Function:               Worn by the gatekeeper.
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
    set_name("nametag");
    set_short("A paper tag reading '" + BBLU + HIW + "Hello My Name Is:" + NORM + " " + HIW + "GATEKEEPER" + NORM + "'");

    set_long("This paper name tag reading '" + BBLU + HIW + "Hello My Name Is:" + NORM + " " + HIW + "GATEKEEPER" + NORM + "'.\n");

    set_value(1500);
    set_ac(0);
    set_type("misc");
    set_alias("tag");

    set_weight(1);
    set_size(1);
}

