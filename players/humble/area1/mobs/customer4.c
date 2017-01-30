/*HUMBLE CORPS 2004*/
#include "../defs.h"
inherit "/obj/monster";
reset(arg) {
    ::reset(arg);
    if (!arg)  {
    money=200+random(300);
    set_name("Customer");
    set_alt_name("customer");
    set_alias("customer");
    set_short("A customer");
    set_race("human");
    set_long(
    "This is a short man with a strange look about him.\n"+
    "Hmmmm. yeah, just don't know about him bro.\n");
    set_gender("male");
    set_level(12);
    set_ac(10);
    set_wc(17);
    set_hp(200+random(50));
    set_al(350);
    }
}
