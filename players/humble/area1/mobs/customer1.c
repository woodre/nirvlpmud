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
     "This is a middle-aged man with a mustache.  He seems a bit\n"+
    "overweight by the looks of him but has a bright smile, he must be\n"+
    "enjoying his shopping adventur.\n");
    set_gender("male");
    set_level(12);
    set_ac(10);
    set_wc(18);
    set_hp(250+random(100));
    }
}
