/*****************************************************************************
 *      File:                   fusion_octotron.c
 *      Function:               High value, high annoyance, exit blocking mob.
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:                 
 *      Change History:         Merged from hydra and tiger1 tank.
 *
 * The intent of this creature is to give players a very bad day.
 * Just because I am a sick bastard, I made it sing Broadway show tunes
 * while fighting as well.
 *
 *****************************************************************************/
inherit "/players/mizan/opl/core/vehicle-creature.c";
#include "/obj/ansi.h"

#define ATTACK_ROUNDS      24
/* each head is worth this amount in HP. The total hp is HEAD_HP * 5 */
#define HEAD_HP            3000

#define DAM_BASE           150
#define DAM_RAND           200
#define HIT_PROB           2

/* hitpoints of the monster */
int hps;

/* the heads of this creature */
int head1, head2, head3, head4, head5, head6, head7, head8;

/* which turn for which head to be attacking */
int t_head1, t_head2, t_head3, t_head4, t_head5, t_head6, t_head7, t_head8;



/*
 * our reset method
 *
 */
reset(arg)
{
    string tmp_ldesc;
    string tmp_long;
    object bin;
    object bin02, op1, op2, op3, op4;

    tmp_ldesc = "    You are inside the surprisingly spacious confines of the Fusion\n";
    tmp_ldesc+= "  Octotron hull. It is dimly lit but neatly arranged, presumably\n";
    tmp_ldesc+= "  because living creatures are not assumed to be inside the hull for\n";
    tmp_ldesc+= "  any reason. The air tastes metallic and bitter here...\n";

    tmp_long = "    The Fusion Octotron sitting before you is the definitive example of the\n"+
               "  of the phrase 'robotic hate machine', or 'mechanical deathgiving device'.\n"+
               "  The Octotron is a giant tracked robot on a chassis similar to that of a\n"+
               "  tank, and in place of a gun turret there is a giant armored stump from\n"+
               "  which eight segmented mechanical arms are housed in swiveling mounts.\n"+
               "  Attached to each arm is a different creature-killing weapon of some sort.\n"+
               "  It would be a safe assessment that the Fusion Octotron does not like you.\n";

    ::reset(arg);

    if (arg) return;


    set_name("Fusion Octotron");
    set_race("octotron");
    set_alias("robot");
    set_short("A Fusion Octotron, Mark III");
    set_long(tmp_long);
    set_level(29);
    set_hp(24000);
    set_al(-800);
    set_wc(90);
    set_ac(55);
    set_heal(69, 3);

    set_chance(15);
    set_spell_mess1(query_name() + " hits you VERY hard!\n");
    set_spell_mess2(query_name() + " hits you with a BONE SHATTERING CRUNCH!\n");
    set_spell_dam(300);
 
    if(1 == random(3)) set_aggressive(1);

    set_hatch_id("hatch");
    set_maximum_fuel(150);
    set_maximum_occupants(8);

    set_key_id("fusion_octotron_key");
    set_engine_key_id("fusion_octotron_enginekey");
    set_fuel(50);
    set_fuel_id("energon_fuel");
    set_inside_short_desc("Inside a Fusion Octotron Mk. III");
    set_inside_long_desc(tmp_ldesc);
    set_exit_mess("leaves with tracks clanking, rumbling");
    set_enter_mess("arrives, its tracks clanking like the sound of mechanical death.");

    set_engine_startup_message("The Fusion Octotron's turbine engine starts up with a terrifying scream!\nssshhhhhrrRRRRREEEEEEAAAAAAA!!!!!!\n");
    set_engine_stop_message("The Fusion Octotron's turbine suddenly cuts out.\nSuddenly, there is silence...\n");

    set_fuel_idle_consumption(20);
    set_fuel_overflow_mess("The tank is full, and some extra diesel fuel gushes out.\n");

    op1 = clone_object("/players/mizan/opl/beasties/easy/cobold.c"), this_object();
    op1->set_aggressive(1);
    move_object(op1, this_object());
    command("be driver", op1);

    op2 = clone_object("/players/mizan/opl/beasties/easy/cobold.c"), this_object();
    op2->set_aggressive(1);
    move_object(op2, this_object());
    command("be passenger", op2);

    op3 = clone_object("/players/mizan/opl/beasties/easy/cobold.c"), this_object();
    op3->set_aggressive(1);
    move_object(op3, this_object());

    op4 = clone_object("/players/mizan/opl/beasties/easy/cobold.c"), this_object();
    op4->set_aggressive(1);
    move_object(op4, this_object());

    /* ridiculous attack bonus */
    set_hp_bonus("/players/mizan/opl/daemons/statsDM.c"->get_hp_bonus_hard() + 15000);

    enable_headlights();
    set_battery_id("fusion_octotron_battery");

    set_headlight_consumption(40);
    set_maximum_battery(50);

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 3;

    move_object(clone_object("/players/mizan/opl/vehicles/fuel/energon_bunker.c"), this_object());

    /* an array of engine noise messages */
    arr_engine_chat_mess = ( {
        "The turbine engine of the Fusion Octotron revs with a frightening whine.",
        "The Fusion Octotron's engine spools up and pulses its throttle briefly.",
    });

    set_idle_chat_chance(1);
    set_engine_chat_chance(1);

    enable_commands();

    t_head1 = 21;
    t_head2 = 18;
    t_head3 = 15;
    t_head4 = 12;
    t_head5 = 9;
    t_head6 = 6;
    t_head7 = 3;
    t_head8 = 1;

    head1 = 0;
    head2 = 0;
    head3 = 0;
    head4 = 0;
    head5 = 0;
    head6 = 0;
    head7 = 0;
    head8 = 0;

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
        say(HIW + "The Fusion Octotron's proximity sensors turn to target " + this_player()->query_name() + "!\n" + NORM);
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
        attacker_name = attacker->query_name();

        if (environment(attacker) == room)
        {
            /* HEAD ONE ATTACK */
            if (head1 == 0 &&
                t_head1 > ATTACK_ROUNDS &&
                environment(attacker) == room &&
                !attacker->query_ghost())
            {
                /*
                 * The BUZZSAW ARM ATTACKS
                 *
                 */

                if (1 == random(HIT_PROB))
                {
                    dam = random(DAM_RAND) + DAM_BASE;
                    tell_room(room, "The " + HIY + "electric buzzsaw" + NORM + " arm rips viciously at " + capitalize(attacker_name) + ".\n");
                    attacker->hit_player(dam, "other|blades");
                }
                else {
                    tell_room(room,"The " + HIY + "electric buzzsaw" + NORM + " arm missed "+capitalize(attacker_name)+".\n");
                }
                if (hps < (HEAD_HP * 7)) {
                    head1 = 1;
                    tell_room(room,"The " + HIY + "electric buzzsaw" + NORM + " arm is destroyed!\n");
                    attacker->add_exp(50000);
                }

                t_head1 = 0;
            }
            else if (t_head1 == (ATTACK_ROUNDS - 1))
            {
                /* tell the room of impending doom */
                tell_room(room, "You see the " + HIY + "electric buzzsaw" + NORM + " arm rear up for an impending strike...\n");
                t_head1 ++;
            }
            else t_head1 ++;

            /* END HEAD ONE ATTACK */



            /* HEAD TWO ATTACK */
            if (head2 == 0 &&
                t_head2 > ATTACK_ROUNDS &&
                environment(attacker) == room &&
                !attacker->query_ghost())
            {
                /*
                 * The MESON CANNON ATTACKS
                 *
                 */

                if (1 == random(HIT_PROB))
                {
                    dam = random(DAM_RAND) + DAM_BASE;
                    tell_room(room, "The " + HIB + "meson cannon" + NORM + " arm belches bitchingly nasty subatomic particles at " + capitalize(attacker_name) + ".\n");
                    attacker->hit_player(dam, "fire");
                }
                else {
                    tell_room(room,"The " + HIB + "meson cannon" + NORM + " arm missed "+capitalize(attacker_name)+".\n");
                }
                if (hps < (HEAD_HP * 6)) {
                    head2 = 1;
                    tell_room(room,"The " + HIB + "meson cannon" + NORM + " arm is destroyed!\n");
                    attacker->add_exp(50000);
                }

                t_head2 = 0;
            }
            else if (t_head2 == (ATTACK_ROUNDS - 1))
            {
                /* tell the room of impending doom */
                tell_room(room, "You see the " + HIB + "meson cannon" + NORM + " arm rear up for an impending strike...\n");
                t_head2 ++;
            }
            else t_head2 ++;

            /* END HEAD TWO ATTACK */




            /* HEAD THREE ATTACK */
            if (head3 == 0 && 
                t_head3 > ATTACK_ROUNDS &&
                environment(attacker) == room &&
                !attacker->query_ghost())
            {
                /*
                 * The NAPALM FLAMETHROWER ATTACKS
                 * Unlike the other attacks- this one does not miss.
                 */

                dam = random(50) + 60;
                tell_room(room, "The " + HIR + "napalm flamethrower" + NORM + " arm belches a conflaguration of bubbling, burning napalm!\n");
                ob = first_inventory(room);
                while (ob)
                {
                    oc = next_inventory(ob);
                    if (ob->is_living() && ob != this_object())
                    {
                        tell_room(room, ob->query_name() + " is hit by the wave of burning napalm!\n");
                        ob->hit_player(dam, "fire");
                    }
                    ob = oc;
                }

                if (hps < (HEAD_HP * 5)) {
                    head3 = 1;
                    tell_room(room,"The " + HIR + "napalm flamethrower" + NORM + " arm is destroyed!\n");
                    attacker->add_exp(50000);
                }

                t_head3 = 0;
            }
            else if (t_head3 == (ATTACK_ROUNDS - 1))
            {
                /* tell the room of impending doom */
                tell_room(room, "You see the " + HIR + "napalm flamethrower" + NORM + " arm rear up for an impending strike...\n");
                t_head3 ++;
            }
            else t_head3 ++;

            /* END HEAD THREE ATTACK */





            /* HEAD FOUR ATTACK */
            if (head4 == 0 &&
                t_head4 > ATTACK_ROUNDS &&
                environment(attacker) == room &&
                !attacker->query_ghost())
            {
                /*
                 * The ION BEAMER ATTACKS
                 *
                 */

                if (1 == random(HIT_PROB))
                {
                    dam = random(DAM_RAND) + DAM_BASE;
                    tell_room(room, "The " + HIG + "ion beamer" + NORM + " fires a pulse of blinding green light at " + capitalize(attacker_name) + ".\n");
                    attacker->hit_player(dam, "other|laser");
                }
                else {
                    tell_room(room,"The " + HIG + "ion beamer" + NORM + " arm missed "+capitalize(attacker_name)+".\n");
                }
                if (hps < (HEAD_HP * 4)) {
                    head4 = 1;
                    tell_room(room,"The " + HIG + "ion beamer" + NORM + " arm is destroyed!\n");
                    attacker->add_exp(50000);
                }

                t_head4 = 0;
            }
            else if (t_head4 == (ATTACK_ROUNDS - 1))
            {
                /* tell the room of impending doom */
                tell_room(room, "You see the " + HIG + "ion beamer" + NORM + " rear up for an impending strike...\n");
                t_head4 ++;
            }
            else t_head4 ++;

            /* END HEAD FOUR ATTACK */


            /* HEAD FIVE ATTACK */
            if (head5 == 0 &&
                t_head5 > ATTACK_ROUNDS &&
                environment(attacker) == room &&
                !attacker->query_ghost())
            {
                /*
                 * This arm has a special attack which 'freezes' a player for 6 rounds.
                 *
                 */

                if (1 == random(HIT_PROB))
                {
                    dam = random(DAM_RAND) + DAM_BASE;
                    tell_room(room, "The " + HIB + "cryo pulverizer" + NORM + " arm emits a freeze ray " + capitalize(attacker_name) + ".\n");
                    attacker->hit_player(dam, "cold");
                }
                else {
                    tell_room(room,"The " + HIB + "cryo pulverizer" + NORM + " arm missed "+capitalize(attacker_name)+".\n");
                }
                if (hps < (HEAD_HP * 3)) {
                    head5 = 1;
                    tell_room(room,"The " + HIB + "cryo pulverizer" + NORM + " arm is destroyed!\n");
                    attacker->add_exp(50000);
                }

                t_head5 = 0;
            }
            else if (t_head5 == (ATTACK_ROUNDS - 1))
            {
                /* tell the room of impending doom */
                tell_room(room, "You see the " + HIB + "cryo pulverizer" + NORM + " arm rear up for an impending strike...\n");
                t_head5 ++;
            }
            else t_head5 ++;

            /* END HEAD FIVE ATTACK */



            /* HEAD SIX ATTACK */
            if (head6 == 0 &&
                t_head6 > ATTACK_ROUNDS &&
                environment(attacker) == room &&
                !attacker->query_ghost())
            {
                /*
                 * This arm has a secondary attack which searches out kids.
                 *
                 */

                if (1 == random(HIT_PROB))
                {
                    dam = random(DAM_RAND) + DAM_BASE;
                    tell_room(room, "The " + HIR + "heat-seeking slicerdicer" + NORM + " arm cuts loose a scorching conflaguration of fire at " + capitalize(attacker_name) + ".\n");
                    attacker->hit_player(dam, "fire");
                }
                else {
                    tell_room(room,"The " + HIR + "heat-seeking slicerdicer" + NORM + " arm missed "+capitalize(attacker_name)+".\n");
                }
                if (hps < (HEAD_HP * 2)) {
                    head6 = 1;
                    tell_room(room,"The " + HIR + "heat-seeking slicerdicer" + NORM + " arm is destroyed!\n");
                    attacker->add_exp(50000);
                }

                t_head6 = 0;
            }
            else if (t_head6 == (ATTACK_ROUNDS - 1))
            {
                /* tell the room of impending doom */
                tell_room(room, "You see the " + HIR + "heat-seeking slicerdicer" + NORM + " arm rear up for an impending strike...\n");
                t_head6 ++;
            }
            else t_head6 ++;

            /* END HEAD SIX ATTACK */


            /* HEAD SEVEN ATTACK */
            if (head7 == 0 &&
                t_head7 > ATTACK_ROUNDS &&
                environment(attacker) == room &&
                !attacker->query_ghost())
            {
                /*
                 * The Tungsten Slugthrower arm has a wimpy effect once it connects
                 *
                 */

                if (1 == random(HIT_PROB))
                {
                    dam = random(DAM_RAND) + DAM_BASE;
                    tell_room(room, "The " + HIW + "tungsten slugthrower" + NORM + " arm punches a round at " + capitalize(attacker_name) + ".\n");
                    attacker->hit_player(dam, "physical");
                }
                else {
                    tell_room(room,"The " + HIW + "tungsten slugthrower" + NORM + " arm missed "+capitalize(attacker_name)+".\n");
                }
                if (hps < (HEAD_HP * 2)) {
                    head7 = 1;
                    tell_room(room,"The " + HIW + "tungsten slugthrower" + NORM + " arm is destroyed!\n");
                    attacker->add_exp(50000);
                }

                t_head7 = 0;
            }
            else if (t_head7 == (ATTACK_ROUNDS - 1))
            {
                /* tell the room of impending doom */
                tell_room(room, "You see the " + HIW + "tungsten slugthrower" + NORM + " arm rear up for an impending strike...\n");
                t_head7 ++;
            }
            else t_head7 ++;

            /* END HEAD SEVEN ATTACK */


            /* HEAD EIGHT ATTACK */
            if (head8 == 0 &&
                t_head8 > ATTACK_ROUNDS &&
                environment(attacker) == room &&
                !attacker->query_ghost())
            {
                /*
                 * The RED HEAD ATTACKS
                 *
                 */

                if (1 == random(HIT_PROB))
                {
                    dam = random(DAM_RAND) + DAM_BASE;
                    tell_room(room, "The " + HIY + "MIRV rocket" + NORM + " arm cuts loose a missile of loving asplosions at " + capitalize(attacker_name) + ".\n");
                    attacker->hit_player(dam, "physical");
                }
                else {
                    tell_room(room,"The " + HIY + "MIRV rocket" + NORM + " arm missed "+capitalize(attacker_name)+".\n");
                }
                if (hps < HEAD_HP) {
                    head8 = 1;
                    tell_room(room,"The " + HIY + "MIRV rocket" + NORM + " arm is destroyed!\n");
                    attacker->add_exp(50000);
                }

                t_head8 = 0;
            }
            else if (t_head8 == (ATTACK_ROUNDS - 1))
            {
                /* tell the room of impending doom */
                tell_room(room, "You see the " + HIY + "MIRV rocket" + NORM + " arm rear up for an impending strike...\n");
                t_head8 ++;
            }
            else t_head8 ++;

            /* END HEAD EIGHT ATTACK */


        }
    }
    ::heart_beat();
}


extra_look()
{
    string desc1, desc2, desc3, desc4, desc5, desc6, desc7, desc8;
    int hp;
    hp = this_object()->query_hp();

    desc1 = "in good shape.";
    desc2 = "in good shape.";
    desc3 = "in good shape.";
    desc4 = "in good shape.";
    desc5 = "in good shape.";
    desc6 = "in good shape.";
    desc7 = "in good shape.";
    desc8 = "in good shape.";

    if (hp < (HEAD_HP * 8)) desc1 = "slightly damaged.";

    if (hp < (HEAD_HP * 7) + (HEAD_HP / 4) * 3) desc1 = "somewhat damaged.";
    if (hp < (HEAD_HP * 7) + (HEAD_HP / 4)) desc1 = "in bad shape.";
    if (hp < (HEAD_HP * 7)) {
        desc1 = "destroyed.";
        desc2 = "slightly damaged.";
    }

    if (hp < (HEAD_HP * 6) + (HEAD_HP / 4) * 3) desc2 = "somewhat damaged.";
    if (hp < (HEAD_HP * 6) + (HEAD_HP / 4)) desc2 = "in bad shape.";
    if (hp < (HEAD_HP * 6)) {
        desc2 = "destroyed.";
        desc3 = "slightly damaged.";
    }

    if (hp < (HEAD_HP * 5) + (HEAD_HP / 4) * 3) desc3 = "somewhat damaged.";
    if (hp < (HEAD_HP * 5) + (HEAD_HP / 4)) desc3 = "in bad shape.";
    if (hp < (HEAD_HP * 5)) {
        desc3 = "destroyed.";
        desc4 = "slightly damaged.";
    }

    if (hp < (HEAD_HP * 4) + (HEAD_HP / 4) * 3) desc4 = "somewhat damaged.";
    if (hp < (HEAD_HP * 4) + (HEAD_HP / 4)) desc4 = "in bad shape.";
    if (hp < (HEAD_HP * 4)) {
        desc4 = "destroyed.";
        desc5 = "slightly damaged.";
    }

    if (hp < (HEAD_HP * 3) + (HEAD_HP / 4) * 3) desc5 = "somewhat damaged.";
    if (hp < (HEAD_HP * 3) + (HEAD_HP / 4)) desc5 = "in bad shape.";
    if (hp < (HEAD_HP * 3)) {
        desc5 = "destroyed.";
        desc6 = "slightly damaged.";
    }

    if (hp < (HEAD_HP * 2) + (HEAD_HP / 4) * 3) desc6 = "somewhat damaged.";
    if (hp < (HEAD_HP * 2) + (HEAD_HP / 4)) desc6 = "in bad shape.";
    if (hp < (HEAD_HP * 2)) {
        desc6 = "destroyed.";
        desc7 = "slightly damaged.";
    }

    if (hp < HEAD_HP + (HEAD_HP / 4) * 3) desc7 = "somewhat damaged.";
    if (hp < HEAD_HP + (HEAD_HP / 4)) desc7 = "in bad shape.";
    if (hp < HEAD_HP) {
        desc7 = "destroyed.";
        desc8 = "slightly damaged.";
    }

    if (hp < (HEAD_HP / 4) * 3) desc8 = "somewhat damaged.";
    if (hp < (HEAD_HP / 4)) desc8 = "in bad shape.";
    if (hp < (HEAD_HP / 8)) desc8 = "in very bad shape.";

    return "The " + HIY + "electric buzzsaw" + NORM + " arm is " + desc1 + "\n" +
           "The " + HIB + "meson cannon" + NORM + " arm is " + desc2 + "\n" +
           "The " + HIR + "napalm flamethrower" + NORM + " arm is " + desc3 + "\n" +
           "The " + HIG + "ion beamer" + NORM + " arm is " + desc4 + "\n" +
           "The " + HIB + "cryo pulverizer" + NORM + " arm is " + desc5 + "\n" +
           "The " + HIR + "heat-seeking slicerdicer" + NORM + " arm is " + desc6 + "\n" +
           "The " + HIW + "tungsten slugthrower" + NORM + " arm is " + desc7 + "\n" +
           "The " + HIY + "MIRV rocket" + NORM + " arm is " + desc8 + "\n";
}


/**
 * We don't wimpy.
 *
 */
run_away() {
    return 0;
}
