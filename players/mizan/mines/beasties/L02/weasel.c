inherit "/players/mizan/mines/core/monster.c";
#include "../../definitions.h"

reset(arg)
{
    object gold;
    string my_name;

    ::reset(arg);
    if(arg) return;


    my_name = LEVEL2_DM->get_weasel_name();

    set_name("A weasel named " + my_name);
    set_race("weasel");
    set_alias("lawyer");
    set_short("A weasel named " + my_name);
    set_long("This is a shifty weasel named " + my_name + ".\n"+
    "It looks like it's up to no good, and needs to be exterminated NOW.\n");



    set_level(2);
    set_hp(MOBSTATS_DM->get_hp(2));
    set_al(-200 + random(100));
    set_wc(MOBSTATS_DM->get_ac(2));
    set_ac(MOBSTATS_DM->get_wc(2));
    set_chance(2);
    set_spell_dam(MOBSTATS_DM->get_spell_dam(2));
    set_spell_mess2("A weasel named " + my_name + " bites at you!");
    set_chat_chance(10);


    gold=clone_object("obj/money");
    gold->set_money(MOBSTATS_DM->get_gold(2));
    move_object(gold,this_object());

    if(1 == random(5)) set_random_move_time(10);
}


heart_beat()
{
	::heart_beat();
	if(attacker_ob && 1 == random(5)) insult();
	else if(1 == random(25)) insult();
}

insult()
{
	string result;
	result = format(query_name() + " says: " + MAMASNAPS_DM->query_snap_ugly(), 76);
	say(result);
}
