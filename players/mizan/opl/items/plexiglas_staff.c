/*****************************************************************************
 *      File:                   plexiglas_staff.c
 *      Function:               A high WC weapon which breaks all the time.
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:
 *      Change History:
 ****************************************************************************/

inherit "obj/weapon";
#include "/obj/ansi.h"

reset(arg)
{
    ::reset(arg);
    if (!arg)
    {
        set_name("staff");
        set_long("    This is a delicate-looking, roughly six-foot section of Plexiglas.\n"+
                 "  You can't imagine that it would make a very durable weapon at all, but\n"+
                 "  perhaps the first few hits or so it might leave a mark on someone.\n");
        set_short(HIC + "A blue Plexiglas staff" + NORM);
        set_class(28);
        set_value(500);
        set_alias("plexiglas");
        set_weight(2);
	set_hit_func(this_object());
    }
}

weapon_hit(attacker)
{
    if(!broke && random(10) > 5)
    {
        weapon_breaks();
        return 0;
    }
}
