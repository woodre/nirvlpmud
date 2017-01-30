/*****************************************************************************
 *      File:                   austrian_death_machine.c
 *      Function:               High value monster with goodies. Rare monster
 *                              and does not appear often in the game (ideally
 *                              just once per boot.
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:                 
 *      Change History:         New file
 ****************************************************************************/

inherit "/players/mizan/opl/core/monster.c";
#include "/players/mizan/opl/definitions.h"
#include "/obj/ansi.h"

reset(arg)
{
    object gold;
    string my_name;

    ::reset(arg);
    if (arg) return;

    my_name = 100000 + random(800000);

    set_name("Austrian Death Machine");
    set_race("machine");
    set_alias("arnold");
    set_short(HIK + BYEL + "Austrian Death Machine" + NORM);
    set_long("Despite the familiar face, the quick and sickening reality sets in. This is\n"+
             "not Arnold Schwarzenegger, and is definitely some sort of late-model cyborg.\n"+
	     "Its impressive frame of steel and flesh is battle damaged with bullet holes,\n"+
             "streaks of shrapnel damage, and pock-marks of various sorts.\n"+
             "Looking closer, you see an engraving on an exposed rib:\n"+
             "'Cyberdyne Model T700s - S/N: " + my_name + "'\n");

    set_level(STATS_DM->get_level_hard());
    set_hp(STATS_DM->get_hp_hard());
    set_al(-500);
    set_wc(STATS_DM->get_wc_hard());
    set_ac(STATS_DM->get_ac_hard());
    set_chance(10);
    set_spell_dam(350);
    set_spell_mess1(short() + " screams: " + HIY + U + "NYYAAAAAAAAAAAAAAAUUUUGH!" + NORM + "\nYou're really in trouble now. You recognize that 'Conan' scream.\n");
    set_spell_mess2(short() + " cockpunches you, and delivers a witty one-liner.\nYour inner child bleeds.\n");

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 3;

    set_heal(15, 1);

    /* aggressive monster bonus, room block bonus */
    set_hp_bonus(STATS_DM->get_hp_bonus_hard() + 300);

    gold = clone_object("obj/money");
    gold->set_money(STATS_DM->get_gold_hard());
    move_object(gold,this_object());

    move_object(clone_object("/players/mizan/opl/beasties/rare/austrian_death_machine/telephone-pole.c"), this_object());

    move_object(clone_object("/players/mizan/opl/beasties/rare/austrian_death_machine/c19_saint.c"), this_object());    

    move_object(clone_object("/players/mizan/opl/beasties/rare/austrian_death_machine/patrasen_SD505_9.64mm.c"), this_object());
    move_object(clone_object("/players/mizan/opl/beasties/rare/austrian_death_machine/patrasen_SD505_9.64mm.c"), this_object());
    move_object(clone_object("/players/mizan/opl/beasties/rare/austrian_death_machine/patrasen_SD505_9.64mm.c"), this_object());

    move_object(clone_object("/players/mizan/opl/beasties/rare/austrian_death_machine/9.64mm.c"), this_object());
    move_object(clone_object("/players/mizan/opl/beasties/rare/austrian_death_machine/9.64mm.c"), this_object());

    move_object(clone_object("/players/mizan/opl/beasties/rare/austrian_death_machine/dactrol_hp_9.64mm.c"), this_object());
    move_object(clone_object("/players/mizan/opl/beasties/rare/austrian_death_machine/dactrol_hp_9.64mm.c"), this_object());


    set_block_exits(1);
    set_aggressive(1);
}


heart_beat()
{
    ::heart_beat();
    if (attacker_ob && 1 == random(3)) ahnuld_snap();
}

ahnuld_snap()
{
    string result;
    result = query_name() + " says: " + HIY + U + RANDOBJ_DM->get_ahnuld_snap() + NORM + "\n";
    say(result);
}
