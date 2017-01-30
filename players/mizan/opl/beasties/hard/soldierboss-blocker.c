inherit "/players/mizan/opl/core/monster.c";
#include "/players/mizan/opl/definitions.h"
#include "/obj/ansi.h"

reset(arg)
{
    object gold, radio;
    string my_name;

    ::reset(arg);
    if (arg) return;


    my_name = SOLDIER_DM->get_boss_name();

    set_name(my_name);
    set_race("soldier");
    set_alias(lower_case(my_name));
    set_short("A crazed soldier named " + my_name);
    set_long(
"    The thousand yard stare is something of a cliche description for those\n"+
"  combat veterans who simply have seen too much intense action. In this case\n"+
"  however you suspect the mental pain and anguish of this soldier was not\n"+
"  borne of combat, but of severely powerful and expensive medication.\n"+
"  Tread carefully, young one. This guy has problems.\n");
    set_level(STATS_DM->get_level_hard());
    set_hp(STATS_DM->get_hp_hard());
    set_al(0);
    set_wc(STATS_DM->get_wc_hard());
    set_ac(STATS_DM->get_ac_hard());
    set_heal(18,1);

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 3;

    set_hp_bonus(STATS_DM->get_hp_bonus_hard());

    gold = clone_object("obj/money");
    gold->set_money(STATS_DM->get_gold_hard());
    move_object(gold,this_object());

    radio = clone_object("players/mizan/mbv3/items/walkie-talkie.c");
    move_object(radio, this_object());

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
    result = query_name() + " says: " + HIR +  SOLDIER_DM->get_insult() + NORM + "\n";
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
        scarf = present("usa-lapel-pin", this_player());
        if(!scarf)
        {
            say(HIR + this_object()->short() + NORM + " turns to attack " + this_player()->query_name() + "!\n");
            this_object()->attack_object(this_player());
        }
        else
        {
            say(HIR + this_object()->short() + NORM + " glares at " +this_player()->query_name() + " menacingly.\n");
        }
    }
}

