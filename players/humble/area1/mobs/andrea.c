/*HUMBLE CORPS 2004*/
#include "../defs.h"
inherit "/obj/monster";
reset(arg) {
    ::reset(arg);
    if (!arg)  {
    money=500+random(500);
    set_name("Andrea");
    set_alt_name("andrea");
    set_alias("andrea");
    set_short(HIW+"Andrea"+NORM);
    set_race("human");
    set_long(
    "Here is a cute girl who appears to be in her early 20s.  She has\n"+
    "straight, blond hair with brown highlights.  She is very pretty girl\n"+
    "it's a shame she has a job in the grocery business.\n");
    set_gender("female");
    set_level(16);
    set_ac(13);
    set_wc(20+random(1));
    set_hp(275+random(50));
    set_al(500);
    set_chat_chance(5);
    load_chat(HIW+"Andrea smiles as she spreads frosting over a cake.\n"+NORM);
    load_chat(HIW+"Andrea says to Amy:"+NORM+" I dunno if I really believe that, you know?\n");
    }
}
