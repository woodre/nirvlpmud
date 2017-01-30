/*HUMBLE CORPS 2004*/
#include "../defs.h"
inherit "/obj/monster";
reset(arg) {
    ::reset(arg);
    if (!arg)  {
    money=200+random(200);
    move_object(clone_object("/players/humble/area1/objs/canoffruit.c"));
    set_name("Customer");
    set_alt_name("customer");
    set_alias("customer");
    set_short("A customer");
    set_race("human");
    set_long(
    "This is a huge black man with enormous gold chains that dangle and shine.\n"+
    "His arms are the size of your torso, I think he'd eat you alive.\n");
    set_gender("male");
    set_level(15);
    set_ac(18);
    set_wc(24);
    set_hp(200);
    set_al(350);
    }
}
