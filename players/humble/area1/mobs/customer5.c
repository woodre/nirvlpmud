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
    "A disgusting over-weight man in his early 20s. He appears to have been\n"+
    "sitting at the trailer park, eating mayonaise sandwiches and\n"+
    "must have run out of mayonaise.\n");
    set_gender("male");
    set_level(10);
    set_ac(10);
    set_wc(14);
    set_hp(150);
    set_al(350);
    }
}
