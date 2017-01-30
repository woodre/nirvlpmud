inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
        ::reset(arg);
        if(arg) return;

        set_name("figure");
        set_alt_name("driver");
        set_race("rogue");
        set_alias("shinshi_rogue_entrance");
        set_short(HIK+"A Dark Hooded Figure"+NORM);
        set_long("\
		A very tall, dark figure stands before you\n\
		with its dusty cloak flowing in the breeze.\n\
		Red eyes pierce through the darkness of its\n\
		hood. The figure seems to fade in and out\n\
		with the shadows that are in the area. The\n\
		figures arms are barely visible, however you\n\
		notice several deep gashes into its arms.\n");
        set_level(100);
        set_hp(99999);
        set_ac(99999);
        set_wc(99999);
        set_al(0);
}