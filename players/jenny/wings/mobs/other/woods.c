inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "paul woods" ||  str == "paul" || str == "woods" || str == "Paul Woods"; } 

reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("Paul Woods");
   set_race("human");
   set_gender("male");
   set_al(150+random(100));
   set_level(13);
   set_hp(200);
   set_wc(16);
   set_ac(11);
   add_money(500+random(200));
   set_short(BOLD+WHT+"Paul Woods"+NORM);
   set_long(
      "Paul Woods is the analyst for Detroit Red Wing radio broadcasts.  He\n"+
      "is a middle-aged man with short brown hair and wearing a black suit.\n"+
      "Paul is a former NHL player.\n");
}
