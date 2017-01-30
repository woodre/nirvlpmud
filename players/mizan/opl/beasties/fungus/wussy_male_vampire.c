inherit "/players/mizan/opl/core/monster.c";
#include "/players/mizan/opl/definitions.h"
#include "/obj/ansi.h"


reset(arg)
{
    object gold, album;
    string my_name;

    ::reset(arg);
    if (arg) return;


    my_name = VAMPIRE_DM->get_male_vampire_name();

    set_name(my_name + " the wussy vampire");
    set_race("vampire");
    set_alias(lower_case(my_name));
    set_short(my_name + " " + HIW + "the wussy vampire" + NORM);
    set_long("This is a shifty, glistening, but beer-bellied vampire named " + my_name + ".\n"+
             "He appears to be in great angst, and clutches wistfully to a lock of\n"+
             "someone's hair.\n");

    set_level(STATS_DM->get_level_medium());
    set_hp(STATS_DM->get_hp_medium());
    set_al(-200);
    set_wc(STATS_DM->get_ac_medium());
    set_ac(STATS_DM->get_wc_medium());
    set_hp_bonus(STATS_DM->get_hp_bonus_medium());
    set_heal(65, 3);


    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 1;

    set_hp_bonus(800);

    set_chance(10);
    set_spell_dam(200);
    set_spell_mess1(short() + " unleashes an unexpected burst of masculinity and testosterone!\n" +
	            "  (TRANSLATION: He had the balls to punch and fight you like a man)\n");
    set_spell_mess2(short() + " wildly claws and hisses at you!");


    gold=clone_object("obj/money");
    gold->set_money(STATS_DM->get_gold_medium());
    move_object(gold,this_object());

    album = clone_object("/players/mizan/opl/beasties/fungus/vampires/album.c");
    move_object(album, this_object());

    if (1 == random(5)) set_random_move_time(10);
}


heart_beat()
{
    ::heart_beat();
    if (attacker_ob && 1 == random(5)) insult();
    else if (!attacker_ob && 1 == random(15)) idlechat();
}

insult()
{
    string result;
    result = query_name() + " says: " + SHAKESPEARE_DM->query_insult() + "\n";
    say(result);
}

idlechat()
{
    string result;
    result = query_name() + " " + VAMPIRE_DM->get_male_vampire_chat() + "\n";
    say(result);
}
