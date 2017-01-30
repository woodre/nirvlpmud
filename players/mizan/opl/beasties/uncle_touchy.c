inherit "/players/mizan/opl/core/monster.c";
#include "../definitions.h"

reset(arg)
{
    object gold;
    string my_name;

    ::reset(arg);
    if (arg) return;


    set_name("Uncle Touchy");
    set_race("uncle");
    set_alias("touchy");
    set_short("Uncle Touchy");
    set_long("Fat, balding, and somewhat greasy from head to toe, Uncle Touchy is\n"+
             "wearing nothing but a stained wife-beater and a pair of dirty shorts\n"+
             "which have obviously seen better days. To top off this ensemble, he\n"+
             "has a pretty crazy combover and is wearing flip-flops.\n");
    set_level(8);
    set_hp(55000);
    set_al(0);
    set_wc(5);
    set_ac(555);
    set_chance(5);
    set_spell_dam(80);
    set_spell_mess1("Uncle Touchy jabs you in the anus! UFIA!");
    set_spell_mess2("Uncle Touchy gropes you in your crotchal regions... eeeew!");
    set_chat_chance(4);
    load_chat("Uncle Touchy says: Heeeey there.... wanna buy something?\n");
    load_chat("Uncle Touchy says: You look mighty cute in those pants. Hah. Hah.\n");
    load_chat("Uncle Touchy looks at you.\n");

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 4;

    gold = clone_object("obj/money");
    gold->set_money(300);
    move_object(gold,this_object());

}
