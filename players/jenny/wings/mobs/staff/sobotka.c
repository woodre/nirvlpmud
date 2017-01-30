inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "al sobotka" ||  str == "al" || str == "sobotka" || str == "Al Sobotka"; } 

reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("Al Sobotka");
   set_race("human");
   set_gender("male");
   set_al(300+random(40));
   set_level(10);
   set_hp(150);
   set_wc(14);
   set_ac(8);
   add_money(430+random(40));
   set_short(BOLD+WHT+"Al Sobotka"+NORM);
   set_long(
      "Al Sobotka is the arena manager for Joe Louis Arena.  It is his job\n"+
      "to make sure the building is ready for hockey games.  Al is an average\n"+
      "size middle-aged man with dark brown hair, and wearing a red vinyl\n"+
      "Wings jacket.\n");
}
