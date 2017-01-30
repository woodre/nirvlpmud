/*****************************************************************************
 *      File:                   guard-turkey.c
 *      Function:               Carries the keys to unlock most of the dead-end
 *                              entrances inside the maze.
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:
 *      Change History:         DONE Initial revision - 09 Mar 2011
 ****************************************************************************/

inherit "/players/mizan/opl/core/monster.c";
#include "/players/mizan/opl/definitions.h"



reset(arg)
{
    object gold;
    object key;
    object fakekey;
    object nightstick;
    object bag;

    string my_name;

    ::reset(arg);
    if (arg) return;


    my_name = TURKEY_DM->get_turkey_name();

    set_name("a giant guard turkey named " + my_name);
    set_race("turkey");
    set_alias(lower_case(my_name));
    set_short("A guard turkey named " + my_name);
    set_long("    This is a terrifying sight... a 8 foot tall turkey fully featuring razor\n"+
             "sharp claws, larger-than-life feathers, and equally larger-than-life drumsticks.\n"+
             "Take great care through, as this turkey seems to be guarding something of\n"+
             "great importance to it, and doesn't seem very inclined to give it up.\n");

    set_level(STATS_DM->get_level_medium());
    set_hp(STATS_DM->get_hp_medium() + 800);
    set_al(0);
    set_wc(STATS_DM->get_wc_medium() + 20);
    set_ac(STATS_DM->get_ac_medium());

    set_hp_bonus(STATS_DM->get_hp_bonus_medium());

    set_heal(60, 3);

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 2;

    set_chat_chance(10);
    load_chat("A giant guard turkey named " + my_name + " says: Gobble gobble.\n");
    load_chat("A giant guard turkey named " + my_name + " looks at you.\n");
    load_chat("A giant guard turkey named " + my_name + " twirls his nightstick.\n");


    gold = clone_object("obj/money");
    gold->set_money(STATS_DM->get_gold_medium() / 2);
    move_object(gold,this_object());

    nightstick = clone_object("/players/mizan/opl/beasties/medium/guard_turkey/nightstick.c");
    move_object(nightstick, this_object());  

    bag = clone_object("/players/mizan/opl/beasties/medium/guard_turkey/duffelbag.c");
    move_object(bag, this_object());

    /* we don't alway have keys available. */
    if (1 == random(6))
    {
        key = clone_object("obj/key");
        key->set_type(TURKEY_DM->get_key_type());
        key->set_code("stonedoor");
        move_object(key, this_object());
    }
    else
    {
        fakekey = clone_object("obj/key");
        fakekey->set_type("minimum-security");
        fakekey->set_code("nulldoor");
        move_object(fakekey, this_object());
    }

    if (1 == random(5)) set_random_move_time(10);
}

