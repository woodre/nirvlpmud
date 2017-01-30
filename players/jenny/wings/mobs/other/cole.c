inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "bob cole" ||  str == "bob" || str == "cole" || str == "Bob Cole"; } 

reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("Bob Cole");
   set_race("human");
   set_gender("male");
   set_al(100+random(20));
   set_level(9);
   set_hp(135);
   set_wc(13);
   set_ac(7);
   add_money(380+random(40));
   set_short(BOLD+WHT+"Bob Cole"+NORM);
   set_long(
      "Bob Cole is the play-by-play man for CBC's Hockey Night in Canada\n"+
      "broadcasts.  He is an older guy, almost completely bald, and wearing\n"+
      "a black suit.\n");
}
