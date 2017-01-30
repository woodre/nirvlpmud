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
    "A happy, quiet QFC shopper.  It's her neighborhood grocer.\n");
    set_gender("female");
    set_level(8);
    set_ac(6);
    set_wc(10);
    set_hp(100);
    set_al(350);
    }
}
