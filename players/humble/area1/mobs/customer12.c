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
    "This is a very, very rich woman.  She is rocking some of those sheek\n"+
    "yellowish/pink J-lo wannabe sunglasses.  She is wearing all sorts\n"+
    "of expensive jewelery.  She acts as if you aren't even there.\n");
    set_gender("female");
    set_level(8);
    set_ac(9+random(5));
    set_wc(8);
    set_hp(100);
    set_al(350);
    }
}
