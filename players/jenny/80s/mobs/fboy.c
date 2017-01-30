inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "a boy with feathered hair" ||  str == "boy" || str == "kid" || str == "boy with feathered hair"; } 
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("boy with feathered hair");
    set_race("human");
set_gender("male");
    set_al(30+random(10));
    set_level(4); 
    set_hp(50+random(17));
    set_wc(8+random(2));
    set_ac(4);
    set_short("A boy with feathered hair");
    set_long(
      "This is a 12 year old boy with blow-dried feathered hair.\n"+
      "He is wearing a denim jacket, bugle boy pants with the\n"+
     "legs rolled up, boat shoes, and no socks.\n");
  gold=clone_object("obj/money");
  gold->set_money(120+random(60));
  move_object(gold,this_object());
}
