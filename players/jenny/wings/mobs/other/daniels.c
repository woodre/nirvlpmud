inherit "/obj/monster";
#include "/players/jenny/define.h"
int num;
id(str) { return str == "ken daniels" ||  str == "ken" || str == "daniels" || str == "Ken Daniels"; } 

reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("Ken Daniels");
   set_race("human");
   set_gender("male");
   set_al(100+random(100));
   set_level(12);
   set_hp(180);
   set_wc(16);
   set_ac(9);
   add_money(500+random(100));
   set_short(BOLD+WHT+"Ken Daniels"+NORM);
   set_long(
      "Ken Daniels is the play by play man for local Red Wings telecasts.\n"+
      "He is a middle aged man with short dark hair, and dressed in a blue\n"+
      "suit.\n");
}
