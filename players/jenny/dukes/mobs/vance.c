inherit "/obj/monster.c";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("vance duke");
    set_alt_name("vance");
set_alias("duke");
set_race("human");
    set_level(8);
    set_wc(10+random(3));
    set_ac(6+random(3));
    set_hp(100+random(45));
    set_al(104);
    set_gender("male");
    set_short(YEL+"Vance Duke"+NORM);
    set_long(
      "Vance is a well built young man in his late 20's.  He has wavy \n"+
      "short dark hair.  Vance is dressed in an off-white short sleeved\n"+
     "shirt, with the last two buttons undone.  He is a cousin of Bo\n"+
     "and Luke Duke.\n");
  gold=clone_object("obj/money");
  gold->set_money(250+random(210));
  move_object(gold,this_object());
}
