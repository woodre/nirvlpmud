inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "michael milken" ||  str == "michael" || str == "milken" || str == "mike" || str == "Michael Milken"; } 
reset(arg)
{
   ::reset(arg);
    if (arg) return;
set_name("Michael Milken");
    set_race("human");
set_gender("male");
    set_al(-(170+random(57)));
    set_level(14);
    set_hp(200+random(15));
    set_wc(17+random(3));
    set_ac(11+random(3));
    set_short(BOLD+HIG+"Michael Milken"+NORM);
    set_long(
      "Michael Milken is a balding, middle aged man, who is wearing\n"+
      "a three piece suit.  He symbolized the greed of the 80's by getting\n"+
      "rich selling junk bonds.  Many people lost a lot of money because\n"+
      "of him.  He was finally convicted of fraud and sent to jail.\n");
  gold=clone_object("obj/money");
  gold->set_money(800+random(100));
  move_object(gold,this_object());
}
