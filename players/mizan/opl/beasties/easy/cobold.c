/*****************************************************************************
 *      File:                   cobold.c
 *      Function:               These guys are inside the vehicles which
 *                              attack the players in the maze
 *                              Everything they say is in all capitals
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
    object burrito;
    object weapon;
    string my_name;
    string my_first_name;
    string my_last_name;

    ::reset(arg);
    if (arg) return;

    my_first_name = COBOLD_DM->get_first_name();
    my_last_name = COBOLD_DM->get_last_name();

    my_name = my_first_name + " " + my_last_name;

    set_name(my_name);
    set_race("cobold");
    set_alias(lower_case(my_name));
    set_alt_name(lower_case(my_first_name));
    set_short(my_name + " the " + HIY + "Cobold" + NORM);
    set_long(
        "    This is the ugliest freaking toad you have ever seen in your life.\n"+
        "  Oh... wait a minute. This isn't a toad. This disgusting, fat, yellowy\n"+
        "  thing is a Cobold of the " + YEL + "Potato Crotch Canyon" + NORM + ". How do you know this level\n"+
        "  of detail for a race of creature you have never seen before?\n\n"+
        "  Because each Cobold is forced to wear a large steel dogtag reading:\n"+
        "  'I am a Cobold named " + my_name + ".\n"+
        "  If found drunk, please return this bitch to the Potato Crotch Canyon.'\n");

    set_level(STATS_DM->get_level_easy());
    set_hp(STATS_DM->get_hp_easy());
    set_al(-300);
    set_wc(STATS_DM->get_wc_easy());
    set_ac(STATS_DM->get_ac_easy());

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 1;

    /* Very fast heal rate */
    set_heal(44, 10);

    /* aggressive monster bonus */
    set_aggressive(1);
    set_hp_bonus(STATS_DM->get_hp_bonus_easy());

    set_chat_chance(5);
    load_chat(my_name + " picks her nose.\n");
    load_chat(my_name + " scratches her crotch.\n");
    load_chat(my_name + " burps rudely!\n");
    load_chat(my_name + " adjusts her butt.\n");
    load_chat(my_name + " scratches herself.\n");
    load_chat(my_name + " farts loudly. POOOOOT!\n");

    set_chance(25);
    set_spell_dam(70);

    set_spell_mess1(short() + " flings a wild punch to the groin!\n");
    set_spell_mess2(short() + " punches for the crotch!\n");

    if (1 == random(3))
    {
        burrito = clone_object("/players/mizan/opl/heals/superburrito.c");
        move_object(burrito, this_object());
        set_wc(query_wc() + 5);
    }

    if (1 == random(3))
    {
        weapon = clone_object("/players/mizan/opl/beasties/easy/cobold/branch.c");
        move_object(weapon, this_object());
        set_wc(query_wc() + 5);
    }
    else if(1 == random(3))
    {
        weapon = clone_object("/players/mizan/opl/beasties/easy/cobold/mamasword.c");
        move_object(weapon, this_object());
        set_wc(query_wc() + 4);
    }

    set_block_exits(1);

    gold = clone_object("obj/money");
    gold->set_money(STATS_DM->get_gold_easy());
    move_object(gold,this_object());

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
    result = format(query_name() + " says: " + HIY + COBOLD_DM->get_insult() + NORM, 90);
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
        scarf = present("cobold-staff", this_player());
        if (!scarf)
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

