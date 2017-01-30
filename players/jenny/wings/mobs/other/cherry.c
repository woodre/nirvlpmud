inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "don cherry" ||  str == "don" || str == "cherry" || str == "Don Cherry"; } 

reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("Don Cherry");
   set_race("human");
   set_gender("male");
   set_al(250+random(90));
   set_level(11);
   set_hp(150+random(10));
   set_wc(15);
   set_ac(10);
   add_money(400+random(200));
   set_chat_chance(25);
   load_a_chat(BOLD+"Don Cherry snorts:"+NORM+" You fight like a Swede.\n");
   set_short(BOLD+WHT+"Don Cherry"+NORM);
   set_long(
      "Don Cherry is the star of Coaches Corner on Hockey Night in Canada.\n"+
      "He is an old guy, with grey hair, a receding hairline, and a grey mustache\n"+
      "and goatee.  He is very sharply dressed in a blue suit and tie.  Don is a\n"+
      "former NHL coach, who has become hockey's most controversial, and\n"+
      "entertaining commentator.\n");
}
