inherit "/players/mizan/opl/core/monster.c";
#include "/players/mizan/opl/definitions.h"
#include "/obj/ansi.h"


reset(arg)
{
    object gold;
    string my_name;

    ::reset(arg);
    if (arg) return;


    my_name = BUNNY_DM->get_rabbit_name();

    set_name(my_name + " the giant bunny");
    set_race("bunny");
    set_alias(lower_case(my_name));
    set_short(my_name  + HIC +  " the giant bunny" + NORM);
    set_long("This is a hulking, 9 foot tall, muscular monstrosity of what was once just\n"+
             "a cute and harmless little bunny rabbit. Your eyes shift to the jagged outline\n"+
             "of five inch claws on the front paws of this killing machine, and realize for\n"+
             "the first time that this is not a beast to be taken lightly by ANY means.\n");
    set_level(STATS_DM->get_level_medium());
    set_hp(STATS_DM->get_hp_medium());
    set_al(0);
    set_wc(STATS_DM->get_wc_medium());
    set_ac(STATS_DM->get_ac_medium());

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 2;

    set_heal(65, 3);
    set_chance(15);
    set_spell_dam(300);
    set_spell_mess1(short() + " hit you so hard that you might not live this one down.\n");
    set_spell_mess2(short() + " clobbers you with a clean double-hind Rabbit-fu kick. OUCH.\n");

    gold = clone_object("obj/money");
    gold->set_money(STATS_DM->get_gold_medium());
    move_object(gold,this_object());

    if (1 == random(5)) set_random_move_time(10);
    if (1 == random(10))
    {
        set_aggressive(1);
        /* aggressive monster bonus */
        set_hp_bonus(STATS_DM->get_hp_bonus_medium() + 100);
    }
    else
    {
        set_hp_bonus(STATS_DM->get_hp_bonus_medium());
    }
}


heart_beat()
{
    ::heart_beat();
    if (attacker_ob && 1 == random(10)) mamasnap();
}

mamasnap()
{
    string result;
    result = query_name() + " says: " + HIC + MAMASNAPS_DM->query_snap() + NORM + "\n";
    say(result);
}
