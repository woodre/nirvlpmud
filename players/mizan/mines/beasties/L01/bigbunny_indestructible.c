inherit "/players/mizan/mines/core/monster.c";
#include "../../definitions.h"

reset(arg)
{
    object gold;
    object quest;
    string my_name;

    ::reset(arg);
    if(arg) return;


    my_name = LEVEL1_DM->get_rabbit_name();

    set_name("A BIG bunny named " + my_name);
    set_race("rabbit");
    set_alias("bunny");
    set_short("A BIG bunny named " + my_name);
    set_long("This is a freakishly large rabbit. It stands roughly a meter\n"+
	     "tall and is far from being a cute little bunny. It seems to be\n"+
	     "suffering from some sort of ailment though, and isn't nearly as\n"+
	     "dangerous-looking as it could be- but don't take it lightly\n"+
	     "or underestimate it in any event. Still... you must kill it.\n");
    set_level(2);
   set_hp(400000);
    set_al(0);
    set_wc(MOBSTATS_DM->get_ac(2));
    set_ac(MOBSTATS_DM->get_wc(2));
    set_chance(5);
    set_spell_dam(MOBSTATS_DM->get_spell_dam(3));
    set_spell_mess1("A BIG bunny named " + my_name + " kicks at you wildly!");
    set_spell_mess2("A BIG bunny named " + my_name + " squeals loudly!");
    set_chat_chance(10);


    gold=clone_object("obj/money");
    gold->set_money(MOBSTATS_DM->get_gold(3));
    move_object(gold,this_object());

    quest=clone_object("/players/mizan/mines/items/L01_questobj.c");
    move_object(quest,this_object());
}
