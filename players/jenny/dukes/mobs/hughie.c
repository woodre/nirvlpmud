inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("hughie hogg");
    set_alt_name("hogg");
    set_race("human");
    set_alias("hughie");
set_gender("male");
    set_al(-(200+random(200)));
    set_level(10);
    set_hp(130+random(20));
    set_wc(14+random(3));
    set_ac(7+random(2));
    set_short(BOLD+""+WHT+"Hughie Hogg"+NORM);
    set_long(
      "Hughie is the nephew of Boss Hogg.  He has dark hair, and\n"+
      "is a little taller, and a whole lot thinner than his uncle Boss.\n"+
     "He is dressed in a white suit and matching top hat.  Hughie\n"+
      "is crookeder than a rattlesnake, and twice as mean.  Boss Hogg\n"+
      "often brings him into town when he needs help with a scheme,\n"+
     "or when he needs help trying to frame the Duke boys.\n");
  gold=clone_object("obj/money");
  gold->set_money(335+random(220));
  move_object(gold,this_object());
}
