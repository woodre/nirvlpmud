/*
Found near the Myrmidar Queen in the Jal-Hab.
Very difficult to obtain, as you have to kill
a dozen myrmidar as well as the queen to get it.
*/
#include "defs.h"

/*  2005.08.12 Forbin
//    -changed from obj/armor.c to bf eq inherit to permit modifying
//     of Bloodfist guild stats
//  inherit "/obj/armor.c";
*/

inherit "/players/forbin/closed/bfeq.c";

void reset(int arg) {
  if(arg) return;
  ::reset(arg);
  set_name("symbol");
  set_alias("holy symbol");
  set_short(HIB+"Holy Symbol of "+HIY+"Tre"+HIB+"los"+NORM);
  set_long(
    "This is the holy symbol of Trelos, patron god of seekers of truth\n"+
    "and defenders of the weak.  It glows with a magical aura.\n"
  );
  set_type("misc");
  set_ac(2);
  set_weight(1);
  set_value(2500);
  set_bf_guild_bonus(1, 5);
  set_bf_guild_bonus(3, 5);
  set_bf_guild_bonus(5, 10);
}

int do_special(object owner) {
  object nmy;
  if(!owner)
    return 0;
  if(!worn)
    return 0;
  if(!(nmy = (object)owner->query_attack()))
    return 0;
  if(owner->query_alignment() > 300 && nmy->query_alignment() < 0) {
    if(!random(20)) {
      tell_object(owner, HIB+"You are blessed by the Guardian.\n"+NORM);
      owner->add_hit_point(1+random(5));
    }
    if(!random(12)) {
      tell_object(owner, HIY+"You are enveloped in a protective glow.\n"+NORM);
      return 5;
    }
  }
}
