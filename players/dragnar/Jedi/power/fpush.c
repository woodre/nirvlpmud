#include "defs.h"

#define DAM random(SKILL+25)
#define COST 15

inherit CMDBASE;

status main(string str) {
  object ob;

  if(USER->query_ghost()) return 0;
  skill_type = "telekinesis";
  if( skill_check(5) ) return 1;
  ob = start_attack(str);
  if( !ob ) return 1;
  if(cp_check(15)) return 1;
  if(delay_check()) return 1;

  this_player()->spell_object(ob, "push", DAM, 0, "");
  write("You point toward "+NAME(ob)+" and push them to the ground.\n");
  say(NAME(this_player())+" points toward "+NAME(ob)+" and "+ob->query_pronoun()+" falls to the ground.\n");
  PO->adj_cp(-COST);
  PO->set_force_delay(1);
  return 1;
}
