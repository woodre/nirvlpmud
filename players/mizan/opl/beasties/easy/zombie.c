/*****************************************************************************
 *      File:                   zombie.c
 *      Function:               A general purpose coining monster, aggro
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:                 
 *      Change History:         
 ****************************************************************************/

inherit "/players/mizan/opl/core/monster.c";
#include "/players/mizan/opl/definitions.h"
#include "/obj/ansi.h"

reset(arg)
{
    object gold;
    string my_type;

    ::reset(arg);
    if (arg) return;


    my_type = ZOMBIE_DM->get_zombie_type();

    set_name("zombie " + my_type);
    set_race("zombie");
    set_alias(lower_case(my_type));
    set_short("A zombie " + my_type);
    set_long("This is a smelly, cliche catastrophe movie zombie with the usual slow,\n"+
             "limping gait and a quest for brains. However there is one slight difference\n"+
             "from the usual cliche... this zombie is physically very strong and quick!\n");

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 1;

    /* lack of a special means faster healing */
    set_heal(48,10);

    set_level(STATS_DM->get_level_easy());
    set_hp(STATS_DM->get_hp_easy());
    set_al(-350);
    set_wc(STATS_DM->get_wc_easy());
    set_ac(STATS_DM->get_ac_easy());

    /* aggressive monster bonus */
    set_hp_bonus(STATS_DM->get_hp_bonus_easy());

    set_chance(15);
    set_spell_mess1(query_name() + " hits you VERY hard!\n");
    set_spell_mess2(query_name() + " hits you with a BONE SHATTERING CRUNCH!\n");
    set_spell_dam(200);

    set_chat_chance(6);
    load_chat("A zombie " + my_type + " moans incoherently.\n");
    load_chat("A zombie " + my_type + " shambles listlessly in your general direction.\n");
    load_chat("A zombie " + my_type + " appears to study you.\n");

    gold = clone_object("obj/money");
    gold->set_money(STATS_DM->get_gold_easy());
    move_object(gold,this_object());

    if (1 == random(5)) set_random_move_time(60);
}

init()
{
    object room;
    object perfume;
    ::init();

    if (!this_player()) return;

    room = environment(this_player());

    if (room &&
            room == environment(this_object()) &&
            this_player()->is_player() &&
            this_player()->query_level() < 20 &&
            !this_player()->query_invis())
    {
        perfume = present("zombie-perfume", this_player());
        if(!perfume)
        {
            say(HIY + this_object()->short() + NORM + " turns to attack " + this_player()->query_name() + "!\n");
            this_object()->attack_object(this_player());
        }
        else
        {
            say(HIY + this_object()->short() + NORM + " glares at " +this_player()->query_name() + " menacingly.\n");
        }
    }
}

heart_beat()
{
    if(1 == random(4)) set_aggressive(1);
    ::heart_beat();
}
