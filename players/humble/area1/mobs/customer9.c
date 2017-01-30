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
    "This man is here on a mission, he is clean cut, he is strong\n"+
     "and he came to get canned vegetables and frozen pizzas!\n"+
     "This motherfucker is James Bond! But he looks like\n"+
    "Henry Rollins.  Fear.\n");
    set_gender("male");
    set_level(12);
    set_ac(10);
    set_wc(18);
    set_hp(200+random(84));
    set_al(350);
    }
}
