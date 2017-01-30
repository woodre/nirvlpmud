/*****************************************************************************
 *      File:                   shoop.c
 *      Function:               Generic high level kill.
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:                  DONE.
 *      Change History:         
 *
 */
inherit "/players/mizan/opl/core/monster.c";
#include "/players/mizan/opl/definitions.h"
#include "/obj/ansi.h"


reset(arg)
{
    object gold;

    ::reset(arg);
    if (arg) return;

    set_name("stick figure person");
    set_race("stick figure");
    set_alias("person");
    set_alt_name("figure");
    set_short("A stick figure person");
    set_long("You blink and rub your eyes. What you are staring at makes no sense at all.\n"+
             "Lurking before you is a cartoon-like, two dimensional stick figure person,\n"+
             "whose body consists of thick lines. His... its... face featureless aside from\n"+
             "two pitch black eyes and a line mouth.\n");
    set_level(STATS_DM->get_level_hard());
    set_hp(STATS_DM->get_hp_hard());
    set_al(0);
    set_wc(STATS_DM->get_wc_hard());
    set_ac(STATS_DM->get_ac_hard());

    set_hp_bonus(STATS_DM->get_hp_bonus_hard());
    set_heal(19, 1);

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 3;

    gold = clone_object("obj/money");
    gold->set_money(STATS_DM->get_gold_hard());
    move_object(gold,this_object());

    if (1 == random(5)) set_random_move_time(10);
    if (1 == random(10)) set_aggressive(1);

}


heart_beat()
{
    object room;

    ::heart_beat();
    if (attacker_ob)
    {
        room = environment(this_object());

        if(1 == random(4) && !attacker_ob->query_ghost())
        {
            tell_room(room, HIY + "IMMA CHARGIN MAH LAZER!!!" + NORM + "\n");
            RANDOBJ_DM->render_shoop(room);
            attacker_ob->hit_player(100 + random(150), "fire");
        }
        else if(1 == random(4))
        {
            /* we hit the entire room */
            tell_room(room, HIY + "IMMA CHARGIN MAH LAZER AT Y'ALL!!!!" + NORM + "\n");
            RANDOBJ_DM->render_shoop(room);

            COMBAT_DM->do_room_hit(this_object(),
                40,
                50,
                "other|laser",
                HIW + "A blinding blast envelopes the room..." + NORM + "\n",
                "You are hit by the laser energy blast!\n",
                "is hit with a laser energy blast!\n",
                "knocks you off your feet!\n");
        }
    }

    else if(1 == random(10)) mamasnap();
}


mamasnap()
{
    string result;
    result = query_name() + " says: " + HIY + MAMASNAPS_DM->query_snap() + NORM + "\n";
    say(result);
}
