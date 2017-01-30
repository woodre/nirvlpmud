/*****************************************************************************
 *      File:                   gundroid.c
 *      Function:               
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:                 
 *      Change History:         A cut down version of the fusion octotron.
 ****************************************************************************/
inherit "/players/mizan/opl/core/vehicle-creature.c";
#include "/players/mizan/opl/definitions.h"
#include "/obj/ansi.h"

#define ATTACK_ROUNDS      9
/* each head is worth this amount in HP. The total hp is HEAD_HP * 5 */
#define HEAD_HP            2000

#define DAM_BASE           50
#define DAM_RAND           100
#define HIT_PROB           2

/* hitpoints of the monster */
int hps;

/* the heads of this creature */
int head1, head2, head3;

/* which turn for which head to be attacking */
int t_head2, t_head3;


/*
 * our reset method
 *
 */
reset(arg)
{
    string tmp_ldesc;
    string tmp_long;
    object bin;
    object bin02;
    object op1,op2;
    object gold;

    tmp_ldesc = "    You are inside the claustrophobic confines of the Gundroid's hull.\n";
    tmp_ldesc+= "  It is hot, dimly lit, smelly, loud, and obviously not designed for\n";
    tmp_ldesc+= "  the likes of living creatures like you.\n";

    tmp_long = "    This terrible thing called the 'gundroid' is a tank-like monstrosity\n"+
               "  with not one but THREE turrets sticking out of it. Arranged in an awkward\n"+
               "  stacked layout much like a wedding cake, each gun has its own tracking and\n"+
               "  appears to be arranged by order of caliber- with the biggest sized one\n"+
               "  sitting on the bottom. While it may be ungainly and stupid to look at,\n"+
               "  don't let your guard down. This crazy thing is programmed to kill,\n"+
               "  and the killing business is very good indeed!\n";

    ::reset(arg);

    if (arg) return;


    set_name("Gundroid Mk. II");
    set_race("gundroid");
    set_alias("droid");
    set_short("A Gundroid, Mk. II");
    set_long(tmp_long);
    set_level(27);
    set_hp(6000);
    set_al(-300);
    set_wc(70);  /* comparatively weaker WC made up for special attacks */
    set_ac(45);

    /* aggressive monster bonus, and strong attack bonus */
    set_hp_bonus(STATS_DM->get_hp_bonus_easy() * 2);

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 2;

    if(1 == random(4)) set_aggressive(1);
    else set_aggressive(0);

    set_hatch_id("hatch");
    set_maximum_fuel(50);
    set_maximum_occupants(8);

    set_key_id("gundroid_key");
    set_engine_key_id("gundroid_enginekey");
    set_fuel(50);
    set_fuel_id("diesel_fuel");
    set_inside_short_desc("Inside a Gundroid, Mk. II");
    set_inside_long_desc(tmp_ldesc);
    set_exit_mess("leaves with tracks clanking, rumbling");
    set_enter_mess("arrives, its tracks clanking loudly");

    set_engine_startup_message("The Gundroid's diesel turbine engine starts up with a whiny scream\n");
    set_engine_stop_message("The Gundroid's diesel turbine shuts off.\nSuddenly, there is silence...\n");

    set_fuel_idle_consumption(20);
    set_fuel_overflow_mess("The tank is full, and some extra diesel fuel gushes out.\n");


    enable_headlights();
    set_battery_id("gundroid_battery");

    set_headlight_consumption(40);
    set_maximum_battery(50);


    if(!bin) bin = move_object(clone_object("/obj/bag.c"), this_object());
    
    move_object(clone_object("/players/mizan/opl/vehicles/fuel/diesel_can.c"), this_object());

    /* an array of engine noise messages */
    arr_engine_chat_mess = ( {
        "The engine of the Gundroid revs with a horrid whine.",
        "The Gundroid's engine spools up and pulses its throttle briefly.",
    });

    set_idle_chat_chance(1);
    set_engine_chat_chance(1);

    enable_commands();

    t_head2 = 1;
    t_head3 = 1;

    head1 = 0;
    head2 = 0;
    head3 = 0;

    op1 = clone_object("/players/mizan/opl/beasties/easy/cobold.c"), this_object();
    op1->set_aggressive(1);
    move_object(op1, this_object());
    command("be driver", op1);

    op2 = clone_object("/players/mizan/opl/beasties/easy/cobold.c"), this_object();
    op2->set_aggressive(1);
    move_object(op2, this_object());

    gold = clone_object("obj/money");
    gold->set_money(10000);
    move_object(gold, bin);

}
/* end function reset(); */

init()
{
    object room;

    if (!this_player()) return;

    room = environment(this_player());

    if (room &&
            room == environment(this_object()) &&
            this_player()->is_player() &&
            this_player()->query_level() < 20 &&
            !this_player()->query_invis())
    {
        say(HIW + "The Gundroid's infared sensors turn to target " + this_player()->query_name() + "!\n" + NORM);
        this_object()->attack_object(this_player());
    }

    ::init();
}


long()
{
    ::long();
    write(extra_look());
}


heart_beat()
{
    int dam;
    object attacker,room, ob, oc;
    string attacker_name;


    /* Setup some vars */
    hps = this_object()->query_hp();
    room = environment(this_object());
    attacker = this_object()->query_attack();

    if (attacker)
    {

        /* get some chats fired off */
        if(1 == random(5)) 
        {
            tell_room(room, "The Gundroid says: " + HIW + GUNDROID_DM->get_gundroid_insult() + NORM + "\n");
        }


        attacker_name = attacker->query_name();

        if (environment(attacker) == room)
        {
            /* HEAD ONE ATTACK */
            if (head1 == 0 && environment(attacker) == room && !attacker->query_ghost())
            {
                /*
                 * The 9.64mm turret ATTACKS
                 *
                 */
                tell_room(room, HIY + "\nBLAM! BLAM! BLAM! BLAM!\n" + NORM);
                if (1 == random(HIT_PROB))
                {
                    dam = random(DAM_RAND / 2) + DAM_BASE / 3;
                    tell_room(room, "The " + HIY + "9.64mm snapgun" + NORM + " turret " + GUNDROID_DM->get_gundroid_st_attack_message() + " at " + capitalize(attacker_name) + ".\n");
                    attacker->hit_player(dam, "fire");
                }
                else {
                    tell_room(room,"The " + HIY + "9.64mm snapgun" + NORM + " turret missed "+capitalize(attacker_name)+".\n");
                }

                if (hps < (HEAD_HP * 2)) {
                    head1 = 1;
                    tell_room(room,"The " + HIY + "9.64mm snapgun" + NORM + " turret is destroyed!\n");
                    attacker->add_exp(50000);
                }

            }

            /* END HEAD ONE ATTACK */



            /* HEAD TWO ATTACK */
            if (head2 == 0 && t_head2 > 3 && environment(attacker) == room && !attacker->query_ghost())
            {
                /*
                 * The 20mm slugthrower
                 *
                 */

                if (1 == random(HIT_PROB))
                {
                    dam = random(DAM_RAND) + DAM_BASE;
                    tell_room(room, HIY + "\nBLAM! BLAM!\n" + NORM);
                    tell_room(room, "The " + HIB + "20mm slugthrower" + NORM + " turret " + GUNDROID_DM->get_gundroid_mt_attack_message() + " at " +  capitalize(attacker_name) + ".\n");
                    attacker->hit_player(dam, "fire");
                }
                else {
                    tell_room(room,"The " + HIB + "20mm slugthrower" + NORM + " turret missed "+capitalize(attacker_name)+".\n");
                }
                if (hps < (HEAD_HP)) {
                    head2 = 1;
                    tell_room(room,"The " + HIB + "20mm slugthrower" + NORM + " turret is destroyed!\n");
                    attacker->add_exp(50000);
                }

                t_head2 = 0;
            }
            else if (t_head2 == 2)
            {
                /* tell the room of impending doom */
                tell_room(room, "You see the " + HIB + "20mm slugthrower" + NORM + " turret rotate and lock on to your direction...\n");
                t_head2 ++;
            }
            else t_head2 ++;

            /* END HEAD TWO ATTACK */




            /* HEAD THREE ATTACK */
            if (head3 == 0 && t_head3 > 6 && environment(attacker) == room && !attacker->query_ghost())
            {
                /*
                 * The 40mm scattergun
                 * Unlike the other attacks- this one does not miss.
                 */

                dam = random(50) + 60;
                tell_room(room, "The " + HIR + "44mm scattergun" + NORM + " turret " + GUNDROID_DM->get_gundroid_lt_attack_message() + " in your general direction.\n");
                ob = first_inventory(room);
                while (ob)
                {
                    oc = next_inventory(ob);
                    if (ob->is_living() && ob != this_object())
                    {
                        tell_room(room, ob->query_name() + " " + GUNDROID_DM->get_gundroid_lt_attack_detail() + "\n");
                        ob->hit_player(dam, "fire");
                    }
                    ob = oc;
                }

                if (hps < 50) {
                    head3 = 1;
                    tell_room(room,"The " + HIR + "44mm scattergun" + NORM + " turret is destroyed!\n");
                    attacker->add_exp(50000);
                }

                t_head3 = 0;
            }
            else if (t_head3 == 5)
            {
                /* tell the room of impending doom */
                tell_room(room, "You see the " + HIR + "44mm scattergun" + NORM + " turret train and lock in your general direction...\n");
                t_head3 ++;
            }
            else t_head3 ++;

            /* END HEAD THREE ATTACK */



        }
    }
    ::heart_beat();
}


extra_look()
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

    return "The " + HIY + "9.64mm snapgun" + NORM + " turret is " + desc1 + "\n" +
           "The " + HIB + "20mm slugthrower" + NORM + " turret is " + desc2 + "\n" +
           "The " + HIR + "44mm scattergun" + NORM + " turret is " + desc3 + "\n";
}


/**
 * We don't wimpy.
 *
 */
run_away() {
    return 0;
}
