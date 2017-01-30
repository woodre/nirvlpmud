/*HUMBLE CORPS 2004*/
#include "../defs.h"
inherit "/obj/monster";
reset(arg) {
    ::reset(arg);
    if (!arg)  {
    money=500+random(500);
    set_name(HIW+"Pam"+NORM);
    set_alt_name("pam");
    set_alias("pam");
    set_short(HIW+"Pam"+NORM);
    set_race("human");
    set_long(
    "This is an older woman with grey frizzy hair. She seems like she's\n"+
    "gonna have a heart-attack just about any moment she moves. She\n"+
    "breathes heavy and waddles about in a sickening manner.\n"+
    "Anyone with any form of compassion would have let her go on\n"+
    "medical leave or given her some extra days off, but no\n"+
    "they work her to the bone here.\n");
    set_gender("female");
    set_level(12);
    set_ac(14);
    set_wc(18);
    set_hp(200);
    set_level(8);
    set_chat_chance(5);
    load_chat(HIW+"Pam mutters:"+NORM+" I got a corn on my foot."+NORM);
    load_chat(HIW+"Pam walks about and breaths heavy.\n");
    }
}
