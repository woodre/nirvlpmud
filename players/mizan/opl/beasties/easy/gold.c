/*****************************************************************************
 *      File:                   gold.c
 *      Function:               Mimic monster
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:                 
 *      Change History:         
 *                              
 ****************************************************************************/

inherit "/players/mizan/opl/core/monster.c";
#include "/players/mizan/opl/definitions.h"
#include "/obj/ansi.h"
int coins;



reset(arg)
{
    object gold;

    ::reset(arg);
    if (arg) return;

    coins = random(5000) + 5000;

    set_name("A large pile of gold coins [" + HIY + coins + NORM + "]");
    set_race("coins");
    set_alias("gold");
    set_short("A large pile of gold coins [" + HIY + coins + NORM + "]");
    set_long(coins + " pieces of Nirvana's main currency: the gold coin.\n"+
             "They are extremely heavy\n"+
             "On closer inspection however, something isn't quite right.\n");
    set_level(STATS_DM->get_level_easy());
    set_hp(STATS_DM->get_hp_easy());
    set_al(0);
    set_wc(STATS_DM->get_wc_easy());
    set_ac(STATS_DM->get_ac_easy());

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 1;

    if(coins > 7500) set_heal(66,10);
    else set_heal(44, 10);

    /* aggressive monster bonus */
    if(1 == random(3))
    {
        set_hp_bonus(STATS_DM->get_hp_bonus_easy());
        set_aggressive(1);
    }
    else
    {
	set_hp_bonus(STATS_DM->get_hp_bonus_easy()/2);
    }

    gold = clone_object("obj/money");
    gold->set_money(coins / 2);
    move_object(gold,this_object());
}


