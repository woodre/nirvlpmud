inherit "/players/mizan/mines/core/monster.c";
#include "../definitions.h"

reset(arg)
{
    object gold;
    string my_name;

    ::reset(arg);
    if(arg) return;


    my_name = LEVEL1_DM->get_rabbit_name();

    set_name("A bunny named " + my_name);
    set_race("rabbit");
    set_alias("bunny");
    set_short("A bunny named " + my_name);
    set_long("This is a cute little bunny rabbit.\n"+
    "It is standing here, looking at you, just asking to be killed.\n");
    set_level(1);
    set_hp(50000);
    set_al(0);
    set_wc(5);
    set_ac(100);
    set_chance(5);
    set_spell_dam(4);


    gold=clone_object("obj/money");
    gold->set_money(random(2)+10);
    move_object(gold,this_object());

    if(1 == random(5)) set_random_move_time(10);
}


heart_beat()
{
	::heart_beat();
	if(!attacker_ob && 1 == random(15)) mamasnap();
}

mamasnap()
{
	string result;
	result = format(query_name() + " says: " + MAMASNAPS_DM->query_snap(), 76);
	say(result);
}
