/*
 * This is a creature which sits in the bar and mopes.
 *
 */
inherit "/players/mizan/opl/core/monster.c";
#include "/obj/ansi.h"

reset(arg)
{
    object gold, what;
    ::reset(arg);
    if (arg) return;
    set_name("Paul the Red Dragon");
    set_short("Paul the " + HIR + "Red Dragon" + NORM + " (retired)");
    set_race("dragon");
    set_alias("paul");
    set_long("    Paul is a fairly large creature, but by red dragon standards he is\n"+
             "  pretty small, only 20 feet long or so. He's also somewhat overweight,\n"+
             "  and judging by the looks of things he appears to be somewhat depressed.\n"+
             "  You would expect his presence in such an extravagant place to be somewhat\n"+
             "  of a downer, but it has the unintended side effect of giving this Irish\n"+
             "  themed bar some street credibility.\n");
    set_level(25);
    set_hp(38000);
    set_al(0);
    set_wc(750);
    set_ac(300);
    set_chat_chance(3);
    load_chat("Paul sighs deeply and takes another sip of his drink.\n");
    load_chat("Paul mumbles something quietly to Shane.\n");
    load_chat("Paul shifts in his place, and acknowledges your presence with a subtle nod.\n");
    load_chat("Paul looks back down at his drink.\n");
    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 3;
}

