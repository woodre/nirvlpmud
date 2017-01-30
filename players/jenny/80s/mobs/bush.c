inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "george bush" ||  str == "george" || str == "bush" || str ==  "George Bush"; }
reset(arg)
{
   ::reset(arg);
    if (arg) return;
set_name("George Bush");
    set_race("human");
set_gender("male");
    set_al(40+random(30));
    set_level(15);
    set_hp(220+random(10));
    set_wc(20+random(2));
    set_ac(11+random(3));
    set_short(HIB+"George Bush"+NORM);
    set_long(
      "George Bush is a tall, thin, older gentlemen with short brown\n"+
      "hair and glasses.  He toiled throughout most of the 80's as the\n"+
      "Vice President of the United States.  He finally emerged from\n"+
      "Reagan's shadow when he won the presidency in 1988.  He\n"+
     "may look like a wimp, but don't be fooled.  This 'wimp' was\n"+
     "once director of the CIA.\n");
  gold=clone_object("obj/money");
  gold->set_money(860+random(110));
  move_object(gold,this_object());
}
