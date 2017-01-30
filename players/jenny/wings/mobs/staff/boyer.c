inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "paul boyer" ||  str == "paul" || str == "boyer" || str == "Paul Boyer"; } 
reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("Paul Boyer");
   set_race("human");
   set_gender("male");
   set_al(150+random(100));
   set_level(14);
   set_hp(200);
   set_wc(18);
   set_ac(11);
   add_money(600+random(20));
   set_short(BOLD+WHT+"Paul Boyer"+NORM);
   set_long(
      "Paul Boyer is the equipment manager for the Detroit Red Wings.  He has\n"+
      "short brown hair and is wearing a black sweatshirt and blue jeans.  Paul\n"+
      "looks like he is in his 30's.\n");
}
