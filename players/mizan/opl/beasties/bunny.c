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
    set_name("Bunny");
    set_short("Bunny the rabbit (busy)");
    set_race("rabbit");
    set_alias("bunny");
    set_long("    A female rabbit sits alone in this room, surrounded by several notebook\n"+
             "  computers and a stack of envelopes. She appears to be completely engrossed\n"+
             "  in her work, and pays no notice to you. Despite her small size, she appears \n"+
             "  rather fit, her physique is lean and taught from what appears to be years\n"+
             "  of Judo training. No, you're not some sort of super-detective or anything...\n"+
             "  She is still wearing her gi, and the black belt is folded neatly on the\n"+
             "  desk next to those envelopes.\n");
    set_level(25);
    set_hp(3800);
    set_al(0);
    set_wc(1550);
    set_ac(4);
    set_chat_chance(6);

    load_chat("Bunny mumbles: ...Air handler unit #6 is nearing end of life...\n");
    load_chat("Bunny mumbles: ...Note to call Vantage elevator and repair mezz door #2...\n");
    load_chat("Bunny mumbles: ...Need more trifold paper towels and urinal cakes...\n");
    load_chat("Bunny mumbles: ...Silly government, trying to property tax us underground...\n");
    load_chat("Bunny mumbles: ...Filing of grievance by Teamsters, counter with arena combat...\n");
    load_chat("Bunny mumbles: ...Over $50K worth of savings by switching to solar... \n");
    load_chat("Bunny mumbles: ...Our oil heat bill is going to be a lot lower this year...\n");
    load_chat("Bunny yawns tiredly.\n");
    load_chat("Bunny treats herself to a nice, luxurious stretch.\n");
    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 3;
}

