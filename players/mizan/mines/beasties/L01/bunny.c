inherit "/players/mizan/mines/core/monster.c";
#include "../../definitions.h"

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
    set_hp(MOBSTATS_DM->get_hp(1));
    set_al(0);
    set_wc(MOBSTATS_DM->get_ac(1));
    set_ac(MOBSTATS_DM->get_wc(1));
    set_chance(5);
    set_spell_dam(MOBSTATS_DM->get_spell_dam(1));
    set_spell_mess1("A bunny named " + my_name + " kicks at you wildly!");
    set_spell_mess2("A bunny named " + my_name + " squeals loudly!");
    set_chat_chance(10);


    gold=clone_object("obj/money");
    gold->set_money(MOBSTATS_DM->get_gold(1));
    move_object(gold,this_object());

    if(1 == random(5)) set_random_move_time(60);
}
