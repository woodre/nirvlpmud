/*HUMBLE CORPS 2004*/
#include "../defs.h"
inherit "/obj/monster";
reset(arg) {
    ::reset(arg);
    if (!arg)  {
    money=400+random(500);
    set_name("Customer");
    set_alt_name("customer");
    set_alias("customer");
    set_short("A customer");
    set_race("human");
    set_long(
    "Here is a man, adorned in a US Naval Officer's Uniform. He walks\n"+
    "proud, with little reason not to.   Damn, all cream white, with black and yellow\n"+
    "stripes. This motherfucker is slick yo!\n");
    set_gender("male");
     set_level(17);
    set_ac(18);
    set_wc(22);
    set_hp(300);
    set_al(800);
    }
}
