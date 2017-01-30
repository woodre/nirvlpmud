inherit "obj/monster";
#include "/players/persephone/rooms.h"
object ke;
reset(arg){
 ::reset(arg);
  if(!arg){
   object gold;
   gold = clone_object("obj/money");
   gold->set_money(10000+random(3000));
   move_object(gold, TOB);
   ke=clone_object("players/persephone/closed/silkey");
   move_object(ke, TOB);
   set_name("anaconda");
   set_alias("snake");
   set_short("An Angry Anaconda");
   set_long("An extremely large mutated anaconda you seem to have angered\n" +
            "him by waking him up. Very stupid indeed I hope you have\n" +
            "Your insurance paid up.\n");
   set_level(30);
   set_wc(40);
   set_ac(25);
   set_hp(2000);
   set_al(0);
   set_aggressive(1);
   set_chance(25);
    set_spell_dam(40);
    set_spell_mess1("The anaconda starts to coiling around its happless victim\n");
    set_spell_mess2("The anaconda starts to constrict you");
  }
}
