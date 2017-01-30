inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "a boy with spiked hair" ||  str == "boy" || str == "kid" || str == "boy with spiked hair"; } 
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("boy with spiked hair");
    set_race("human");
set_gender("male");
    set_al(20+random(10));
    set_level(5); 
    set_hp(65+random(15));
    set_wc(9+random(2));
    set_ac(5);
    set_short("A boy with spiked hair");
    set_long(
      "This is a 14 year old boy with spiked hair.  He is wearing parachute\n"+
      "pants, and a polo shirt with the collar turned up.\n");
  gold=clone_object("obj/money");
  gold->set_money(150+random(100));
  move_object(gold,this_object());
}
