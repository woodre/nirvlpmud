/* 2005.08.16 Zeus
// -changed from obj/armor.c to bfeq object to support
//  modifying of Bloodfist guild attribute bonuses
// inherit "/obj/armor.c";
*/
inherit "/players/forbin/closed/bfeq.c";
#include "/players/arrina/closed/ansi.h"

reset(arg){
  ::reset(arg);
   set_name("Shadowveil");
  set_short(HIW+"ShadowVeil"+NORM);
  set_alias("veil");
  set_long("Almost translucent, this veil appears to be\n"+
            "armor used by the mysterious Qurd mages.\n");
  set_type("armor");
  set_ac(5);
/* <ill> may 2005 */
  set_params("magical",5,0,0);
  set_weight(2);
  set_value(5000);
  set_bf_guild_bonus(0, 5);
  set_bf_guild_bonus(4, 5);
}

