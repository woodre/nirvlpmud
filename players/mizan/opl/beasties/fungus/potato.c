inherit "/players/mizan/opl/core/monster.c";
#include "/players/mizan/opl/definitions.h"
#include "/obj/ansi.h"
/*
 * This is a 'normal' monster within the maze.
 *
 *
 */

int joke_index;

reset(arg)
{
    object gold, bag, weapon;
    string my_name;

    ::reset(arg);
    if (arg) return;


    set_name("giant potato");
    set_race("potato");
    set_short("A giant, animated potato");
    set_long("The fungal forest must do some pretty strange things to the crops. Standing\n"+
             "before you is a massive, living potato which is probably about 8 feet tall.\n"+
             "No, you are not hallucinating, and yes, this guy will be probably somewhat\n"+
             "hard to take down- even though he... it... whatever... is a potato.\n");
    set_level(STATS_DM->get_level_medium());
    set_hp(STATS_DM->get_hp_medium());
    set_al(0);
    set_wc(STATS_DM->get_wc_medium());
    set_ac(STATS_DM->get_ac_medium());
    set_chance(10);
    set_spell_dam(200);
    set_heal(70,3);

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 2;

    set_spell_mess1(short() + " surprises you with a complex... rolling... attack.\n");
    set_spell_mess2(short() + " struck you with a cone of sound.\nHow the... what the... where the hell did a POTATO learn to do that???\n");

    gold = clone_object("obj/money");
    gold->set_money(STATS_DM->get_gold_medium());
    move_object(gold,this_object());

    if (1 == random(3))
    {
        bag = clone_object("/obj/bag.c");
        move_object(bag, this_object());
        weapon = clone_object("/players/mizan/opl/items/plexiglas_staff.c");
        move_object(weapon, bag);
    }

    if (1 == random(5)) set_random_move_time(10);
    if (1 == random(10))
    {
        set_aggressive(1);
        /* aggressive monster bonus */
        set_hp_bonus(STATS_DM->get_hp_bonus_medium() + 400);
    }
    else
    {
        set_hp_bonus(STATS_DM->get_hp_bonus_medium());
    }
}


heart_beat()
{
    ::heart_beat();
    if (attacker_ob && 1 == random(3)) insult();
    else if (!attacker_ob && 1 == random(10) && find_call_out("blonde_punchline") < 1) blonde_joke();

    if(attacker_ob && 1 == random(3)) smash_pets();
}

insult()
{
    string result;
    result = query_name() + " says: " + HIY + MAMASNAPS_DM->query_snap() + NORM + "\n";
    say(result);
}


blonde_joke()
{
    string result;
    joke_index = BLONDEJOKES_DM->get_joke_index();
    if(joke_index < 2 || BLONDEJOKES_DM->query_joke(joke_index) == "") return;

    result = query_name() + " asks: " + HIY + BLONDEJOKES_DM->query_joke(joke_index) + NORM + "\n";
    say(result);

    remove_call_out("blonde_punchline");
    call_out("blonde_punchline", 8);
}

blonde_punchline()
{
    string result;

    result = (query_name() + " exclaims: " + HIY + BLONDEJOKES_DM->query_joke(joke_index + 1) + NORM + "\n");
    say(result);
}

smash_pets()
{
    object pet;

    if(!environment(this_object())) return;
    pet = present("pet", environment(this_object()));
    if(pet && pet->is_pet())
    {
        say(HIY + "The Giant Potato rolls clear over " + pet->query_name() + "!\n" + NORM);
        say(pet->query_name() + " embraces Death's solemn kiss.\n");
        destruct(pet);
    }
}

