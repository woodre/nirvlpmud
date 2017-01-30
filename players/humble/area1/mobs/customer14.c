/*HUMBLE CORPS 2004*/
#include "../defs.h"
inherit "/obj/monster";
reset(arg) {
    ::reset(arg);
    if (!arg)  {
     money=5+random(8);
    set_name("Customer");
    set_alt_name("customer");
    set_alias("customer");
    set_short("A customer");
    set_race("human");
    set_long(
    "An old lady in a wheel chair.  She has an oxygen tank strapped\n"+
    "to the side of her wheelchair.  Her skin dangles from her chin, elbows\n"+
    "it's just plain a sad site to see.\n");
    set_gender("female");
    set_level(5);
    set_ac(0);
    set_wc(18);
    set_hp(50);
    set_al(350);
    }
}
