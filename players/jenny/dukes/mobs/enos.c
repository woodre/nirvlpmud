inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("enos strate");
    set_alt_name("enos");
    set_race("human");
    set_alias("strate");
set_gender("male");
    set_al(100+random(30));
    set_level(11);
    set_hp(148+random(25));
    set_wc(13+random(5));
    set_ac(7+random(3));
    set_short(BOLD+""+HIB+"Enos Strate"+NORM);
    set_long(
      "Enos is a tall young man with short brown hair and a happy\n"+
      "go lucky smile.  He is a deputy sheriff, and the only honest\n"+
     "lawman in hazard county.  He is kind of a dipstick, but still\n"+
      "the best officer Hazzard has to offer.  He dreams of one day\n"+
      "marrying Daisy Duke.  Friends, don't we all?\n");
  gold=clone_object("obj/money");
  gold->set_money(400+random(200));
  move_object(gold,this_object());
}
