/*****************************************************************************
 *      File:                   hugefish.c
 *      Function:               
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

reset(arg)
{
    object gold;

    ::reset(arg);
    if (arg) return;

    set_name("Huge fish");
    set_race("fish");
    set_long("You can't see it terribly clearly... but this is a pretty HUGE fish!\n");
    set_level(STATS_DM->get_level_hard());
    set_hp(STATS_DM->get_hp_hard());
    set_al(0);
    set_wc(STATS_DM->get_wc_hard());
    set_ac(STATS_DM->get_ac_hard());

    set_heal(19, 1);

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 3;

    /* aggressive monster bonus */
    if(1 == random(3))
    {
        set_hp_bonus(STATS_DM->get_hp_bonus_hard());
        set_aggressive(1);
    }
    else
    {
	set_hp_bonus(STATS_DM->get_hp_bonus_hard()/2);
    }

}

short() { return 0; }
