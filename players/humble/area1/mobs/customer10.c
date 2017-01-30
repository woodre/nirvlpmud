/*HUMBLE CORPS 2004*/
#include "../defs.h"
inherit "/obj/monster";
reset(arg) {
    ::reset(arg);
    if (!arg)  {
    money=150+random(500);
    set_name("Customer");
    set_alt_name("customer");
    set_alias("customer");
    set_short("A customer");
    set_race("human");
    set_long(
    "Hey it's that small chinese kid from Goonies! Oh man don't you\n"+
    "just love that guy?!\n");
    set_gender("male");
    set_level(10);
    set_ac(8);
    set_wc(18);
    set_hp(100);
    set_ac(6);
    set_wc(10);
    set_hp(100);
    set_al(350);
    set_chat_chance(8);
     load_chat(HIW+"The Chinese kid says:"+NORM+" That's what I said you idiot! BOOBY TWAPS!!!!\n");
    }
}
