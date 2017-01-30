inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg) {
   ::reset(arg);
    if (arg) return;
    set_name("cleetus hogg");
    set_alt_name("cleetus");
    set_race("human");
    set_alias("hogg");
set_al(-(100+random(60)));
set_gender("male");
    set_level(9);
    set_hp(120+random(28));
    set_wc(11+random(5));
    set_ac(7);
    set_short(BOLD+""+HIB+"Cleetus Hogg"+NORM);
    set_long(
      "Cleetus is a pudgy middle aged man with light brown hair, which\n"+
      "is clearly starting to recede.  He is a deputy sheriff, and an\n"+
     "incompetent one at that.  He is a terrible driver, and is almost\n"+
      "never able to catch the Duke boys.  Cleetus is Boss Hogg's\n"+
      "third cousin twice-removed.\n");
  gold=clone_object("obj/money");
  gold->set_money(325+random(150));
  move_object(gold,this_object());
}
