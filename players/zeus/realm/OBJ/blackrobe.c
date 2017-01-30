/* 2005.08.12 Forbin 
// -changed from obj/armor.c to bfeq object to support 
//  modifying of Bloodfist guild attribute bonuses
// inherit "/obj/armor.c"; 
*/
inherit "/players/forbin/closed/bfeq.c";
#include "/players/zeus/closed/all.h"

reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("robe");
   set_short(BOLD+BLK+"A long black robe"+NORM);
  set_long(
"A long black robe once worn by the monk Tyborlek.  The robe\n"+
"is made of cloth, and very finely woven.  A strange magical aura\n"+
"radiates forth from the robe, consuming whoever wears it.\n");
  set_type("chest");
  set_ac(1);
  set_weight(1);
  set_value(666+random(333));
  set_bf_guild_bonus(0, 10);
  set_bf_guild_bonus(4, 15);
}
