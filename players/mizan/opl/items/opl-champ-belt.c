/*****************************************************************************
 *      File:                   opl-champ-belt.c
 *      Function:               A prize for beating the OverPowerLord
 *                              AC2 Belt which allows item storage like a belt
 *                              and autoloads on the player.
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 5/2011
 *      Notes:
 *      Change History:
 ****************************************************************************/
#define MAX_WEIGTH      12
inherit "obj/armor";
#include "/obj/ansi.h"

int local_weight;

reset(arg) 
{
    ::reset(arg);
    if (arg) return;
    local_weight = 0;
    set_name("El Luchador Fantasma Championship Wrestling belt");
    set_value(22000);
    set_ac(2);
    set_weight(1);
    set_type("belt");
    set_alias("belt");
}

clean_up() 
{
    if (local_weight) 
    {
        write("The items in the belt clunk and clatter against one another.\n");
    }
    return 1;
}


long() 
{
    write("  This an utterly spectacular leather belt made in the classic 'Championship'\n"+
          "Wrestling' style. It has a large gold plate with an ornate rendering of the\n"+
          "Mexican Luchador Fantasma, wearing his jumpsuit, facemask, helmnet, and cape,\n"+
          "all while mounted on a motorcycle in the festive scene of a full-blown\n"+
          "street riot. On top of that, he is about to engage the riot police who are\n"+
          "positioned to shoot tear gas at him. You notice that there are several\n"+
          "canisters on the belt body as well. They appear to be usable as storage.\n");

    if (first_inventory(this_object()))
        write("There are things in the belt.\n");
    else
        write("Maybe you can put things into the belt.\n");
}

add_weight(w) 
{
    if (local_weight + w > MAX_WEIGTH) return 0;
    local_weight += w;
    return 1;
}


short() {
    if (worn) {
        return HBWHT + HIK + "El Luchador Fantasma Championship Wrestling belt" + NORM + " (worn)";
    }
    return HBWHT + HIK + "El Luchador Fantasma Championship Wrestling belt" + NORM;
}


can_put_and_get() 
{
    return 1;
}


get() 
{
    return 1;
}


prevent_insert() 
{
    if (local_weight > 0) 
    {
        write("You can't when there are things in the belt.\n");
        return 1;
    }
    return 0;
}


string query_auto_load() 
{
    return "/players/mizan/opl/items/opl-champ-belt.c";
}


