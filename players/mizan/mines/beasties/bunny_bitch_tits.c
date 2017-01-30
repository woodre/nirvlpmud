inherit "/players/mizan/mines/core/monster.c";
#include "../definitions.h"

reset(arg)
{
    object gold;
    string my_name;

    ::reset(arg);
    if(arg) return;


   my_name = "Bitch Tits";

    set_name("A bunny named " + my_name);
    set_race("rabbit");
    set_alias("bunny");
    set_short("A bunny named " + my_name);
    set_long("This is a cute little bunny rabbit.\n"+
   "Oddly enough... it sort of looks like Wicket.\n");
    set_level(1);
    set_hp(500);
    set_al(0);
    set_wc(5);
    set_ac(10000);
    set_chance(5);
    set_spell_dam(4);


    gold=clone_object("obj/money");
    gold->set_money(random(2)+10);
    move_object(gold,this_object());

    if(1 == random(50)) set_random_move_time(10);
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
