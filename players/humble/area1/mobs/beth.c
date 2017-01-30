/*HUMBLE CORPS 2004*/
#include "../defs.h"

inherit "/obj/monster";

reset(arg) {
    object gold;
    ::reset(arg);
    if (!arg)
       gold = clone_object("obj/money");
    money=1500+random(250);
       move_object(gold,this_object());
    init_command ("wear apron");
    set_short(HIW+"Beth "+NORM);
    set_name("Beth");
    set_alias("beth");
    set_alt_name("beth");
    set_level(17);
    set_wc(23+random(2));
    set_ac(14+random(1));
    set_hp(325+random(50));
    set_long(
    "This woman amazingly looks like a weathered Meg Ryan.\n"+
    "In fact you would say she looks like Meg Ryan on crack.\n"+
    "Incredible! She is Meg Ryan, but she has a really nice round ass, although\n"+
    "she appears to be in a fowl mood\n");
    set_gender("female");
    set_al(0);
    set_chat_chance(7);
    load_chat(HIW+"Beth takes a long drag from her cigarette and blows smoke in your face.\n"+NORM);
}

