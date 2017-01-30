#include "defs.h"

/* 2005.08.12 Forbin 
// -changed from obj/armor.c to bfeq object to support 
//  modifying of Bloodfist guild attribute bonuses
// inherit "/obj/armor.c"; 
*/
inherit "/players/forbin/closed/bfeq.c";

void reset(int arg) {
  if(arg) return;
  ::reset(arg);
  set_name("mail");
  set_alias("platemail");
  set_short("Dwarven platemail");
  set_long(
"This is a magnificent piece of workmanship, a genuine suit\n"+
"of dwarven platemail.  Only a dozen suits of this type are\n"+
"manufactured each year in the great underground halls of\n"+
"dwarvenkind, so few are the dwarven metalworkers capable of\n"+
"producing such fine workmanship.  The suit is trimmed in\n"+
"silver, with a golden dragon in flight on the chestplate.\n"
  );
  set_ac(4);
  set_type("armor");
  set_weight(9);
  set_value(12000);
  set_bf_guild_bonus(0, -10);
  set_bf_guild_bonus(1, 10);
}
