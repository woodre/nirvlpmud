/*
 * This is a creature which sits in the rabbit hole.
 * It is not meant to be touched by players.
 */
inherit "/players/mizan/opl/core/monster.c";
#include "/obj/ansi.h"

reset(arg)
{
    object gold, what;
    ::reset(arg);
    if (arg) return;
    set_name("Tripod");
    set_short("Tripod the tiger (sleeping)");
    set_race("tiger");
    set_alias("tripod");
    set_long("    Tripod is an immense, three legged tiger. He appears to be completely\n"+
             "  engrossed in the art of sleeping, which happens to be something which\n"+
             "  all cats large and small tend to be very proficent at.\n");
    set_level(25);
    set_hp(13800);
    set_al(0);
    set_wc(1550);
    set_ac(55);
    set_chat_chance(3);

    load_chat("Tripod snores loudly.\n");
    load_chat("Tripod scratches his nose with a paw.\n");
    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 3;
}

