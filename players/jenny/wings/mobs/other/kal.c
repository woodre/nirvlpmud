inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "ken kal" ||  str == "ken" || str == "kal" || str == "Ken Kal"; } 

reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("Ken Kal");
   set_race("human");
   set_gender("male");
   set_al(100+random(100));
   set_level(11);
   set_hp(165);
   set_wc(15);
   set_ac(9);
   add_money(400+random(200));
   set_short(BOLD+WHT+"Ken Kal"+NORM);
   set_long(
      "Ken Kal does the play by play for Detroit Red Wings radio broadcasts.\n"+
      "He is a balding middle-aged man with glasses and wearing a light brown suit.\n");
}
