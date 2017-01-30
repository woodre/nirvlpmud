/*
 * This is a monster that is made out to look like a pile of gold coins.
 *
 */
inherit "/players/mizan/opl/core/monster.c";
#include "/players/mizan/opl/definitions.h"
#include "/obj/ansi.h"
int coins;



reset(arg)
{
    object gold;

    ::reset(arg);
    if (arg) return;

    coins = random(9999) + 50000;

    set_name("gold coins");
    set_race("coins");
    set_alias("gold");
    set_short("A veritable dragon horde of gold coins [" + HIY + coins + NORM + "]");
    set_long(coins + " pieces of Nirvana's main currency: the gold coin.\n"+
             "They are extremely heavy\n"+
             "On closer inspection however, something isn't quite right.\n");
    set_level(STATS_DM->get_level_hard());
    set_hp(STATS_DM->get_hp_hard() * 2);
    set_al(0);
    set_wc(STATS_DM->get_wc_hard());
    set_ac(STATS_DM->get_ac_hard());

    set_heal(15, 1);
    set_hp_bonus(STATS_DM->get_hp_bonus_hard() / 2);

    set_chance(15);
    set_spell_mess1(query_name() + " hits you VERY hard!\n");
    set_spell_mess2(query_name() + " hits you with a BONE SHATTERING CRUNCH!\n");
    set_spell_dam(250);

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 3;

    gold = clone_object("obj/money");
    gold->set_money(coins / 3);
    move_object(gold,this_object());
}


