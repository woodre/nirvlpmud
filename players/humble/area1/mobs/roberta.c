/*HUMBLE CORPS 2004*/
#include "../defs.h"
inherit "/obj/monster";
reset(arg) {
    ::reset(arg);
    if (!arg)  {
    money=1500+random(2000);
    set_name(GRN+"Roberta"+NORM);
    set_alt_name("roberta");
    set_alias("roberta");
    set_short(GRN+"Roberta"+NORM);
    set_race("human");
    set_long(
    "Roberta is a short chubby little woman.  She appears to be\n"+
    "completely catatonic as she works away at the computer.\n"+
    "Either she's high on something or the fact she has to listen to\n"+
   "Gary's bitch-ass all the time.\n");
    set_gender("female");
    set_level(17);
    set_ac(18);
    set_wc(24);
    set_hp(450+random(200));
    set_al(350);
    set_chat_chance(6);
    load_chat(HIW+"Roberta snores then wakes up as her chin hits her chest.\n"+NORM);
    load_chat(HIW+"Roberta stares at the computer and moves her mouse around.\n"+NORM);
    }
}
