/*HUMBLE CORPS 2004*/
#include "../defs.h"
inherit "/obj/monster";
reset(arg) {
    ::reset(arg);
    if (!arg)  {
    money=random(100);
    move_object(clone_object("/players/humble/area1/objs/canofsoup.c"));
    set_name("Customer");
    set_alt_name("customer");
    set_alias("customer");
    set_short("A customer");
    set_race("human");
    set_long(
    "Here is the perfect stereotypical punk. He has large spikes\n"+
    "protruding from the hood in his sweatshirt, along with several piercings\n"+
    "he sports spiked-straight purple hair and eyeliner.\n"+
    "This guy is really just a fashion design student on LSD.\n");
    set_gender("male");
    set_level(15);
    set_ac(18);
    set_wc(16);
    set_hp(380+random(70));
    set_al(350);
    }
}
