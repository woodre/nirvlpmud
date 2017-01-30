inherit "/players/mizan/mines/core/monster.c";
#include "../definitions.h"

reset(arg)
{
    object gold;
    string my_name;

    ::reset(arg);
    if(arg) return;


    my_name = LEVEL1_DM->get_rabbit_name();

    set_name("A sheep commando named " + my_name);
    set_race("sheep");
    set_alias("commando");
    set_short("A sheep commando named " + my_name);
    set_long("This is a cute little sheep, but it has a dark side, as it is a\n"+
	     "member of the Earwaxian National Guard. Upon closer inspection you\n"+
	     "realize it seems to be bleeding from the butthole. Gross.\n");
    set_level(3);
    set_hp(MOBSTATS_DM->get_hp(3));
    set_al(0);
    set_wc(MOBSTATS_DM->get_wc(3));
    set_ac(MOBSTATS_DM->get_ac(3));
    set_chance(5);
    set_spell_dam(MOBSTATS_DM->get_spell_dam(3));
    set_spell_mess1("A bunny named " + my_name + " kicks at you wildly!");
    set_spell_mess2("A bunny named " + my_name + " squeals loudly!");
    set_chat_chance(10);
    load_chat("A sheep mutters: hut.. hut... hut\n");

    gold=clone_object("obj/money");
    gold->set_money(MOBSTATS_DM->get_gold(3));
    move_object(gold,this_object());

    if(1 == random(5)) set_random_move_time(60);
}
