/*HUMBLE CORPS 2004*/
#include "../defs.h"
inherit "/obj/monster";
reset(arg) {
    ::reset(arg);
    if (!arg)  {
    money=1000+random(4000);
    set_name(HIR+"Mary"+NORM);
    set_alt_name("mary");
    set_alias("mary");
    set_short(HIR+"Mary"+NORM);
    set_race("human");
    set_long(
   HIR+"Mary"+NORM+" is a older looking gal with dark black\n"+
    "hair.  She is the Manager of the emat department and is chock\n"+
    "full of personality.  She looks like a southern woman, I'd watch\n"+
     "it if I was you.\n");
    set_gender("female");
    set_level(20);
    set_ac(18);
    set_wc(28);
    set_hp(1000+random(200));
    set_al(350);
    set_chat_chance(5);
    load_chat(HIR+"Mary stacks some meat into the meat case.\n"+NORM);
    }
}
