inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "jim nill" ||  str == "jim" || str == "nill" || str == "Jim Nill"; } 

reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("Jim Nill");
   set_race("human");
   set_gender("male");
   set_al(150+random(50));
   set_level(14);
   set_hp(200);
   set_wc(19);
   set_ac(11);
   add_money(600+random(300));
   set_short(BOLD+WHT+"Jim Nill"+NORM);
   set_long(
      "Jim Nill is the Assistant General Manager of the Detroit Red Wings.\n"+
      "He is an averaged sized middled aged man with light brown hair and\n"+
      "a big, bushy mustache.  His job is to help the General Manager with\n"+
      "personnel decisions, contract negotiations, etc.  Jim is a former NHL\n"+
      "player, and is still in good shape.\n");
}
