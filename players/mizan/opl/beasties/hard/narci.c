inherit "/players/mizan/opl/core/monster.c";

/*****************************************************************************
 *      File:                   narci.c
 *      Function:               Annoying high level kill
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:                 
 *      Change History:         
 *                              
 ****************************************************************************/

#include "/players/mizan/opl/definitions.h"
#include "/obj/ansi.h"


reset(arg)
{
    object gold;
    object weapon;
    object heal;

    string my_name;
    string my_first_name;
    string my_last_name;


    ::reset(arg);
    if (arg) return;


    my_first_name = NARCI_DM->get_first_name();
    my_last_name = NARCI_DM->get_last_name();
    my_name = my_first_name + " " + my_last_name;

    set_name(my_name);
    set_race("narcissist");
    set_alt_name(lower_case(my_name));
    set_alias(lower_case(my_first_name));
    set_short(my_name + ", member of the " + HIM + "Narcissist Killing League" + NORM);
    set_long("    Handsome and dapper are one way to describe the physical specimen standing\n" +
	     "  before you. Beautiful works much better, albeit in a non-homosexual and oddly\n"+
             "  admirable way. This is none other than " + my_name + ", an esteemed\n" +
	     "  member of the " + HIM + "Narcissist Killing League" + NORM + ", an elitist street gang of sorts\n"+
	     "  where not only do you have to be a good fighter, but a pretty boy in\n"+
	     "  order to be a member.\n");

    set_level(STATS_DM->get_level_hard());
    set_hp(STATS_DM->get_hp_hard());
    set_al(-200);
    set_wc(STATS_DM->get_wc_hard());
    set_ac(STATS_DM->get_ac_hard());

    set_hp_bonus(STATS_DM->get_hp_bonus_hard());
    set_heal(19, 1);

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 3;

    gold = clone_object("obj/money");
    gold->set_money(STATS_DM->get_gold_hard());
    move_object(gold,this_object());

    weapon = clone_object("/players/mizan/opl/beasties/hard/narci/katana.c");
    move_object(weapon, this_object());

    heal = 0;
    if(1 == random(2)) heal = clone_object("/players/mizan/opl/heals/ublood_cyan.c");
    else if(1 == random(6)) heal = clone_object("/players/mizan/opl/heals/ublood_yellow.c");
    else if(1 == random(9)) heal = clone_object("/players/mizan/opl/heals/ublood_magenta.c");
    else if(1 == random(18)) heal = clone_object("/players/mizan/opl/heals/ublood_black.c"); 
    if(heal) move_object(heal, this_object());

    if (1 == random(5)) set_random_move_time(10);
}


heart_beat()
{
    ::heart_beat();
    if (attacker_ob && 1 == random(4)) insult();
    else if (1 == random(12)) chat();
}

chat()
{
    int mode;
    string insult;
    mode = random(3);

    if(mode == 1)
    {
        insult = NARCI_DM->get_fact();
	insult = query_name() + " says: " + HIM + insult + NORM + "\n";
    }
    else
    {
        insult = NARCI_DM->get_insult();
        insult = query_name() + " says: " + HIM + insult + NORM + "\n";
    }

    say(insult);
}

insult()
{
    string result;
    result = query_name() + " says: " + HIM + NARCI_DM->get_insult() + NORM + "\n";
    say(result);
}
