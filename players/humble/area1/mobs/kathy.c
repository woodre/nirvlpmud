/*HUMBLE CORPS 2004*/
#include "../defs.h"
inherit "/obj/monster";
reset(arg) {
    ::reset(arg);
    if (!arg)  {
    money=2299+random(2500);
    set_name(HIW+"Kathy"+NORM);
    set_alt_name("kathy");
    set_alias("kathy");
    set_short(HIW+"Kathy"+NORM);
    set_race("human");
    set_long(
    HIW+"Kathy"+NORM+" is a middle-aged woman with blonde hair\n"+
    "and blue eyes.  She seems to be a bit over-weight but is very\n"+
    "cheerful.  As you step closer to her you can smell alcohol.\n");
    set_gender("female");
    set_level(18);
    set_ac(16);
    set_wc(22);
    set_hp(400+random(150));
    set_al(350);
    }
}
