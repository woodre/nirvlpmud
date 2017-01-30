/*****************************************************************************
 *      File:                   sheep.c
 *      Function:               General purpose medium monsters
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:
 *      Change History:         DONE Initial revision - 09 Mar 2011
 ****************************************************************************/

inherit "/players/mizan/opl/core/monster.c";
#include "/players/mizan/opl/definitions.h"
#include "/obj/ansi.h"

reset(arg)
{
    object gold;
    string my_name;

    ::reset(arg);
    if (arg) return;


    my_name = SHEEP_DM->get_sheep_name();

    set_name("a sheep commando named " + my_name);
    set_race("sheep");
    set_alias(lower_case(my_name));
    set_alt_name("commando");
    set_short("A sheep commando named " + my_name);
    set_long("This is a cute little sheep, but it has a dark side, as it is a\n"+
             "member of the Earwaxian National Guard. Upon closer inspection you\n"+
             "realize it seems to be bleeding from the butthole. Gross.\n");
    set_level(STATS_DM->get_level_medium());
    set_hp(STATS_DM->get_hp_medium());
    set_al(0);
    set_wc(STATS_DM->get_wc_medium());
    set_ac(STATS_DM->get_ac_medium());
    set_heal(60,3);

    set_hp_bonus(STATS_DM->get_hp_bonus_medium());

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 2;

    set_chat_chance(10);
    load_chat(short() + " mutters: hut.. hut... hut\n");
    load_chat(short() + " sniffs you carefully.\n");
    load_chat(short() + " blinks nervously.\n");
    load_chat(short() + " sniffs its own behind.\n");

    set_chance(15);
    set_spell_mess1(query_name() + " hits you VERY hard!\n");
    set_spell_mess2(query_name() + " hits you with a BONE SHATTERING CRUNCH!\n");
    set_spell_dam(250);

    gold = clone_object("obj/money");
    gold->set_money(STATS_DM->get_gold_medium());
    move_object(gold,this_object());

    move_object(clone_object("/players/mizan/opl/beasties/medium/sheep/garb.c"), this_object());

    if (1 == random(5)) set_random_move_time(15);
}


heart_beat()
{
    ::heart_beat();
    if (attacker_ob && 1 == random(3)) insult();
}

insult()
{
    string result;
    result = query_name() + " says: " + HIW + RANDOBJ_DM->get_film_quote() + NORM + "\n";
    say(result);
}


