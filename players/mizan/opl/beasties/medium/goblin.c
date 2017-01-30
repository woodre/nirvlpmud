/*****************************************************************************
 *      File:                   goblin.
 *      Function:               Aggressive exp/coining monster
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
    object heal;
    string my_name;

    ::reset(arg);
    if (arg) return;


    my_name = GOBLIN_DM->get_goblin_name();

    set_name(my_name);
    set_race("goblin");
    set_alias(lower_case(my_name));
    set_short(my_name + " the " + HIG + "Goblin" + NORM);
    set_long(
    "    Dark green wrinkled skin... check. A rough and tumble, stout frame\n"+
    "  associated with hard living... check. Uncurable ugliness... check.\n"+
    "  Well, this is indeed a Goblin. He doesn't look very happy, but if you\n"+
    "  weren't being paid too much money and had the name of '" + my_name + "',\n"+
    "  you wouldn't be terribly optimistic in life, would you?\n");
    set_level(STATS_DM->get_level_medium());
    set_hp(STATS_DM->get_hp_medium());
    set_al(0);
    set_wc(STATS_DM->get_wc_medium() + 45);
    set_ac(STATS_DM->get_ac_medium());
    set_heal(48,3);

    set_hp_bonus(STATS_DM->get_hp_bonus_medium());

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 2;

    set_chance(15);
    set_spell_mess1(query_name() + " hits you VERY hard!\n");
    set_spell_mess2(query_name() + " hits you with a BONE SHATTERING CRUNCH!\n");
    set_spell_dam(250);

    set_chat_chance(5);
    load_chat(my_name + " picks his nose.\n");
    load_chat(my_name + " scratches his butt.\n");
    load_chat(my_name + " burps rudely!\n");
    load_chat(my_name + " adjusts his crotch.\n");
    load_chat(my_name + " scratches himself.\n");
    load_chat(my_name + " farts loudly. POOOOOT!\n");
 
    gold = clone_object("obj/money");
    gold->set_money(STATS_DM->get_gold_medium());
    move_object(gold,this_object());

    if(1 == random(5))
    {
        heal = clone_object("/players/mizan/opl/heals/nightmarefuel.c");
        move_object(heal, this_object());
    }

    if (1 == random(5)) set_random_move_time(60);
}


heart_beat()
{
    ::heart_beat();
    if (attacker_ob && 1 == random(3)) insult();
}

insult()
{
    string result;
    result = query_name() + " " + GOBLIN_DM->get_insult() + NORM + "\n";
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
        scarf = present("goblin-scarf", this_player());
        if(!scarf)
        {
            say(HIG + this_object()->short() + NORM + " turns to attack " + this_player()->query_name() + "!\n");
            this_object()->attack_object(this_player());
        }
        else
        {
            say(HIG + this_object()->short() + NORM + " glares at " +this_player()->query_name() + " menacingly.\n");
        }
    }
}

