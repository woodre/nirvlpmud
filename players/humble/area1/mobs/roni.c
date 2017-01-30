/*HUMBLE CORPS 2004*/
#include "../defs.h"
inherit "/obj/monster";
reset(arg) {
    ::reset(arg);
    if (!arg)  {
    money=1000+random(250);
    move_object(clone_object("/players/humble/area1/objs/grocerybag.c"));
    init_command("wield bag");
    set_name(HIW+"Roni"+NORM);
    set_alias("roni");
    set_alt_name("roni");
    set_short(HIW+"Roni"+NORM);
    set_race("human");
    set_long(
    "Now here is a delightful little checker.  She's not too big\n"+
    "not too small, not too short, and not too tall. Imagine that!\n"+
    "Roni appears to be in her 30s and really enjoys what she is doing.\n");
    set_gender("female");
    set_level(15);
    set_ac(16);
    set_wc(18);
    set_hp(350+random(100));
    set_al(350);
    set_chat_chance(6);
    load_chat(YEL+"Roni picks up her cellphone and answers it.\n"+NORM);
    load_chat(YEL+"Roni smiles and says:"+NORM+" Oh can you wait just a moment, I have a call.\n");
    }
}
