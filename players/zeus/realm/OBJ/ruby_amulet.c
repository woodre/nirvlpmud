/* 2005.08.12 Forbin 
// -changed from obj/armor.c to bfeq object to support 
//  modifying of Bloodfist guild attribute bonuses
// inherit "/obj/armor.c"; 
*/
inherit "/players/forbin/closed/bfeq.c";
#include "/players/zeus/closed/all.h"

reset(arg){
  if(arg) return;
  ::reset(arg);
  set_name("ruby amulet");
   set_short("A "+RED+"ruby"+NORM+" amulet");
  set_long(
"The red ruby on this amulet is amazingly beautiful.  It is slightly\n"+
"warm, as though it has magical properties to it.  It is tied to a\n"+
"simple string.  The amulet feels incredibly light in your hand.\n");
  set_type("amulet");
  set_ac(2);
  set_weight(0);  /* this is weightless for a reason, so don't change it w/o talking to Zeus first please  */
  set_value(2000);
  set_bf_guild_bonus(3, 5);
  set_bf_guild_bonus(5, 5);
}

id(str){ return str == "amulet" || str == "ruby amulet"; }
