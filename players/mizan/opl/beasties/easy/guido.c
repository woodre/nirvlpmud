/*****************************************************************************
 *      File:                   guido.c
 *      Function:               
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
    object hat;
    string my_name;
    string my_first_name;
    string my_nickname;

    ::reset(arg);
    if (arg) return;

    my_first_name = GUIDO_DM->get_first_name();
    my_nickname = GUIDO_DM->get_nickname();

    my_name = my_first_name + " '" + my_nickname + "'";

    set_name(my_name);
    set_race("guido");
    set_alias(lower_case(my_nickname));
    set_alt_name(lower_case(my_first_name));
    set_short(my_name + " the " + HIC + "Jersey Shore Guido Wannabe" + NORM);
    set_long(
        "    The only thing worse than the characters in 'The Jersey Shore' are the\n"+
        "  legions of idiots who emulate their shallow, dysfunctional lifestyles.\n"+
        "  Standing before you is one such specimen, a roided-up gorilla juicehead who\n"+
        "  thinks that Central American means Kansas, that socialism means unamerican,\n"+
        "  and Apartheid is a new hangover headache remedy. The saddest part of the whole\n"+
        "  process of following his Jersey Shore heroes is that he is not even Italian.\n"+
        "  He might be Albanian, Irish, Chilean, or any mixture of any nationality EXCEPT\n"+
        "  Italian. Oh yeah- he doesn't even hail from the Jersey Shore either. \n"+
        "  He's probably from Long Island, or even Maine, for all we know.\n");

    set_level(STATS_DM->get_level_weak());
    set_hp(STATS_DM->get_hp_weak());
    set_al(-300);
    set_wc(STATS_DM->get_wc_weak());
    set_ac(STATS_DM->get_ac_weak());

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 0;

    /* Very fast heal rate */
    set_heal(44, 10);

    set_hp_bonus(STATS_DM->get_hp_bonus_weak());

    set_chat_chance(5);
    load_chat(my_name + " adjusts his crotch.\n");
    load_chat(my_name + " spits on the ground.\n");
    load_chat(my_name + " flexes and preens himself, obvlivious to you.\n");
    load_chat(my_name + " wonders why there are so many fat chicks here.\n");
    load_chat(my_name + " says: " + HIC + "Yo... where the grenades at? This shit is WACK!" + NORM + "\n");

    set_chance(25);
    set_spell_dam(70);

    set_spell_mess1(short() + " throws a wild flurry of punches aiming for the crotch!\n");
    set_spell_mess2(short() + " charges you, going for a clean tackle!\n");

    if (1 == random(3))
    {
        burrito = clone_object("/players/mizan/opl/heals/superburrito.c");
        move_object(burrito, this_object());
        set_wc(query_wc() + 5);
    }

    if (1 == random(3))
    {
        hat = clone_object("/players/mizan/opl/beasties/easy/guido/asshat.c");
        move_object(hat, this_object());
        set_wc(query_wc() + 5);
    }

    set_block_exits(1);

    gold = clone_object("obj/money");
    gold->set_money(STATS_DM->get_gold_weak());
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
    result = format(query_name() + " says: " + HIC + MAMASNAPS_DM->query_snap_fat() + NORM, 90);
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
        scarf = present("guidos_suck", this_player());
        if (scarf)
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

