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
    "This is a short woman with a large mole bulging out from her nose.\n"+
    "She is pushing a grocery cart and seems rather un-interested in anything\n"+
    "at all, anywhere, with anyone, except herself.\n");
    set_gender("female");
    set_level(10);
    set_ac(10);
    set_wc(18);
    set_hp(200);
    set_al(350);
    }
}
