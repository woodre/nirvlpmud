inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("Maybell");
    set_alt_name("maybell");
    set_race("human");
    set_alias("operator");
set_gender("female");
    set_al(60+random(30));
    set_level(7);
    set_hp(90+random(22));
    set_wc(9+random(4));
    set_ac(5+random(3));
    set_short(BOLD+""+MAG+"Maybell"+NORM);
    set_long(
      "Maybell is an attractive young woman in her mid 30's.  She is\n"+
      "Boss Hogg's niece, and also the nosy telephone operator.  If\n"+
     "you ever need to know any gossip, talk to her.\n");
  gold=clone_object("obj/money");
  gold->set_money(200+random(200));
  move_object(gold,this_object());
}
