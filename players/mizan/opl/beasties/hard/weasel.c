inherit "/players/mizan/opl/core/monster.c";

/*****************************************************************************
 *      File:                   weasel.c
 *      Function:               Steals coins from players
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:                  Updated in 6/2014 with code from Boltar's Bill
 *                              the taxman
 *      Change History:        
 *                              rearranged heartbeat so that the code doesn't
 *                              die during combat. Used simplified version of
 *                              stuff from Boltar's Bill the Taxman
 * 
 *                              
 ****************************************************************************/

#include "/players/mizan/opl/definitions.h"
#include "/obj/ansi.h"

int mon,eatmoney,plymon,count;
object goldeat,lostgold;

reset(arg)
{
    object gold;
    string my_name;

    ::reset(arg);
    if (arg) return;


    my_name = WEASEL_DM->get_name();

    set_name(my_name + " the weasel");
    set_race("weasel");
    set_alias(lower_case(my_name));
    set_short(my_name + CYN + " the weasel" + NORM);
    set_long("    This is a shifty weasel named " + my_name + ".\n"+
             "  The only reason you know his name is from the paper sticker badge which\n" +
             "  is affixed crookedly to his shiny, new Armani suit. Wait a minute... \n"+
             "  a weasel... wearing a suit? Oh, it makes sense now. It really should have\n"+
             "  sunken in sooner, the obviousness of it all... this weasel is a lawyer.\n");

    set_level(STATS_DM->get_level_hard());
    set_hp(STATS_DM->get_hp_hard());
    set_al(-200 + random(100));
    set_wc(STATS_DM->get_ac_hard());
    set_ac(STATS_DM->get_wc_hard());
    set_heal(18,1);

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 3;

    set_hp_bonus(STATS_DM->get_hp_bonus_hard());

    set_chance(25);
    set_spell_dam(300);
    set_spell_mess1("Well, it looks the hot oil has hit the anus.\nYou got " + query_name() + " really, REALLY mad.\n");
    set_spell_mess2("A weasel named " + my_name + " bites at you!");

    set_chat_chance(5);
    load_chat(my_name + " smirks at you.\n");


    gold = clone_object("obj/money");
    gold->set_money(STATS_DM->get_gold_hard());
    move_object(gold,this_object());

    if (1 == random(5)) set_random_move_time(10);


    goldeat = this_object();
    call_other(goldeat, "set_function", "steal_gold");
    call_other(goldeat, "set_type", "arrives");
    call_other(goldeat, "set_match", "");
    call_other(goldeat, "set_function", "steal_gold");
    call_other(goldeat, "set_type", "hit");
    call_other(goldeat, "set_match", "weasel");
    call_other(goldeat, "set_function", "steal_gold");
    call_other(goldeat, "set_type", "missed");
    call_other(goldeat, "set_match", "weasel");
    call_other(goldeat, "set_function", "steal_gold");
    call_other(goldeat, "set_type", "leaves");
    call_other(goldeat, "set_match", "");


}



heart_beat()
{
    ::heart_beat();
    if (attacker_ob && 1 == random(3)) insult();
}


steal_gold(str) 
{
    string who, ext;
    goldeat = this_object();

    sscanf(str, "%s %s\n", who, ext);
    lostgold = find_player(lower_case(who));
    if (lostgold == 0) 
    {
        return 1;
    }

    mon = 0 - random(300) - 1;
    if(lostgold->query_money() < 8000) mon = 0 - random(500) - 1;
    if(lostgold->query_money() > 45000) mon = 0 - random(2000) - 1;
    count = call_other(lostgold, "query_money", 0);

    plymon = 0 - count;
    if (mon < plymon) {
        mon = plymon;
    }
    eatmoney = 0 - mon/3;

    if(mon == 0) 
    {
        tell_object(lostgold, query_name() + " smacks you in the mouth for being a POOR ASS!\n");
        call_other(lostgold, "add_hit_point", 0-random(80));
        return 1;
    }

    call_other(lostgold, "add_money", mon);
    call_other(goldeat, "add_money", eatmoney);
    tell_object(lostgold, query_name() + " steals some of your money!!\n");

    insult();
    return 1;
}




/*

heart_beat()
{
    int att_money;

    ::heart_beat();
 
    if (attacker_ob && 1 == random(5)) insult();
    else if (1 == random(25)) insult();

    if(1 == random(4) && attacker_ob)
    {
        att_money = attacker_ob->query_money();
        if(att_money < 500)
        {
            say(query_name() + " smacks you in the mouth for being a POOR ASS!\n");
            if(!attacker_ob->query_ghost()) attacker_ob->hit_player(random(100), "other|sleaze");
        }
        else
        {
            say(query_name() + " steals some money from you!\n");
            attacker_ob->add_money(-random(400));
        }
    }

}
*/

insult()
{
    string result;
    if(1 == random(4))  result = query_name() + " says: " + CYN + WEASEL_DM->get_threat() + NORM;
    else result = query_name() + " says: " + CYN + MAMASNAPS_DM->query_snap_ugly() + NORM;
    say(result + "\n");
}
