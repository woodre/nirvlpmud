inherit "/players/mizan/opl/core/monster.c";
#include "/players/mizan/opl/definitions.h"
#include "/obj/ansi.h"

reset(arg)
{
    object gold;
    string my_name;

    ::reset(arg);
    if (arg) return;


    my_name = POSTAL_DM->get_name();

    set_name(lower_case(my_name));
    set_race("human");
    set_alias("worker");
    set_short("A " + HIW + "crazed postal worker" + NORM + " named " + my_name);
    set_long(
    "    Years of government service under psychologically troubling conditions\n"+
    "  will yield you cold-blooded wackjobs by the dozens. It looks like this year\n"+
    "  is set for a bumper crop of crazy- this fine middle-aged specimen is a prime\n"+
    "  example... nearing his retirement, and looking forward to a pension, he is\n"+
    "  drawn into a state of deep depression as it became news that his branch office\n"+
    "  is facing the prospect of a drawdown and sudden closure.\n\n"+
    "  Ergo... he is now here, given a new lease on life, with the option to come\n"+
    "  try to hunt you down and beat you to a bloody mess, or worse.\n");

    set_level(STATS_DM->get_level_hard());
    set_hp(STATS_DM->get_hp_hard() + 3500);
    set_al(0);
    set_wc(STATS_DM->get_wc_hard());
    set_ac(STATS_DM->get_ac_hard());

    set_heal(20,1);

    set_chance(15);
    set_spell_mess1(query_name() + " hits you VERY hard!\n");
    set_spell_mess2(query_name() + " hits you with a BONE SHATTERING CRUNCH!\n");
    set_spell_dam(200);

    /* These guys are ALWAYS aggro */
    set_aggressive(1);

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 3;

    set_hp_bonus(STATS_DM->get_hp_bonus_hard());

    set_chat_chance(5);
    load_chat(my_name + " picks his nose.\n");
    load_chat(my_name + " scratches his butt.\n");
 
    gold = clone_object("obj/money");
    gold->set_money(STATS_DM->get_gold_hard());
    move_object(gold,this_object());

    if (1 == random(5)) set_random_move_time(15);
}


heart_beat()
{
    ::heart_beat();
    if (attacker_ob && 1 == random(3)) insult();
}

insult()
{
    string result;
    result = format(query_name() + " " + POSTAL_DM->get_insult() + NORM, 92);
    say(result);
}

