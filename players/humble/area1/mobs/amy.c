   /* Humble Corporate */

#include <ansi.h>

inherit "/obj/monster";

reset(arg) {
    object gold, spatula;
    ::reset(arg);
    if (!arg)
    gold = clone_object("obj/money");
    money=500+random(100);
       gold = clone_object("obj/money");
       move_object(gold,this_object());
    set_name("Amy");
    set_alt_name("Amy");
    set_alias("amy");
    set_short(HIW+"Amy "+NORM);
    set_race("human");
    set_long("This is Amy, she is the Bakery Manager.  She is a cute short asian woman\n"+
    "the kind you see in movies, she appears to e in her 30s and is very cheerful.\n");
    set_gender("female");
    set_level(15);
    set_ac(12+random(1));
    set_wc(20);
    set_hp(245+random(45));
    set_al(350);
    set_chat_chance(7);
    load_chat("Amy asks you:"+HIW+" Did you see my bling bling on my car!"+NORM);
    load_chat("Amy tells Andrea something and giggles.");
  }
