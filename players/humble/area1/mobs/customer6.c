/*HUMBLE CORPS 2004*/
#include "../defs.h"
inherit "/obj/monster";
reset(arg) {
    ::reset(arg);
    if (!arg)  {
    money=150+random(500);
    move_object(clone_object("/players/humble/area1/objs/shoppingcart1.c"));
    set_name("Customer");
    set_alt_name("customer");
    set_alias("customer");
    set_short("A customer");
    set_race("human");
    set_long(
    "A short old lady, how sweet, justl ike grandma.\n");
    set_gender("female");
    set_level(8);
    set_ac(8);
    set_wc(12);
    set_hp(150);
    set_al(350);
    }
}
