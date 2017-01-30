/*****************************************************************************
 *      File:                   lectroid.c
 *      Function:               General purpose annoying monster
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
    string my_name;

    ::reset(arg);
    if (arg) return;


    my_name = LECTROID_DM->get_lectroid_name();

    set_name("John " + my_name);
    set_race("lectroid");
    set_alias("john");
    set_short("A " + BWHT + HIK + "Black Lectroid" + NORM + " named John " + my_name);
    set_long("    This appears to be like any other human, but something is sort of wrong\n"+
            "  about the appearance of this guy. He has a somewhat vacant and alternatingly\n"+
            "  uncomfortably crazed look in his eyes... and despite the fact that he is\n"+
            "  dressed appropriately in a fine business attire, he has several odd and not\n"+
            "  quite explainable stains on his shirt and jacket. He is a Black Lectroid,\n"+
            "  whatever the hell that is,\n");
    set_level(STATS_DM->get_level_medium());
    set_hp(STATS_DM->get_hp_medium());
    set_al(0);
    set_wc(STATS_DM->get_wc_medium());
    set_ac(STATS_DM->get_ac_medium());
    set_heal(60,3);

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 2;

    /* aggressive monster bonus */
    set_hp_bonus(STATS_DM->get_hp_bonus_medium());

    set_chance(15);
    set_spell_mess1(query_name() + " lunges forth, trying to tackle you!\n");
    set_spell_mess2(query_name() + " screams a hideous, bloodcurdling cry and tries to claw you!\n");
    set_spell_dam(250);

    gold = clone_object("obj/money");
    gold->set_money(STATS_DM->get_gold_medium());
    move_object(gold,this_object());

    if (1 == random(5)) set_random_move_time(60);
}

heart_beat()
{
    ::heart_beat();
    if (attacker_ob && 1 == random(5)) insult();
    else if (1 == random(25)) insult();
}

insult()
{
    string result;
    result = query_name() + " says: " + U + LECTROID_DM->get_lectroid_quote() + NORM + "\n";
    say(result);
}

init()
{
    object room;
    object scarf;
    ::init();

    if (!this_player()) return;

    room = environment(this_player());

    if (room &&
            room == environment(this_object()) &&
            this_player()->is_player() &&
            this_player()->query_level() < 20 &&
            !this_player()->query_invis())
    {
        scarf = present("overthruster", this_player());
        if(scarf)
        {
	    say(short() + " screams: " + U + "THE OVERTHRUSTER!" + NORM + "\n");
            say(short() + " turns to attack " + this_player()->query_name() + "!\n");
            this_object()->attack_object(this_player());
        }
    }
}

