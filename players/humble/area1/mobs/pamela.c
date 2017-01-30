/*HUMBLE CORPS 2004*/
#include "../defs.h"
inherit "/obj/monster";
reset(arg) {
    ::reset(arg);
    if (!arg)  {
    money=1000+random(500);
    move_object(clone_object("/players/humble/area1/objs/grocerybag.c"));
    init_command("wield bag");
    set_name(HIW+"Pamela"+NORM);
    set_alt_name("pamela");
    set_alias("pamela");
    set_short(HIW+"Pamela"+NORM);
    set_race("human");
    set_long(
    "This is Pamela. She is a stickly looking girl with long brown hair.\n"+
    "She wears strange clothes underneath her black and yellow uniform.\n"+
    "She reminds you of a mouse for some reason.\n");
    set_gender("female");
    set_level(15);
    set_ac(14);
    set_wc(16);
    set_hp(300);
    set_al(350);
    }
}
