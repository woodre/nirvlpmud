inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("brat");
    set_alt_name("kid");
    set_race("human");
    set_alias("child");
    set_al(9+random(8));
    set_level(4);
    set_hp(55+random(10));
    set_wc(8);
    set_ac(4);
set_gender("male");
    set_short("A little brat");
    set_long(
      "A young boy who can't find his mommy and is wandering around the\n"+
      "mall.  He is very confused, but is mindful of one thing his mother\n"+
     "taught him.  'BE GOOD, OR YOU'LL GROW UP TO BE A SHOE\n"+
     "SALESMAN, LIKE AL BUNDY.'\n");
  gold=clone_object("obj/money");
  gold->set_money(120+random(40));
  move_object(gold,this_object());
}
