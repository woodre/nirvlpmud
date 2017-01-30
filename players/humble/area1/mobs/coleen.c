/*HUMBLE CORPS 2004*/
#include "../defs.h"

inherit "/obj/monster";

reset(arg) {
    object gold;
    ::reset(arg);
    if (!arg)  {
       gold = clone_object("obj/money");
    money=500+random(600);
       move_object(gold,this_object());
    move_object(clone_object("/players/humble/area1/objs/grocerybag.c"));
    init_command("wield bag");
    set_name("Coleen");
    set_alt_name("coleen");
    set_alias("coleen");
    set_short("Coleen");
    set_race("human");
    set_long(
    "Coleen is a cute girl.  She wears a low-cut shirt showing what little\n"+
    "cleavage she has.  Her thong is sticking way out of her pants.\n"+
    "She is one of those teenie-bopper girls who looks like she is\n"+
    "about 19 but your intuition tells you she is closer to 15.\n");
    set_gender("female");
    set_level(15);
    set_ac(12);
    set_wc(20);
    set_hp(200+random(100));
    set_al(0);
    set_chat_chance(4);
    load_chat(HIW+"Coleen bends over showing her g-string.\n"+NORM);
     load_chat(HIW+"Coleen looks over at you and smiles.\n"+NORM);
    }
}
