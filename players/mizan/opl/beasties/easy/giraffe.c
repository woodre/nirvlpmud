/*****************************************************************************
 *      File:                   giraffe.c
 *      Function:               Annoying three headed cockblocker
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:                  DONE.
 *      Change History:
 *
 ****************************************************************************/

inherit "/players/mizan/opl/core/monster.c";
#include "/players/mizan/opl/definitions.h"
int head1,head2,head3;
int hps;

#define HEAD_HP 1500


reset(arg)
{
    object weapon;
    object gold;
    ::reset(arg);
    if (arg) return;
    set_name("three headed giraffe");
    set_race("giraffe");
    set_alias("three headed");
    set_short("A three headed giraffe");
    set_level(25);
    set_hp(4500);
    set_al(-100);
    set_wc(88);
    set_ac(40);
    set_aggressive(0);
    gold = clone_object("obj/money");
    gold->set_money(random(1000) + 4500);

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 1;

    /* multiple head attack bonus */
    set_hp_bonus(STATS_DM->get_hp_bonus_easy() + 1000);

    /* This monster cannot heal, or it kind of messes up the extra heads. So it has more HP */

    move_object(gold,this_object());
    weapon = clone_object("players/mizan/opl/heals/turboburrito.c");
    move_object(weapon,this_object());

    set_block_exits(1);
    enable_commands();
}

long() {
    write("This is a three headed giraffe. Nothing really unusual to report here,\n"+
          "as it is positively certain that you encounter something like this\n"+
          "practically every single day. Otherwise, it's a really scary looking\n"+
          "creature, and seems to have some rather unpleasant odors near it.\n" + extra_long());
}

heart_beat() {
    int dam;
    object attacker,room;
    string attacker_name;
    ::heart_beat();
    hps = this_object()->query_hp();
    room = environment(this_object());
    attacker=this_object()->query_attack();
    if (attacker) 
    {
        attacker_name=attacker->query_real_name();

        if (present(attacker_name,environment(this_object()))) 
        {
            if (head1 == 0) {
                if (1 == random(2) && !attacker->query_ghost()) 
                {
                    tell_room(room,"The ugly head spits vomit at "+capitalize(attacker_name)+".\n");
                    dam = random(130);
                    attacker->hit_player(dam, "other|sleaze");
                }
                else {
                    tell_room(room,"The ugly head missed "+capitalize(attacker_name)+".\n");
                }
                if (this_object()->query_hp() < (HEAD_HP * 2)) {
                    head1 = 1;
                    tell_room(room,"The ugly head explodes!\n");
                    if (!attacker->query_ghost()) attacker->add_exp(90000);
                }
            }
            if (head2 == 0) {
                if (1 == random(2) && !attacker->query_ghost()) {
                    tell_room(room,"The goofy-looking head spits bile at "+capitalize(attacker_name)+".\n");
                    dam = random(130);
                    attacker->hit_player(dam, "acid");
                }
                else {
                    tell_room(room,"The goofy-looking head missed "+capitalize(attacker_name)+".\n");
                }
                if (this_object()->query_hp() < HEAD_HP) {
                    head2 = 1;
                    tell_room(room,"The goofy-looking head is destroyed.\n");
                    if (!attacker->query_ghost()) attacker->add_exp(90000);
                }
            }
            if (head3 == 0) {
                if (1 == random(2) && !attacker->query_ghost()) {
                    tell_room(room,"The smelly head spits poop at "+capitalize(attacker_name)+".\n");
                    dam = random(150);
                    attacker->hit_player(dam, "poop");
                }
                else {
                    tell_room(room,"The smelly head missed "+capitalize(attacker_name)+".\n");
                }
                if (this_object()->query_hp() < 100) {
                    head3 = 1;
                    tell_room(room,"The smelly head explodes.\n");
                    if (!attacker->query_ghost()) attacker->add_exp(90000);
                }
            }
        }
    }
}

extra_long()
{
    string desc1, desc2, desc3;
    int hp;
    hp = this_object()->query_hp();

    desc1 = "in good shape.";
    desc2 = "in good shape.";
    desc3 = "in good shape.";

    if (hp < (HEAD_HP * 2)) desc1 = "slightly damaged.";

    if (hp < (HEAD_HP * 2) + (HEAD_HP / 4) * 3) desc1 = "somewhat damaged.";
    if (hp < (HEAD_HP * 2) + (HEAD_HP / 4)) desc1 = "in bad shape.";
    if (hp < (HEAD_HP * 2)) {
        desc1 = "destroyed.";
        desc2 = "slightly damaged.";
    }

    if (hp < HEAD_HP + (HEAD_HP / 4) * 3) desc2 = "somewhat damaged.";
    if (hp < HEAD_HP + (HEAD_HP / 4)) desc2 = "in bad shape.";
    if (hp < HEAD_HP) {
        desc2 = "destroyed.";
        desc3 = "slightly damaged.";
    }

    if (hp < (HEAD_HP / 4) * 3) desc3 = "somewhat damaged.";
    if (hp < (HEAD_HP / 4)) desc3 = "in bad shape.";
    if (hp < (HEAD_HP / 8)) desc3 = "in very bad shape.";

    return "The ugly head is " + desc1 + "\n" +
           "The goofy-looking head is " + desc2 + "\n" +
           "The smelly head is " + desc3 + "\n";
}


