inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "harry neale" ||  str == "harry" || str == "neale" || str == "Harry Neale"; } 

reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("Harry Neale");
   set_race("human");
   set_gender("male");
   set_al(100+random(20));
   set_level(9);
   set_hp(130);
   set_wc(13);
   set_ac(7);
   add_money(370+random(60));
   set_short(BOLD+WHT+"Harry Neale"+NORM);
   set_long(
      "Harry Neale is an analyst for CBC's Hockey Night in Canada broadcasts.\n"+
      "He is an older guy with brown hair and wearing a black suit.  Harry was\n"+
      "coach of the Detroit Red Wings for a brief time during the mid 1980's.\n");
}
