/* Changed weight and ac from 1 to 2. Should be a nice item. -Snow */
/* 2005.08.12 Forbin 
// -changed from obj/armor.c to bfeq object to support 
//  modifying of Bloodfist guild attribute bonuses
// inherit "/obj/armor.c"; 
*/
inherit "/players/forbin/closed/bfeq.c";
/* 2005.06.11 Forbin -added color to short */
#include "/players/forbin/ansi.h"
reset(arg){
  if(arg) return;
  ::reset(arg);
set_name("shield of gondor");
set_ac(2);
set_weight(2);
set_type("shield");
set_alias("shield");
set_arm_light(1);
set_short("A "+HIW+"Silver"+NORM+" and "+HIK+"Black"+NORM+" Shield");
set_long("A Silver Shield with Black Decore...\n"+
       "It has a White Tree Painted on The Front...\n"+
       "It seems like it May have come from Gondor...\n");
set_value(1000);
  set_bf_guild_bonus(0, -10); 
set_bf_guild_bonus(2, 10); 
set_bf_guild_bonus(5, 10);
}
