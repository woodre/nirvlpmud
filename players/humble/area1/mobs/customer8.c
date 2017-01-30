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
    "This is an enormous amazonian woman by the looks of her.\n"+
    "She is one of those intensely huge women who looks like she\n"+
    "works out all the time.  She smiles as she catches you looking at her.\n");
    set_gender("female");
    set_level(15);
    set_ac(18);
    set_wc(15);
    set_hp(300);
    set_al(350);
    }
}
