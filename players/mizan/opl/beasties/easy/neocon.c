/*****************************************************************************
 *      File:                   neocon.c
 *      Function:               General purpose coining monster
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:                  DONE.
 *      Change History:         
 *
 */
inherit "/players/mizan/opl/core/monster.c";
#include "/players/mizan/opl/definitions.h"
#include "/obj/ansi.h"
reset(arg)
{
    object gold;
    string my_name;
    string first_name;

    ::reset(arg);
    if (arg) return;

    first_name = NEOCON_DM->get_first_name();
    my_name = first_name + " " + NEOCON_DM->get_last_name();

    set_name(my_name);
    set_race("teabagger");
    set_alias(lower_case(my_name));
    set_alt_name(lower_case(first_name));
    set_short("A crazed teabagger named " + my_name);
    set_long("   Before you stands an exemplar of hate, bigotry, and intolerance. Dressed in\n"+
             "  their Sunday best patriotic T-shirts, Sarah Palin buttons, cutoff jorts, and\n"+
             "  Crocs shoes is a curious blend of both old and new worlds. Their appearance\n"+
             "  might cry out the cutting edge look of Walmart, but their message is the same\n"+
             "  as the generations of haters which came before them. Sadly, the more things\n"+
             "  change, the more they remain the same.\n");
    set_level(STATS_DM->get_level_easy());
    set_hp(STATS_DM->get_hp_easy());
    set_al(-999);
    set_wc(STATS_DM->get_wc_easy());
    set_ac(STATS_DM->get_ac_easy());

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 1;

    set_heal(30,10);

    set_hp_bonus(STATS_DM->get_hp_bonus_easy());

    set_chance(25);
    set_spell_dam(88);
    set_spell_mess1(short() + " cries: " + HIY + "I invoke the power of Rush Limbaugh to stop you!\n" + NORM);
    set_spell_mess2(short() + " cries: " + HIY + "You will got to HELL for not watching enough Fox News!\n" + NORM);

    gold = clone_object("obj/money");
    gold->set_money(STATS_DM->get_gold());
    move_object(gold,this_object());

    if (1 == random(5)) set_random_move_time(60);
}

heart_beat()
{
    ::heart_beat();
    if (attacker_ob && 1 == random(2)) insult();
    else if (1 == random(4)) insult();
}

insult()
{
    string result;
    int i;

    i = random(6);

    if(i == 1)
        result = query_name() + " chants: " + HIY + NEOCON_DM->get_ethnic_group() + " go home!\n" + NORM;
    else if(i == 2)
	result = query_name() + " chants: " + HIY + "Bomb " + NEOCON_DM->get_location() + "!\n" + NORM;
    else if(i == 3)
        result = query_name() + " says: " + HIY + NEOCON_DM->get_insult() + "\n" + NORM;
    else if(i == 4)
        result = query_name() + " smirks condescendingly at you.\n";
    else if(i == 5)
        result = query_name() + " chants: " + HIY +"All "+ NEOCON_DM->get_ethnic_group() + " are TERRORISTS!\n" + NORM;
    else
        result = query_name() + " chants: " + HIY + "We hate " + NEOCON_DM->get_ethnic_group() + "!\n" + NORM;

    say(result);
}

