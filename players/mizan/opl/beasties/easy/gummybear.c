/*****************************************************************************
 *      File:                   gummybear.c
 *      Function:               A general purpose coining monster.
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

    ::reset(arg);
    if (arg) return;

    set_name("gummy polar bear");
    set_race("bear");
    set_alias("gummy bear");
    set_short("A gummy polar bear");
    set_long(
        "    This is the fearsome and majestic creature you have come to know since\n"+
        "  childhood. Well... for the most part it is anyhow. While it has the size,\n"+
        "  shape, and mass of what you expect is a polar bear... it is certainly not\n"+
        "  quite the same as what you are used to. The reason for this is because his\n"+
        "  body is composed entirely of the see-through material that makes up\n"+
        "  gummy bears. This, my friends... is a gummy polar bear.\n");
    set_level(25);

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 1;

    /* We use the same stats as the zombies */
    set_hp(STATS_DM->get_hp_easy());
    set_al(200);
    set_wc(STATS_DM->get_wc_easy());
    set_ac(STATS_DM->get_ac_easy());

    /* Heals a bit slower though */
    set_heal(25, 12);

    set_hp_bonus(STATS_DM->get_hp_bonus_easy());

    set_chat_chance(5);
    load_chat(query_name() + " scratches itself.\n");
    load_chat(query_name() + " carefully examines you.\n");
    load_chat(query_name() + " burps rudely!\n");
    load_chat(query_name() + " sniffs his crotch.\n");
    load_chat(query_name() + " sniffs the air.\n");
    load_chat(query_name() + " farts loudly. POOOOOT!\n");
 
    set_chance(25);
    set_spell_dam(100);

    set_spell_mess1(short() + " lunges for you with his gummy... claws.\n");
    set_spell_mess2(short() + " bowls you over with a surprisingly quick " + HIY + "SMACK!!!" + NORM + "\n");

    gold = clone_object("obj/money");
    gold->set_money(STATS_DM->get_gold_easy());
    move_object(gold,this_object());

    if (1 == random(5)) set_random_move_time(60);
}


heart_beat()
{
    ::heart_beat();
    if (attacker_ob && 1 == random(5)) insult();
}

insult()
{
    string result;
    result = query_name() + " cries: " + HIB + RANDOBJ_DM->get_gummy_bear_insult() + NORM + "\n";
    say(result);
}

/*
init()
{
    object room;
    object repellent;
    ::init();

    if (!this_player()) return;

    room = environment(this_player());

    if (room &&
            room == environment(this_object()) &&
            this_player()->is_player() &&
            this_player()->query_level() < 20 &&
            !this_player()->query_invis())
    {
        repellent = present("repellent", this_player());
        if(repellent)
        {
	    say(query_name() + "s don't like repellent!\n");
            say(HIG + this_object()->short() + NORM + " turns to attack " + this_player()->query_name() + "!\n");
            this_object()->attack_object(this_player());
        }
        else
        {
            say(HIG + this_object()->short() + NORM + " glares at " +this_player()->query_name() + " menacingly.\n");
        }
    }
}
*/
