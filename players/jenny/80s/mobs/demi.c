inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "demi moore" ||  str == "demi" || str == "moore" || str == "actress" || str == "Demi Moore"; }
reset(arg)
{
   ::reset(arg);
    if (arg) return;
set_name("Demi Moore");
    set_race("human");
set_gender("female");
    set_al(50+random(20));
    set_level(12);
    set_hp(179+random(10));
    set_wc(17);
    set_ac(8);
    set_short(HIB+"Demi Moore"+NORM);
    set_long(
      "Demi Moore is an attractive woman with dark brown hair.  She\n"+
      "is a brat pack actress, but is much better known for her work\n"+
      "during the 90's.  In the 80's, she stared in films such as 'St.\n"+
     "Elmo's Fire', and 'One Crazy Summer'.\n");
  gold=clone_object("obj/money");
  gold->set_money(500+random(200));
  move_object(gold,this_object());
}
