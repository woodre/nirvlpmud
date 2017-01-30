/*****************************************************************************
 *      File:                   hydra-blocker.c
 *      Function:               General purpose annoying monster
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:
 *      Change History:
 *
 ****************************************************************************/
inherit "/players/mizan/opl/core/monster.c";
#include "/players/mizan/opl/definitions.h"

int head1,head2,head3,head4,head5;
int hps;

/* Based pretty much on Sweetness' code.
 * Pretty much all of it, that is.
 *
 * This stuff is credited elsewhere though.
 */

reset(arg) {
    object weapon;
    object gold;
    ::reset(arg);
    if (arg) return;
    set_name("hydra");
    set_race("dragon");
    set_alias("hydra");
    set_short("Hydra");
    set_level(29);
    set_hp(5000);
    set_al(-1000);
    set_wc(85);
    set_ac(65);
    set_aggressive(1);
    set_heal(75,3);
    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 2;

    /* aggressive monster bonus, blocker bonus */
    set_hp_bonus(STATS_DM->get_hp_bonus_medium() + 1000);

    gold = clone_object("obj/money");
    gold->set_money(random(6000) + 20000);
    move_object(gold,this_object());

    set_chance(15);
    set_spell_mess1(query_name() + " hits you VERY hard!\n");
    set_spell_mess2(query_name() + " hits you with a BONE SHATTERING CRUNCH!\n");
    set_spell_dam(300);

    enable_commands();

    set_block_exits(1);
}

long()
{
    write("This is a five-headed Hydra.\n");
    write("It's big, angry, smelly, and mean.\n");
    write(extra_long());
}

heart_beat()
{
    int dam;
    object attacker,room;
    string attacker_name;

    hps=this_object()->query_hp();
    room=environment(this_object());
    attacker=this_object()->query_attack();

    ::heart_beat();

    if (attacker) {
        attacker_name=attacker->query_real_name();
        if (present(attacker_name,environment(this_object()))) {
            if (head1 == 0 && !attacker->query_ghost()) {
                if (1 == random(2)) {
                    tell_room(room,"The head of electricity slams a lightning bolt at "+capitalize(attacker_name)+".\n");
                    dam=random(100);
                    attacker->hit_player(dam, "other|lightning");
                }
                else {
                    tell_room(room,"The head of electricity missed "+capitalize(attacker_name)+".\n");
                }
                if (this_object()->query_hp() < 4000) {
                    head1 = 1;
                    tell_room(room,"The head of electricity is destroyed!\n");
                    attacker->add_exp(3000);
                }
            }

            if (head2 == 0 && !attacker->query_ghost()) {
                if (1 == random(3)) {
                    tell_room(room,"The head of frost shoots a freezing blast at "+capitalize(attacker_name)+".\n");
                    dam=random(60);
                    attacker->hit_player(dam, "other|cold");
                }
                else {
                    tell_room(room,"The head of frost missed "+capitalize(attacker_name)+".\n");
                }
                if (this_object()->query_hp() < 3000) {
                    head2 = 1;
                    tell_room(room,"The head of frost is destroyed!\n");
                    attacker->add_exp(4000);
                }
            }

            if (head3 == 0 && !attacker->query_ghost()) {
                if (1 == random(3)) {
                    tell_room(room,"The head of acid belches boiling acid at "+capitalize(attacker_name)+".\n");
                    dam=random(85);
                    attacker->hit_player(dam, "other|acid");
                }
                else {
                    tell_room(room,"The head of acid missed "+capitalize(attacker_name)+".\n");
                }
                if (this_object()->query_hp() < 2000) {
                    head3 = 1;
                    tell_room(room,"The head of acid is destroyed!\n");
                    attacker->add_exp(5000);
                }
            }

            if (head4 == 0 && !attacker->query_ghost()) {
                if (1 == random(2)) {
                    tell_room(room,"The head of fire blows a blast of flame at "+capitalize(attacker_name)+".\n");
                    dam=random(140);
                    attacker->hit_player(dam, "fire");
                }
                else {
                    tell_room(room,"The head of fire missed "+capitalize(attacker_name)+".\n");
                }
                if (this_object()->query_hp() < 1000) {
                    head4 = 1;
                    tell_room(room,"The head of fire is destroyed!\n");
                    attacker->add_exp(5000);
                }
            }

            if (head5 == 0 && !attacker->query_ghost()) {
                if (1 == random(2)) {
                    tell_room(room,"The head of death spews forth rotten corpses at "+capitalize(attacker_name)+".\n");
                    dam=random(110);
                    attacker->hit_player(dam, "other|poison");
                }
                else {
                    tell_room(room,"The head of death missed "+capitalize(attacker_name)+".\n");
                }
            }
        }
    }
}

extra_long() {
    string desc1,desc2,desc3,desc4,desc5;
    int hp;
    hp=this_object()->query_hp();
    desc1 = "in good shape.";
    desc2 = "in good shape.";
    desc3 = "in good shape.";
    desc4 = "in good shape.";
    desc5 = "in good shape.";
    if (hp < 5000) {
        desc1 = "slightly hurt.";
    }
    if (hp < 4500) {
        desc1 = "somewhat hurt.";
    }
    if (hp < 4250) {
        desc1 = "in bad shape.";
    }
    if (hp < 4000) {
        desc1 = "dead.";
        desc2 = "slightly hurt.";
    }
    if (hp < 3500) {
        desc2 = "somewhat hurt.";
    }
    if (hp < 3250) {
        desc2 = "in bad shape.";
    }
    if (hp < 3000) {
        desc2 = "dead.";
        desc3 = "slightly hurt.";
    }
    if (hp < 2500) {
        desc3 = "somewhat hurt.";
    }
    if (hp < 2250) {
        desc3 = "in bad shape.";
    }
    if (hp < 2000) {
        desc3 = "dead.";
        desc4 = "slightly hurt.";
    }
    if (hp < 1500) {
        desc4 = "somewhat hurt.";
    }
    if (hp < 1250) {
        desc4 = "in bad shape.";
    }
    if (hp < 1000) {
        desc4 = "dead";
        desc5 = "slightly hurt.";
    }
    if (hp <  500) {
        desc5 = "somewhat hurt.";
    }
    if (hp <  250) {
        desc5 = "somewhat hurt.";
    }
    if (hp <  100) {
        desc5 = "in very bad shape.";
    }
    return "The head of electricity is "+desc1+"\n"+"The head of frost is "+desc2+"\n"+
           "The head of acid is "+desc3+"\n"+"The head of fire is "+desc4+"\n"+"The head of death is "+desc5+"\n";
}
