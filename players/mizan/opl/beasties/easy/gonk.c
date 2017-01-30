/*****************************************************************************
 *      File:                   gonk.c
 *      Function:               A general purpose, non aggro coining monster
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:                 
 *      Change History:         
 ****************************************************************************/

inherit "/players/mizan/opl/core/monster.c";
#include "/players/mizan/opl/definitions.h"

reset(arg)
{
    object gold;
    object thingo;
    ::reset(arg);
    if (arg) return;
    set_name("droid");
    set_alias("gonk");
    set_short("A GNK power droid");
    set_long("This is a stout, featureless robot with a body like a boxy garbage can\n"+
             "and two stubby legs protruding from the bottom of it. There appear to be\n"+
             "some sort of mass-produced but homemade modifications to it, namely in the\n"+
             "in the form of additionally installed armor plating.\n");

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 1;

    /* Lots of hitpoints, but comparatively weaker than the other monsters */
    set_level(STATS_DM->get_level_easy());
    set_hp(STATS_DM->get_hp_easy());
    set_al(100);
    set_wc(STATS_DM->get_wc_easy());
    set_ac(STATS_DM->get_ac_easy());

    set_heal(30,10);

    set_hp_bonus(1066);

    set_chat_chance(6);
    load_chat("A GNS power droid says: Gonk.\n");
    load_chat("A GNS power droid says: Gonk. Gonk.\n");

    gold = clone_object("obj/money");
    gold->set_money(STATS_DM->get_gold_easy());
    move_object(gold,this_object());

    thingo = 0;
    if(1 == random(4)) thingo = clone_object("/players/mizan/opl/beasties/easy/gonk/overthruster.c");
    if(thingo) move_object(thingo, this_object());

    set_random_move_time(10);
}
